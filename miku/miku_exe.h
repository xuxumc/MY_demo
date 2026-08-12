#ifndef MIKU_EXE_H
#define MIKU_EXE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class miku_EXE;
}
QT_END_NAMESPACE

class miku_EXE : public QMainWindow
{
    Q_OBJECT

public:
    explicit miku_EXE(QWidget *parent = nullptr);
    ~miku_EXE() override;

private:
    Ui::miku_EXE *ui;
    struct ectp{
        QString name;
        QString account;
        QString password;
        QString note;
    };
    ectp addP;
    void jianqie();
    QString savedHash;
    QString hashP(const QString& str);
    bool falst{true};//是否是初始密码
    bool eventFilter(QObject *obj, QEvent *event) override;
    void loadCustomIllust();
    void refreshModifyCombo();
    QJsonArray loadPasswords();
    void savePasswords(const QJsonArray &arr);
    bool show_hide{false};//显示/隐藏密码判断用于添加密码
    bool show_hide2{false};//显示/隐藏密码判断用于添加密码
    bool show_hide3{false};//显示/隐藏密码判断用于添加密码
    bool recoveryVerified{false};//找回密码是否已验证
    void refreshPasswordList();
    void showPasswordDetail(int row);

};
#endif // MIKU_EXE_H
