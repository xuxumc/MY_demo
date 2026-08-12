#include "debug.h"
#include "ui_debug.h"

#include <QAbstractAnimation>
#include <QDir>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsOpacityEffect>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QListWidgetItem>
#include <QPropertyAnimation>
#include <QStandardPaths>
#include <QStyle>
#include <QTimer>

namespace {
QString dataFilePath()
{
    const QString folder = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(folder);
    return folder + QDir::separator() + "bugs.json";
}

void addShadow(QWidget *widget)
{
    auto *shadow = new QGraphicsDropShadowEffect(widget);
    shadow->setBlurRadius(32);
    shadow->setOffset(0, 10);
    shadow->setColor(QColor(0, 0, 0, 75));
    widget->setGraphicsEffect(shadow);
}
}

BugCollector::BugCollector(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::BugCollector)
{
    ui->setupUi(this);
    setMinimumSize(920, 620);

    addShadow(ui->welcomeCard);
    addShadow(ui->side);
    addShadow(ui->editor);

    connect(ui->startBtn, &QPushButton::clicked, this, &BugCollector::showWorkspace);
    connect(ui->saveBtn, &QPushButton::clicked, this, &BugCollector::saveCurrentBug);
    connect(ui->newBtn, &QPushButton::clicked, this, [this] {
        ui->bugList->clearSelection();
        ui->bugName->clear();
        ui->bugType->setCurrentIndex(0);
        ui->bugCode->clear();
        ui->bugReason->clear();
        ui->bugName->setFocus();
    });
    connect(ui->backBtn, &QPushButton::clicked, this, [this] {
        ui->pages->setCurrentWidget(ui->welcomePage);
        startAnimation();
    });
    connect(ui->bugList, &QListWidget::currentRowChanged, this, &BugCollector::showBug);

    loadBugs();
    ui->pages->setCurrentWidget(ui->welcomePage);
    QTimer::singleShot(0, this, &BugCollector::startAnimation);

    connect(ui->shanchu, &QPushButton::clicked,
            this, [this]() {
                auto row = ui->bugList->currentRow();
                if(row<0||row>=bugs.size())return;
                bugs.removeAt(row);
                saveBugs();
                refreshBugList();
            });
}

BugCollector::~BugCollector()
{
    delete ui;
}

void BugCollector::startAnimation()
{
    animatePage(ui->welcomeCard, 650);
}

void BugCollector::showWorkspace()
{
    auto *fade = new QGraphicsOpacityEffect(ui->welcomePage);
    ui->welcomePage->setGraphicsEffect(fade);
    auto *out = new QPropertyAnimation(fade, "opacity", fade);
    out->setDuration(220);
    out->setStartValue(1.0);
    out->setEndValue(0.0);
    out->setEasingCurve(QEasingCurve::InCubic);
    connect(out, &QPropertyAnimation::finished, this, [this] {
        ui->welcomePage->setGraphicsEffect(nullptr);
        ui->pages->setCurrentWidget(ui->workspacePage);
        animatePage(ui->workspacePage, 480);
    });
    out->start(QAbstractAnimation::DeleteWhenStopped);
}

void BugCollector::animatePage(QWidget *page, int duration)
{
    // Only opacity is animated. Geometry remains owned by Qt layouts, so cards never overlap.
    auto *effect = new QGraphicsOpacityEffect(page);
    page->setGraphicsEffect(effect);
    auto *animation = new QPropertyAnimation(effect, "opacity", effect);
    animation->setDuration(duration);
    animation->setStartValue(0.0);
    animation->setEndValue(1.0);
    animation->setEasingCurve(QEasingCurve::OutCubic);
    connect(animation, &QPropertyAnimation::finished, page, [page] {
        // Defer effect removal until the animation has finished its own cleanup.
        QTimer::singleShot(0, page, [page] { page->setGraphicsEffect(nullptr); });
    });
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void BugCollector::saveCurrentBug()
{
    bug entry;

    entry.name = ui->bugName->text();
    entry.type = ui->bugType->currentText();
    entry.code = ui->bugCode->toPlainText();
    entry.reason = ui->bugReason->toPlainText();

    bugs.push_back(entry);

    saveBugs();

    refreshBugList();

    ui->bugName->clear();
    ui->bugCode->clear();
    ui->bugReason->clear();
}
void BugCollector::loadBugs()
{
    QFile file(dataFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
        refreshBugList();
        return;
    }

    const QJsonDocument document = QJsonDocument::fromJson(file.readAll());
    for (const QJsonValue &value : document.array()) {
        const QJsonObject object = value.toObject();
        bugs.push_back({object.value("name").toString(), object.value("type").toString(),
                        object.value("code").toString(), object.value("reason").toString()});
    }
    refreshBugList();
}

bool BugCollector::saveBugs() const
{
    QJsonArray array;
    for (const bug &entry : bugs) {
        QJsonObject object;
        object["name"] = entry.name;
        object["type"] = entry.type;
        object["code"] = entry.code;
        object["reason"] = entry.reason;
        array.append(object);
    }

    QFile file(dataFilePath());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return false;
    return file.write(QJsonDocument(array).toJson(QJsonDocument::Indented)) >= 0;
}

void BugCollector::refreshBugList()
{
    ui->bugList->blockSignals(true);
    ui->bugList->clear();
    for (const bug &entry : bugs) {
        auto *item = new QListWidgetItem(QString("  %1   %2").arg(entry.type, entry.name), ui->bugList);
        item->setToolTip(entry.reason);
        item->setSizeHint(QSize(0, 46));
    }
    ui->bugList->blockSignals(false);
    ui->emptyHint->setVisible(bugs.isEmpty());
    ui->countLabel->setText(QStringLiteral("%1 条记录").arg(bugs.size()));
}

void BugCollector::showBug(int index)
{
    if (index < 0 || index >= bugs.size())
        return;
    const bug &entry = bugs[index];
    ui->bugName->setText(entry.name);
    const int typeIndex = ui->bugType->findText(entry.type);
    ui->bugType->setCurrentIndex(qMax(0, typeIndex));
    ui->bugCode->setPlainText(entry.code);
    ui->bugReason->setPlainText(entry.reason);
    showStatus(QStringLiteral("正在编辑已有记录"), true);
}

void BugCollector::showStatus(const QString &text, bool success)
{
    ui->statusLabel->setText(text);
    ui->statusLabel->setProperty("success", success);
    ui->statusLabel->style()->unpolish(ui->statusLabel);
    ui->statusLabel->style()->polish(ui->statusLabel);
    animatePage(ui->statusLabel, 260);
}
