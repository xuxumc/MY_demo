#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "json.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QJsonArray arr;
    QJsonObject obj;
    bool json_seve_(QString text);
    void seve_json_text(QString text, QString text2 ,QString text3);
    void listWidget_add();
};
#endif // MAINWINDOW_H
