#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QListWidgetItem>

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
    void saveDiary();
    void loadDiaries();
    void showDiary(QListWidgetItem *item);
    bool Window_Hello = false; //检测是否通过验证
    void verifyWindowsHello(std::function<void(bool)> callback);
};
#endif // MAINWINDOW_H
