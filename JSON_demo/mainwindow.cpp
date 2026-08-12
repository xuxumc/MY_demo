#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "json.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    listWidget_add();
    connect(ui->pushButton,&QPushButton::clicked,
        this,[this]{

            QString text = ui ->lineEdit ->text();
            QString text2 = ui -> lineEdit_2 -> text();
            QString text3 = ui -> lineEdit_3 -> text();
            if(text.isEmpty()||text2.isEmpty()||text3.isEmpty()){
                QMessageBox::warning(this,"错误","不能为空!");
                return;
            }
            seve_json_text(text,text2,text3);
            if(!json_seve_(text)){seve_json_text(text,text2,text3);}
            else{
                QMessageBox::information(this,"成功","成功");
                ui->lineEdit->clear();
                ui->lineEdit_2->clear();
                ui->lineEdit_3->clear();
                listWidget_add();
            }
        }
    );

    connect(ui->listWidget,&QListWidget::itemDoubleClicked,
        this,[=](QListWidgetItem *item){
            auto q = QMessageBox::question(
            this,"确认？","确认删除",
            QMessageBox::Yes , QMessageBox::No
            );
            if(q == QMessageBox::No){return;}
            int row = ui->listWidget->row(item);
            delete ui->listWidget->takeItem(row);
            arr.removeAt(row);

            QJsonArray jsonArr;;
            QFile outin("测试.json");
            if(!outin.open(QIODevice::ReadWrite))
                return;
            QByteArray data=outin.readAll();
            QJsonDocument doc=QJsonDocument::fromJson(data);
            QJsonArray arr=doc.array();
            arr.removeAt(row);
            outin.resize(0);
            outin.write(
               QJsonDocument(arr).toJson()
            );
            outin.close();
            ui->listWidget_2->clear();
        }
        );

    connect(ui->listWidget,&QListWidget::itemClicked,
        this,[=](QListWidgetItem *item){
        int row =ui->listWidget->row(item);
        ui->listWidget_2->clear();
        QFile file("测试.json");

        if(!file.open(QIODevice::ReadOnly))
            return;

        QByteArray data=file.readAll();

        QJsonDocument doc =QJsonDocument::fromJson(data);

        QJsonArray arr=doc.array();

        QJsonObject obj_ = arr[row].toObject();

        ui->listWidget_2->addItem(obj_["测试"].toString());

        ui->listWidget_2->addItem(obj_["测试2"].toString());

        ui->listWidget_2->addItem(obj_["测试3"].toString());

        }
        );
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::json_seve_(QString text){
    QFile file("测试.json");
    if(!file.open(QIODevice::ReadOnly))
        return false;

    QByteArray data=file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray arr=doc.array();
    for(int i = 0 ; i < arr.size() ; i++){
        QJsonObject obj=arr[i].toObject();
        if(obj["测试"] == text){return true;}
    }

    return false;
}
void MainWindow::seve_json_text(QString text , QString text2 , QString text3){
    obj["测试"] = text;
    obj["测试2"] = text2;
    obj["测试3"] = text3;
    arr.append(obj);
    QJsonDocument doc(arr);
    QFile out("测试.json");
    if(out.open(QIODevice::WriteOnly)){
        out.write(doc.toJson());
        out.close();
    }
}
void MainWindow::listWidget_add(){
    ui->listWidget->clear();
    QFile file("测试.json");
    if(!file.open(QIODevice::ReadOnly))
        return;
    QByteArray data=file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray arr=doc.array();
    for(int i = 0 ; i < arr.size() ; i++){
        QJsonObject obj=arr[i].toObject();
        QString text = obj["测试"].toString();
        ui->listWidget->addItem(text);
    }
}