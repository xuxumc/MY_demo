#include "miku_exe.h"
#include "ui_miku_exe.h"
#include <QPainter>
#include <QPainterPath>
#include <QSettings>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QEvent>
#include <QMouseEvent>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QStandardPaths>
#include <QDir>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

//HKEY_CURRENT_USER\Software\MikuProject\miku_exe
//删除此注册表文件夹（miku_exe）可恢复为初始密码


miku_EXE::miku_EXE(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::miku_EXE)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->stackedWidget->setCurrentIndex(0);
    ui->edit_add_password->setEchoMode(QLineEdit::Password);
    jianqie();
    // 立绘可点击换图
    ui->mikuIllust_main->installEventFilter(this);
    ui->mikuIllust_main->setCursor(Qt::PointingHandCursor);
    loadCustomIllust();

    // 卡片 hover + 点击
    ui->card_add->installEventFilter(this);
    ui->card_add->setCursor(Qt::PointingHandCursor);
    ui->card_view->installEventFilter(this);
    ui->card_view->setCursor(Qt::PointingHandCursor);
    ui->card_modify->installEventFilter(this);
    ui->card_modify->setCursor(Qt::PointingHandCursor);

    //数据更新
    QJsonArray arr1 = loadPasswords();
    ui->statCount->setText(QString::number(arr1.size()) + " 条");

    // === page_7 主界面样式 ===
    ui->page_7->setStyleSheet(R"(
    /* 页面背景透明，让绿色底透出 */
    #page_7 { background: transparent; }

    /* 所有 Label 透明背景 */
    QLabel { background: transparent; }

    /* 标题 */
    #mainTitle {
        color: #FFFFFF;
        font-size: 22pt;
        font-weight: bold;
    }
    #mainSubtitle {
        color: rgba(255, 255, 255, 0.6);
        font-size: 9pt;
    }

    /* 退出登录 — 幽灵描边风格 */
    #btn_logout {
        background: transparent;
        color: #FFFFFF;
        border: 2px solid rgba(255, 255, 255, 0.5);
        border-radius: 14px;
        font: bold 10pt "Microsoft YaHei";
        padding: 4px 16px;
    }
    #btn_logout:hover {
        background: #FFFFFF;
        color: #2A9D96;
        border: 2px solid #FFFFFF;
    }

    /* 卡片容器 — 白色圆角 */
    #card_add, #card_view, #card_modify {
        background: #FFFFFF;
        border-radius: 16px;
    }

    /* 卡片图标 */
    #icon_add, #icon_view, #icon_modify {
        color: #2A9D96;
        font-size: 24pt;
        font-weight: bold;
        background: transparent;
    }

    /* 卡片标题 */
    #title_add, #title_view, #title_modify {
        color: #333333;
        font-size: 13pt;
        font-weight: bold;
    }

    /* 卡片描述 */
    #desc_add, #desc_view, #desc_modify {
        color: #999999;
        font-size: 9pt;
    }

    /* 统计文字 */
    #statLabel {
        color: rgba(255, 255, 255, 0.7);
        font-size: 10pt;
    }
    #statCount {
        color: #FFFFFF;
        font-size: 12pt;
        font-weight: bold;
    }
)");

    // === page_3 致谢页卡片样式 ===
    ui->page_3->setStyleSheet(R"(
    #page_3 { background: transparent; }
    QLabel { background: transparent; }
    #frame_zhixie_1, #frame_zhixie_2, #frame_zhixie_3 {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // === page_8 添加密码页样式 ===
    ui->page_8->setStyleSheet(R"(
    #page_8 { background: transparent; }
    QLabel { background: transparent; }
    #card_add_form {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // === page_9 查看密码页样式 ===
    ui->page_9->setStyleSheet(R"(
    #page_9 { background: transparent; }
    QLabel { background: transparent; }
    #card_detail {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // === page_10 修改密码页样式 ===
    ui->page_10->setStyleSheet(R"(
    #page_10 { background: transparent; }
    QLabel { background: transparent; }

    #card_modify_form {
        background: #FFFFFF;
        border-radius: 16px;
    }

    /* 下拉框本体 */
    #combo_select {
        background: #FFFFFF;
        border: 2px solid #39C5BB;
        border-radius: 8px;
        padding: 6px 12px;
        color: #333333;
        font-size: 10pt;
    }
    #combo_select::drop-down {
        border: none;
        width: 30px;
    }

    /* 下拉列表 — 文字颜色 + hover高亮 */
    #combo_select QAbstractItemView {
        background: #FFFFFF;
        color: #333333;
        border: 1px solid #39C5BB;
        selection-background-color: #39C5BB;
        selection-color: #FFFFFF;
        outline: none;
    }
    )");


    // === page_11 修改登录密码页样式 ===
    ui->page_11->setStyleSheet(R"(
    #page_11 { background: transparent; }
    QLabel { background: transparent; }
    #card_changepwd_form {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // === page_13 密保设置页样式 ===
    ui->page_13->setStyleSheet(R"(
    #page_13 { background: transparent; }
    QLabel { background: transparent; }
    #card_security_form {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // === page_14 找回密码页样式 ===
    ui->page_14->setStyleSheet(R"(
    #page_14 { background: transparent; }
    QLabel { background: transparent; }
    #card_recovery_form {
        background: #FFFFFF;
        border-radius: 16px;
    }
    )");

    // 密保新密码框初始禁用，验证通过后才能输入
    ui->edit_recovery_newpwd->setEnabled(false);
    ui->edit_recovery_confirmpwd->setEnabled(false);
    ui->btn_recovery_confirm->setEnabled(false);


    //密码系统初始化
    QSettings settings("MikuProject", "miku_exe");
    if (!settings.contains("password_hash")) {
        // 首次运行，写入默认密码的哈希
        settings.setValue("password_hash", hashP("miku"));
        falst = false;
    }
    savedHash = settings.value("password_hash").toString();

    ui->morenmima_label->hide();
    if(!falst){ui->morenmima_label->show();}

//-----------------------------------------------------------------------------------------------------------
    connect(ui->zhixie,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(1);
    });
//-----------------------------------------------------------------------------------------------------------
    connect(ui->zhixie_fanhui_push,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(0);
    });
//-----------------------------------------------------------------------------------------------------------
    connect(ui->jinru,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btn_logout,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_changelogin,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(7);
    });

    connect(ui->btn_add_back,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_view_back,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_modify_back,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_changepwd_back,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->mima_quren,&QPushButton::clicked,
        this,[this]{
        QString mima =hashP(ui->mima_lineEdit->text());
        if(mima == savedHash){
            ui->stackedWidget->setCurrentIndex(3);
            ui->mima_lineEdit->clear();
        }
        else{QMessageBox::warning(this,"错误","密码错误!");}
    });

    connect(ui->mima_lineEdit,&QLineEdit::returnPressed,
        this,[this]{
            QString mima =hashP(ui->mima_lineEdit->text());
            if(mima == savedHash){
                ui->stackedWidget->setCurrentIndex(3);
                ui->mima_lineEdit->clear();
            }
            else{QMessageBox::warning(this,"错误","密码错误!");}
    });

    connect(ui->mima_fanhui,&QPushButton::clicked,
        this,[this]{
        ui->stackedWidget->setCurrentIndex(0);
    });

//-----------------------------------------------------------------------------------------------------------


    connect(ui->btn_add_save,&QPushButton::clicked,//基础保存
        this,[this]{
        addP.account = ui->edit_add_account->text();
        addP.name = ui->edit_add_name->text();
        addP.note = ui->edit_add_note->toPlainText();
        addP.password = ui->edit_add_password->text();
        if(addP.name.isEmpty()||addP.password.isEmpty()){
            QMessageBox::warning(this,"错误","不能为空");
            return ;
        }
        QJsonObject obj;
        obj["name"] = addP.name;
        obj["account"] = addP.account;
        obj["note"] = addP.note;
        obj["password"] = addP.password;
        QJsonArray arr = loadPasswords();
        arr.append(obj);
        savePasswords(arr);
        QMessageBox::information(this,"miku~","成功！");
        ui->edit_add_account->clear();
        ui->edit_add_name->clear();
        ui->edit_add_note->clear();
        ui->edit_add_password->clear();
        ui->statCount->setText(QString::number(arr.size()) + " 条");
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_add_showpwd,&QPushButton::clicked,//显示/隐藏密码
        this,[this]{
        if(show_hide){
            ui->edit_add_password->setEchoMode(QLineEdit::Password);
            show_hide = false;
        }
        else{
            ui->edit_add_password->setEchoMode(QLineEdit::Normal);
            show_hide = true;
        }
    });

    connect(ui->list_passwords, &QListWidget::currentRowChanged,
        this, [this](int row){
        showPasswordDetail(row);
    });

    connect(ui->edit_search, &QLineEdit::returnPressed,
        this, [this](){
        ui->list_passwords->clear();
        QString num = ui->edit_search->text();
        QJsonArray arr = loadPasswords();
        for (int i = 0; i < arr.size(); i++) {
            QJsonObject obj = arr[i].toObject();
            QString name = obj["name"].toString();
            if(name.contains(num)) {
                QListWidgetItem *item = new QListWidgetItem(name);  // 4. 创建 item
                item->setData(Qt::UserRole, i);                      // 5. 存真实索引
                ui->list_passwords->addItem(item);
            }
        }
    });

    connect(ui->list_passwords, &QListWidget::itemDoubleClicked,//删除密码
        this, [this](QListWidgetItem *item){
        auto y = QMessageBox::question(
            this,
            "确定？",
            "miku要吃掉你的密码",
            QMessageBox::Yes|QMessageBox::No
            );
        if(y == QMessageBox::Yes){
            int realIndex = item->data(Qt::UserRole).toInt();

            QJsonArray arr = loadPasswords();
            arr.removeAt(realIndex);
            savePasswords(arr);

            refreshPasswordList();
            ui->statCount->setText(QString::number(arr.size()) + " 条");
        }

    });

    connect(ui->btn_modify_delete, &QPushButton::clicked,
        this, [this](){
        auto y = QMessageBox::question(
            this,
            "确定？",
            "miku要吃掉你的密码~",
            QMessageBox::Yes|QMessageBox::No
            );
        if(y == QMessageBox::Yes){
            int index = ui->combo_select->itemData(ui->combo_select->currentIndex(), Qt::UserRole).toInt();
            QJsonArray arr = loadPasswords();
            arr.removeAt(index);
            savePasswords(arr);
            refreshModifyCombo();
            ui->statCount->setText(QString::number(arr.size()) + " 条");
            ui->stackedWidget->setCurrentIndex(3);
        }
    });

    connect(ui->btn_modify_save, &QPushButton::clicked,
        this, [this]{
        QJsonObject obj;
        int index = ui->combo_select->itemData(ui->combo_select->currentIndex(), Qt::UserRole).toInt();
        obj["name"] = ui->edit_modify_name->text();
        obj["account"] = ui->edit_modify_account->text();
        obj["password"] = ui->edit_modify_password->text();
        obj["note"] = ui->edit_modify_note->toPlainText();
        QJsonArray arr = loadPasswords();
        arr[index] = obj;
        savePasswords(arr);
        QMessageBox::information(this, "miku~", "修改成功！");
        ui->edit_modify_name->clear();
        ui->edit_modify_account->clear();
        ui->edit_modify_password->clear();
        ui->edit_modify_note->clear();
        ui->stackedWidget->setCurrentIndex(3);
    });

    connect(ui->btn_modify_showpwd, &QPushButton::clicked,
        this, [this]{
        if(show_hide2){
            ui->edit_modify_password->setEchoMode(QLineEdit::Password);
            show_hide2 = false;
        }
        else{
            ui->edit_modify_password->setEchoMode(QLineEdit::Normal);
            show_hide2 = true;
        }
    });

//-----------------------------------------------------------------------------------------------------------

    connect(ui->btn_changepwd_confirm, &QPushButton::clicked,
        this, [this]{
        QString mima = ui->edit_old_pwd->text();
        QString mima_has = hashP(mima);
        if(mima_has == savedHash){
            QString mima_new , mima_new2;
            mima_new = ui->edit_new_pwd->text();
            mima_new2 = ui->edit_confirm_pwd->text();
            if(mima_new==mima_new2){
                QString mima_new_has = hashP(mima_new);
                savedHash = mima_new_has;
                QSettings settings("MikuProject", "miku_exe");
                settings.setValue("password_hash", savedHash);
                QMessageBox::information(this, "miku~", "密码修改成功！");
                ui->edit_old_pwd->clear();
                ui->edit_new_pwd->clear();
                ui->edit_confirm_pwd->clear();
                ui->stackedWidget->setCurrentIndex(3);
            }else{QMessageBox::warning(this,"错误","密码不一致");}
        }else{QMessageBox::warning(this,"错误","密码错误");}
    });


    connect(ui->btn_resetpwd_confirm, &QPushButton::clicked,
        this, [this]{
        QString mima = ui->edit_reset_current_pwd->text();
        mima = hashP(mima);
        if(mima == savedHash){
            auto y = QMessageBox::question(this,
                "确定？",
                "确定么?",
                QMessageBox::Yes|QMessageBox::No
            );
            if(y == QMessageBox::Yes){
                QSettings settings("MikuProject", "miku_exe");
                settings.setValue("password_hash", hashP("miku"));
                savedHash = settings.value("password_hash").toString();
                QMessageBox::information(this, "miku~", "密码修改成功！");
                ui->stackedWidget->setCurrentIndex(0);
            }else{ui->stackedWidget->setCurrentIndex(3);}
            ui->edit_reset_current_pwd->clear();
        }
    });

    connect(ui->btn_reset_showpwd, &QPushButton::clicked,
        this, [this]{
        if(show_hide3){
            ui->edit_reset_current_pwd->setEchoMode(QLineEdit::Password);
            show_hide3 = false;
        }
        else{
            ui->edit_reset_current_pwd->setEchoMode(QLineEdit::Normal);
            show_hide3 = true;
        }
    });

    connect(ui->btn_changelogin_chongzhi, &QPushButton::clicked,
        this, [this]{
        ui->stackedWidget->setCurrentIndex(8);
    });

    connect(ui->btn_resetpwd_back, &QPushButton::clicked,
        this, [this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

//-----------------------------------------------------------------------------------------------------------
    // === 密保找回系统 ===

    // 忘记密码 → 跳转找回密码页，并加载已设置的密保问题
    connect(ui->btn_forgot_pwd, &QPushButton::clicked,
        this, [this]{
        QSettings settings("MikuProject", "miku_exe");
        QString question = settings.value("security_question").toString();
        if (question.isEmpty()) {
            QMessageBox::warning(this, "提示", "你还没有设置密保问题，请先在主界面设置密保后再使用找回功能。");
            return;
        }
        ui->label_recovery_question->setText(question);
        // 重置状态
        recoveryVerified = false;
        ui->edit_recovery_answer->clear();
        ui->edit_recovery_newpwd->clear();
        ui->edit_recovery_confirmpwd->clear();
        ui->edit_recovery_newpwd->setEnabled(false);
        ui->edit_recovery_confirmpwd->setEnabled(false);
        ui->btn_recovery_confirm->setEnabled(false);
        ui->stackedWidget->setCurrentIndex(10);
    });

    // 主界面 → 设置密保页
    connect(ui->btn_security_setup, &QPushButton::clicked,
        this, [this]{
        // 如果已经设过密保，预填已有问题
        QSettings settings("MikuProject", "miku_exe");
        QString oldQ = settings.value("security_question").toString();
        if (!oldQ.isEmpty()) {
            int idx = ui->combo_security_question->findText(oldQ);
            if (idx >= 0) ui->combo_security_question->setCurrentIndex(idx);
        }
        ui->edit_security_answer->clear();
        ui->edit_security_confirm->clear();
        ui->stackedWidget->setCurrentIndex(9);
    });

    // 密保页 → 返回主界面
    connect(ui->btn_security_back, &QPushButton::clicked,
        this, [this]{
        ui->stackedWidget->setCurrentIndex(3);
    });

    // 找回密码页 → 返回登录页
    connect(ui->btn_recovery_back, &QPushButton::clicked,
        this, [this]{
        ui->stackedWidget->setCurrentIndex(2);
    });

    // 保存密保
    connect(ui->btn_security_save, &QPushButton::clicked,
        this, [this]{
        QString question = ui->combo_security_question->currentText();
        QString answer = ui->edit_security_answer->text().trimmed();
        QString confirm = ui->edit_security_confirm->text().trimmed();

        if (answer.isEmpty()) {
            QMessageBox::warning(this, "错误", "答案不能为空！");
            return;
        }
        if (answer != confirm) {
            QMessageBox::warning(this, "错误", "两次输入的答案不一致！");
            return;
        }

        QSettings settings("MikuProject", "miku_exe");
        settings.setValue("security_question", question);
        settings.setValue("security_answer_hash", hashP(answer.toLower()));

        QMessageBox::information(this, "miku~", "密保设置成功！\n请牢记你的答案，忘记密码时可以用它找回。");
        ui->edit_security_answer->clear();
        ui->edit_security_confirm->clear();
        ui->stackedWidget->setCurrentIndex(3);
    });

    // 验证密保答案
    connect(ui->btn_recovery_verify, &QPushButton::clicked,
        this, [this]{
        QSettings settings("MikuProject", "miku_exe");
        QString storedHash = settings.value("security_answer_hash").toString();
        QString input = ui->edit_recovery_answer->text().trimmed().toLower();

        if (input.isEmpty()) {
            QMessageBox::warning(this, "错误", "请输入答案！");
            return;
        }
        if (hashP(input) == storedHash) {
            recoveryVerified = true;
            ui->edit_recovery_newpwd->setEnabled(true);
            ui->edit_recovery_confirmpwd->setEnabled(true);
            ui->btn_recovery_confirm->setEnabled(true);
            ui->edit_recovery_answer->setEnabled(false);
            ui->btn_recovery_verify->setEnabled(false);
            QMessageBox::information(this, "miku~", "验证成功！请设置新密码。");
            ui->edit_recovery_newpwd->setFocus();
        } else {
            QMessageBox::warning(this, "错误", "答案错误！");
        }
    });

    // 确认重置密码
    connect(ui->btn_recovery_confirm, &QPushButton::clicked,
        this, [this]{
        if (!recoveryVerified) {
            QMessageBox::warning(this, "错误", "请先验证密保答案！");
            return;
        }
        QString newPwd = ui->edit_recovery_newpwd->text();
        QString confirmPwd = ui->edit_recovery_confirmpwd->text();

        if (newPwd.isEmpty()) {
            QMessageBox::warning(this, "错误", "新密码不能为空！");
            return;
        }
        if (newPwd != confirmPwd) {
            QMessageBox::warning(this, "错误", "两次输入的密码不一致！");
            return;
        }

        savedHash = hashP(newPwd);
        QSettings settings("MikuProject", "miku_exe");
        settings.setValue("password_hash", savedHash);

        QMessageBox::information(this, "miku~", "密码重置成功！请用新密码登录。");

        // 重置页面状态
        recoveryVerified = false;
        ui->edit_recovery_answer->clear();
        ui->edit_recovery_newpwd->clear();
        ui->edit_recovery_confirmpwd->clear();
        ui->edit_recovery_answer->setEnabled(true);
        ui->btn_recovery_verify->setEnabled(true);
        ui->edit_recovery_newpwd->setEnabled(false);
        ui->edit_recovery_confirmpwd->setEnabled(false);
        ui->btn_recovery_confirm->setEnabled(false);

        ui->stackedWidget->setCurrentIndex(2);
    });

//-----------------------------------------------------------------------------------------------------------


    // === 动画系统 ===
    // 1. 页面切换淡入效果
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, [this](int){
        QWidget *page = ui->stackedWidget->currentWidget();
        QGraphicsOpacityEffect *effect = qobject_cast<QGraphicsOpacityEffect*>(page->graphicsEffect());
        if (!effect) {
            effect = new QGraphicsOpacityEffect(page);
            page->setGraphicsEffect(effect);
        }
        effect->setOpacity(0.0);
        auto *anim = new QPropertyAnimation(effect, "opacity");
        anim->setDuration(300);
        anim->setStartValue(0.0);
        anim->setEndValue(1.0);
        anim->setEasingCurve(QEasingCurve::OutCubic);
        anim->start(QPropertyAnimation::DeleteWhenStopped);
    });

    // 2. 音符浮动动画
    auto setupFloat = [](QWidget *w, int amplitude, int duration){
        auto *anim = new QPropertyAnimation(w, "pos");
        QPoint orig = w->pos();
        anim->setDuration(duration);
        anim->setLoopCount(-1);
        anim->setKeyValueAt(0, orig);
        anim->setKeyValueAt(0.5, QPoint(orig.x(), orig.y() - amplitude));
        anim->setKeyValueAt(1, orig);
        anim->setEasingCurve(QEasingCurve::InOutSine);
        anim->start();
    };

    // Page 0 notes
    setupFloat(ui->deco_note_1, 6, 3000);
    setupFloat(ui->deco_note_2, 4, 2200);
    setupFloat(ui->deco_note_3, 5, 2800);
    setupFloat(ui->deco_note_4, 3, 2000);
    // Page 3 notes
    setupFloat(ui->deco_note_zx1, 5, 2600);
    setupFloat(ui->deco_note_zx2, 4, 2400);
    setupFloat(ui->deco_note_zx3, 3, 1800);
    // Page 2 notes
    setupFloat(ui->deco_note_pwd1, 4, 2500);
    setupFloat(ui->deco_note_pwd2, 3, 2100);

}

miku_EXE::~miku_EXE()
{
    delete ui;
}

void miku_EXE::jianqie(){
    QPixmap avatar(":/new/prefix1/miku_peg_2.png");
    QPixmap roundAvatar(45, 45);
    roundAvatar.fill(Qt::transparent);
    QPainter painter(&roundAvatar);
    painter.setRenderHint(QPainter::Antialiasing);
    QPainterPath path;
    path.addEllipse(0, 0, 45, 45);
    painter.setClipPath(path);
    painter.drawPixmap(0, 0, 45, 45, avatar);
    painter.setPen(QPen(QColor("#FFFFFF"), 2));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(1, 1, 43, 43);
    painter.end();
    ui->mikuAvatar->setPixmap(roundAvatar);
}

QString miku_EXE::hashP(const QString& str)
{
    QByteArray hash = QCryptographicHash::hash(
        str.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool miku_EXE::eventFilter(QObject *obj, QEvent *event)
{
    // === 卡片 hover 效果 ===
    if (event->type() == QEvent::Enter) {
        QFrame *card = qobject_cast<QFrame*>(obj);
        if (card && (card == ui->card_add || card == ui->card_view || card == ui->card_modify)) {
            card->setStyleSheet("background: #F0FFFE; border: 2px solid #39C5BB; border-radius: 16px;");
            return true;
        }
    }
    if (event->type() == QEvent::Leave) {
        QFrame *card = qobject_cast<QFrame*>(obj);
        if (card && (card == ui->card_add || card == ui->card_view || card == ui->card_modify)) {
            card->setStyleSheet("background: #FFFFFF; border-radius: 16px;");
            return true;
        }
    }

    // === 卡片点击 ===
    if (event->type() == QEvent::MouseButtonPress) {
        if (obj == ui->card_add) {
            ui->stackedWidget->setCurrentIndex(4);
            return true;
        }
        if (obj == ui->card_view) {
            ui->list_passwords->clear();
            ui->label_detail_name->setText("-");
            ui->label_detail_account->setText("-");;
            ui->label_detail_password->setText("******");
            ui->label_detail_note->clear();
            refreshPasswordList();
            ui->stackedWidget->setCurrentIndex(5);
            return true;
        }
        if (obj == ui->card_modify) {
            refreshModifyCombo();
            ui->stackedWidget->setCurrentIndex(6);
            return true;
        }
    }

    // === 点击立绘 → 打开文件选择框 ===
    if (obj == ui->mikuIllust_main
        && event->type() == QEvent::MouseButtonPress)
    {
        QString filePath = QFileDialog::getOpenFileName(
            this,
            "选择立绘图片",
            "",
            "图片文件 (*.png *.jpg *.jpeg *.bmp)"
            );
        if (!filePath.isEmpty()) {
            QSettings settings("MikuProject", "miku_exe");
            settings.setValue("custom_illust_path", filePath);
            loadCustomIllust();
        }
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}

void miku_EXE::loadCustomIllust()
{
    QSettings settings("MikuProject", "miku_exe");
    QString path = settings.value("custom_illust_path").toString();

    if (!path.isEmpty() && QFile::exists(path)) {
        // 用户选过自定义图片 → 加载它
        ui->mikuIllust_main->setPixmap(QPixmap(path));
    } else {
        // 没选过 → 用默认资源图
        ui->mikuIllust_main->setPixmap(
            QPixmap(":/new/prefix1/miku_peg-removebg-preview.png")
            );
    }
}

QJsonArray miku_EXE::loadPasswords()
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile file(dir + "/passwords.json");
    if (!file.exists()) {
        return QJsonArray();
    }
    if (!file.open(QIODevice::ReadOnly)) {
        return QJsonArray();
    }
    QByteArray data = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    return doc.array();
}

void miku_EXE::savePasswords(const QJsonArray &arr)
{
    QString dir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir().mkpath(dir);
    QFile file(dir + "/passwords.json");
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }
    QJsonDocument doc(arr);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();
}


void miku_EXE::refreshPasswordList()
{
    ui->list_passwords->clear();
    QJsonArray arr = loadPasswords();
    for (int i = 0; i < arr.size(); i++) {        // 普通 for 拿索引
        QJsonObject obj = arr[i].toObject();
        QString name = obj["name"].toString();
        QListWidgetItem *item = new QListWidgetItem(name);  // 创建 item
        item->setData(Qt::UserRole, i);                      // 存真实索引
        ui->list_passwords->addItem(item);                   // 加进列表
    }
}


void miku_EXE::showPasswordDetail(int row)
{
    QListWidgetItem *item = ui->list_passwords->item(row);
    if (!item) return;

    int realIndex = item->data(Qt::UserRole).toInt();

    QJsonArray arr = loadPasswords();
    if (realIndex < 0 || realIndex >= arr.size()) return;

    QJsonObject obj = arr[realIndex].toObject();
    ui->label_detail_name->setText(obj["name"].toString());
    ui->label_detail_account->setText(obj["account"].toString());
    ui->label_detail_password->setText(obj["password"].toString());
    ui->label_detail_note->setText(obj["note"].toString());
}

void miku_EXE::refreshModifyCombo()
{
    ui->combo_select->clear();
    QJsonArray arr = loadPasswords();
    for (int i = 0; i < arr.size(); i++) {
        QJsonObject obj = arr[i].toObject();
        QString name = obj["name"].toString();
        ui->combo_select->addItem(name);
        ui->combo_select->setItemData(i, i, Qt::UserRole);
    }
}

