#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QListWidgetItem>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <windows.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Security.Credentials.UI.h>
#include <userconsentverifierinterop.h>
#include <windows.h>
#include <winrt/base.h>
#include <winrt/Windows.Security.Credentials.UI.h>
#include <userconsentverifierinterop.h>

#include <QMetaObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadDiaries();

    connect(ui->clearButton , &QPushButton::clicked,
        this,[this]{
        ui->contentEdit->clear();
        ui->titleEdit->clear();
    });

    connect(ui->saveButton , &QPushButton::clicked,
        this,[this]{
        saveDiary();
    });

    connect(ui->diaryListWidget, &QListWidget::itemClicked,
        this, [this](QListWidgetItem *item){
        if(!Window_Hello){
            verifyWindowsHello([this](bool ok)
            {
                if (ok){
                    loadDiaries();
                    Window_Hello = true;
                }else
                    QMessageBox::warning(this, "提示", "验证失败");
                });
        }else{
          showDiary(item);
        }

    });

}

void MainWindow::verifyWindowsHello(std::function<void(bool)> done)
{
    using namespace winrt;
    using namespace Windows::Foundation;
    using namespace Windows::Security::Credentials::UI;

    try
    {
        HWND hwnd = reinterpret_cast<HWND>(winId());

        auto interop =
            winrt::get_activation_factory<
                UserConsentVerifier,
                ::IUserConsentVerifierInterop>();

        winrt::hstring message = L"请验证身份以访问日记";

        auto operation =
            winrt::capture<
                IAsyncOperation<UserConsentVerificationResult>>(
                interop,
                &::IUserConsentVerifierInterop::RequestVerificationForWindowAsync,
                hwnd,
                reinterpret_cast<HSTRING>(winrt::get_abi(message))
                );

        operation.Completed([this, done](auto const& op, auto)
                            {
                                bool ok = false;

                                try
                                {
                                    ok = op.GetResults() ==
                                         UserConsentVerificationResult::Verified;
                                }
                                catch (...) {}

                                QMetaObject::invokeMethod(this, [done, ok]
                                                          {
                                                              done(ok);
                                                          });
                            });
    }
    catch (...)
    {
        done(false);
    }
}

void MainWindow::saveDiary()
{
    QString title = ui->titleEdit->text();
    QString content = ui->contentEdit->toPlainText();

    // 标题为空就不保存
    if (title.trimmed().isEmpty())
        return;

    QFile file("diary.json");

    QJsonArray diaries;

    // 先读取以前的数据
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray data = file.readAll();
        file.close();

        QJsonDocument oldDoc = QJsonDocument::fromJson(data);

        if (oldDoc.isObject())
        {
            QJsonObject root = oldDoc.object();
            diaries = root["diaries"].toArray();
        }
    }

    // 创建新日记
    QJsonObject diary;

    diary["title"] = title;
    diary["content"] = content;

    diaries.append(diary);

    // 根 JSON
    QJsonObject root;
    root["diaries"] = diaries;

    QJsonDocument doc(root);

    // 写回文件
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    }

    // 同时加入左边列表
    QListWidgetItem *item = new QListWidgetItem(title);

    // 把正文藏在 item 里面
    item->setData(Qt::UserRole, content);

    ui->diaryListWidget->addItem(item);

    ui->statusLabel->setText("日记已保存");
}

void MainWindow::loadDiaries()
{
    QFile file("diary.json");

    if (!file.open(QIODevice::ReadOnly))
        return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (!doc.isObject())
        return;

    QJsonObject root = doc.object();
    QJsonArray diaries = root["diaries"].toArray();

    ui->diaryListWidget->clear();

    for (const QJsonValue &value : diaries)
    {
        QJsonObject diary = value.toObject();

        QString title = diary["title"].toString();
        QString content = diary["content"].toString();

        QListWidgetItem *item = new QListWidgetItem(title);

        // 正文偷偷塞进这一行
        item->setData(Qt::UserRole, content);

        ui->diaryListWidget->addItem(item);
    }
}

void MainWindow::showDiary(QListWidgetItem *item)
{
    if (item == nullptr)
        return;

    QString title = item->text();
    QString content = item->data(Qt::UserRole).toString();

    // 创建窗口
    QDialog *dialog = new QDialog(this);

    dialog->setWindowTitle(title);
    dialog->resize(600, 450);

    // 布局
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    // 标题
    QLabel *titleLabel = new QLabel(title, dialog);

    QFont font = titleLabel->font();
    font.setPointSize(18);
    font.setBold(true);
    titleLabel->setFont(font);

    // 正文
    QTextEdit *contentEdit = new QTextEdit(dialog);
    contentEdit->setPlainText(content);
    contentEdit->setReadOnly(true);

    layout->addWidget(titleLabel);
    layout->addWidget(contentEdit);

    // 关闭窗口时自动释放
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    dialog->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
