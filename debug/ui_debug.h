/********************************************************************************
** Form generated from reading UI file 'debug.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUG_H
#define UI_DEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BugCollector
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QStackedWidget *pages;
    QWidget *welcomePage;
    QVBoxLayout *welcomeOuter;
    QSpacerItem *welcomeTop;
    QHBoxLayout *welcomeRow;
    QSpacerItem *welcomeLeft;
    QFrame *welcomeCard;
    QVBoxLayout *welcomeCardLayout;
    QHBoxLayout *logoRow;
    QSpacerItem *logoLeft;
    QLabel *logoBadge;
    QSpacerItem *logoRight;
    QLabel *welcomeTitle;
    QLabel *welcomeSubtitle;
    QSpacerItem *welcomeGap;
    QPushButton *startBtn;
    QLabel *welcomeFoot;
    QSpacerItem *welcomeRight;
    QSpacerItem *welcomeBottom;
    QWidget *workspacePage;
    QVBoxLayout *workspaceOuter;
    QHBoxLayout *topBar;
    QLabel *brandLabel;
    QSpacerItem *topBarSpacer;
    QPushButton *backBtn;
    QHBoxLayout *contentLayout;
    QFrame *side;
    QVBoxLayout *sideLayout;
    QHBoxLayout *libraryHeader;
    QLabel *sectionTitle;
    QSpacerItem *librarySpacer;
    QLabel *countLabel;
    QPushButton *newBtn;
    QLabel *emptyHint;
    QListWidget *bugList;
    QFrame *editor;
    QVBoxLayout *editorLayout;
    QLabel *editorTitle;
    QLabel *editorSubtitle;
    QSpacerItem *editorGap;
    QHBoxLayout *basicFields;
    QVBoxLayout *nameField;
    QLabel *nameLabel;
    QLineEdit *bugName;
    QVBoxLayout *typeField;
    QLabel *typeLabel;
    QComboBox *bugType;
    QLabel *codeLabel;
    QPlainTextEdit *bugCode;
    QLabel *reasonLabel;
    QPlainTextEdit *bugReason;
    QHBoxLayout *actionRow;
    QLabel *statusLabel;
    QSpacerItem *actionSpacer;
    QPushButton *saveBtn;
    QPushButton *shanchu;

    void setupUi(QMainWindow *BugCollector)
    {
        if (BugCollector->objectName().isEmpty())
            BugCollector->setObjectName("BugCollector");
        BugCollector->resize(1180, 760);
        BugCollector->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow, QWidget#centralwidget { background: #0B1020; color: #EAF0FF; font-family: \"Microsoft YaHei UI\", \"Segoe UI\"; }\n"
"QWidget#welcomePage { background: qradialgradient(cx:0.5, cy:0.38, radius:0.8, fx:0.5, fy:0.38, stop:0 #172755, stop:0.45 #101936, stop:1 #090D19); }\n"
"QFrame#welcomeCard, QFrame#side, QFrame#editor { background: #151D31; border: 1px solid #263451; border-radius: 22px; }\n"
"QFrame#welcomeCard { background: rgba(21, 29, 49, 235); }\n"
"QLabel#logoBadge { background: #6C63FF; color: white; border-radius: 32px; font-size: 30px; font-weight: 700; }\n"
"QLabel#welcomeTitle { font-size: 34px; font-weight: 700; color: #F6F8FF; }\n"
"QLabel#welcomeSubtitle, QLabel#editorSubtitle, QLabel#countLabel, QLabel#emptyHint { color: #94A3C7; }\n"
"QLabel#brandLabel { font-size: 20px; font-weight: 700; color: #F3F6FF; }\n"
"QLabel#editorTitle { font-size: 24px; font-weight: 700; color: #F4F7FF; }\n"
"QLabel#sectionTitle { font-size: 15px; font-weight: 700; color: #DDE6FF; }\n"
"QLabel[field="
                        "\"true\"] { color: #AAB7D5; font-size: 12px; font-weight: 600; }\n"
"QPushButton { min-height: 40px; padding: 0 18px; border-radius: 10px; border: 1px solid #334364; background: #202B45; color: #EAF0FF; font-weight: 600; }\n"
"QPushButton:hover { background: #293858; border-color: #53698F; }\n"
"QPushButton:pressed { background: #1A243A; }\n"
"QPushButton#startBtn, QPushButton#saveBtn { background: #6C63FF; border: 1px solid #817AFF; color: white; }\n"
"QPushButton#startBtn:hover, QPushButton#saveBtn:hover { background: #7C74FF; }\n"
"QPushButton#startBtn { min-height: 48px; border-radius: 14px; font-size: 15px; }\n"
"QPushButton#backBtn { background: transparent; border: none; color: #9DABD0; padding: 0 8px; }\n"
"QLineEdit, QComboBox, QPlainTextEdit { background: #0E1527; border: 1px solid #2A3857; border-radius: 10px; color: #EDF2FF; selection-background-color: #6C63FF; padding: 9px 11px; }\n"
"QLineEdit:focus, QComboBox:focus, QPlainTextEdit:focus { border: 1px solid #746CFF; background: #111A30; }\n"
"QCo"
                        "mboBox { min-height: 22px; }\n"
"QComboBox::drop-down { border: none; width: 28px; }\n"
"QComboBox QAbstractItemView { background: #151D31; color: #EDF2FF; border: 1px solid #334364; selection-background-color: #6C63FF; }\n"
"QListWidget { background: transparent; border: none; outline: none; color: #DCE5FA; }\n"
"QListWidget::item { background: #10182B; border: 1px solid #263451; border-radius: 10px; margin: 3px 0; }\n"
"QListWidget::item:hover { background: #1B2742; border-color: #405174; }\n"
"QListWidget::item:selected { background: #292A57; border: 1px solid #6C63FF; color: white; }\n"
"QLabel#statusLabel { color: #F2A6A6; }\n"
"QLabel#statusLabel[success=\"true\"] { color: #6EE7B7; }\n"
"QScrollBar:vertical { background: transparent; width: 8px; margin: 2px; }\n"
"QScrollBar::handle:vertical { background: #344260; border-radius: 4px; min-height: 26px; }\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical { height: 0; }\n"
"  "));
        centralwidget = new QWidget(BugCollector);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setSpacing(0);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(0, 0, 0, 0);
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName("pages");
        welcomePage = new QWidget();
        welcomePage->setObjectName("welcomePage");
        welcomeOuter = new QVBoxLayout(welcomePage);
        welcomeOuter->setObjectName("welcomeOuter");
        welcomeOuter->setContentsMargins(28, 28, 28, 28);
        welcomeTop = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        welcomeOuter->addItem(welcomeTop);

        welcomeRow = new QHBoxLayout();
        welcomeRow->setObjectName("welcomeRow");
        welcomeLeft = new QSpacerItem(160, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        welcomeRow->addItem(welcomeLeft);

        welcomeCard = new QFrame(welcomePage);
        welcomeCard->setObjectName("welcomeCard");
        welcomeCard->setMinimumSize(QSize(500, 430));
        welcomeCard->setMaximumSize(QSize(620, 470));
        welcomeCardLayout = new QVBoxLayout(welcomeCard);
        welcomeCardLayout->setSpacing(18);
        welcomeCardLayout->setObjectName("welcomeCardLayout");
        welcomeCardLayout->setContentsMargins(58, 50, 58, 46);
        logoRow = new QHBoxLayout();
        logoRow->setObjectName("logoRow");
        logoLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        logoRow->addItem(logoLeft);

        logoBadge = new QLabel(welcomeCard);
        logoBadge->setObjectName("logoBadge");
        logoBadge->setMinimumSize(QSize(64, 64));
        logoBadge->setMaximumSize(QSize(64, 64));
        logoBadge->setAlignment(Qt::AlignmentFlag::AlignCenter);

        logoRow->addWidget(logoBadge);

        logoRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        logoRow->addItem(logoRight);


        welcomeCardLayout->addLayout(logoRow);

        welcomeTitle = new QLabel(welcomeCard);
        welcomeTitle->setObjectName("welcomeTitle");
        welcomeTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        welcomeCardLayout->addWidget(welcomeTitle);

        welcomeSubtitle = new QLabel(welcomeCard);
        welcomeSubtitle->setObjectName("welcomeSubtitle");
        welcomeSubtitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        welcomeCardLayout->addWidget(welcomeSubtitle);

        welcomeGap = new QSpacerItem(20, 22, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        welcomeCardLayout->addItem(welcomeGap);

        startBtn = new QPushButton(welcomeCard);
        startBtn->setObjectName("startBtn");
        startBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        welcomeCardLayout->addWidget(startBtn);

        welcomeFoot = new QLabel(welcomeCard);
        welcomeFoot->setObjectName("welcomeFoot");
        welcomeFoot->setStyleSheet(QString::fromUtf8("color:#647394; font-size:11px;"));
        welcomeFoot->setAlignment(Qt::AlignmentFlag::AlignCenter);

        welcomeCardLayout->addWidget(welcomeFoot);


        welcomeRow->addWidget(welcomeCard);

        welcomeRight = new QSpacerItem(160, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        welcomeRow->addItem(welcomeRight);


        welcomeOuter->addLayout(welcomeRow);

        welcomeBottom = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        welcomeOuter->addItem(welcomeBottom);

        pages->addWidget(welcomePage);
        workspacePage = new QWidget();
        workspacePage->setObjectName("workspacePage");
        workspaceOuter = new QVBoxLayout(workspacePage);
        workspaceOuter->setSpacing(18);
        workspaceOuter->setObjectName("workspaceOuter");
        workspaceOuter->setContentsMargins(30, 22, 30, 28);
        topBar = new QHBoxLayout();
        topBar->setObjectName("topBar");
        brandLabel = new QLabel(workspacePage);
        brandLabel->setObjectName("brandLabel");

        topBar->addWidget(brandLabel);

        topBarSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        topBar->addItem(topBarSpacer);

        backBtn = new QPushButton(workspacePage);
        backBtn->setObjectName("backBtn");
        backBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        topBar->addWidget(backBtn);


        workspaceOuter->addLayout(topBar);

        contentLayout = new QHBoxLayout();
        contentLayout->setSpacing(20);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        side = new QFrame(workspacePage);
        side->setObjectName("side");
        side->setMinimumSize(QSize(300, 0));
        side->setMaximumSize(QSize(360, 16777215));
        sideLayout = new QVBoxLayout(side);
        sideLayout->setSpacing(12);
        sideLayout->setObjectName("sideLayout");
        sideLayout->setContentsMargins(20, 22, 20, 20);
        libraryHeader = new QHBoxLayout();
        libraryHeader->setObjectName("libraryHeader");
        sectionTitle = new QLabel(side);
        sectionTitle->setObjectName("sectionTitle");

        libraryHeader->addWidget(sectionTitle);

        librarySpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        libraryHeader->addItem(librarySpacer);

        countLabel = new QLabel(side);
        countLabel->setObjectName("countLabel");

        libraryHeader->addWidget(countLabel);


        sideLayout->addLayout(libraryHeader);

        newBtn = new QPushButton(side);
        newBtn->setObjectName("newBtn");
        newBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        sideLayout->addWidget(newBtn);

        emptyHint = new QLabel(side);
        emptyHint->setObjectName("emptyHint");
        emptyHint->setAlignment(Qt::AlignmentFlag::AlignCenter);
        emptyHint->setWordWrap(true);

        sideLayout->addWidget(emptyHint);

        bugList = new QListWidget(side);
        bugList->setObjectName("bugList");

        sideLayout->addWidget(bugList);


        contentLayout->addWidget(side);

        editor = new QFrame(workspacePage);
        editor->setObjectName("editor");
        editorLayout = new QVBoxLayout(editor);
        editorLayout->setSpacing(12);
        editorLayout->setObjectName("editorLayout");
        editorLayout->setContentsMargins(28, 24, 28, 22);
        editorTitle = new QLabel(editor);
        editorTitle->setObjectName("editorTitle");

        editorLayout->addWidget(editorTitle);

        editorSubtitle = new QLabel(editor);
        editorSubtitle->setObjectName("editorSubtitle");

        editorLayout->addWidget(editorSubtitle);

        editorGap = new QSpacerItem(20, 8, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        editorLayout->addItem(editorGap);

        basicFields = new QHBoxLayout();
        basicFields->setSpacing(14);
        basicFields->setObjectName("basicFields");
        nameField = new QVBoxLayout();
        nameField->setObjectName("nameField");
        nameLabel = new QLabel(editor);
        nameLabel->setObjectName("nameLabel");
        nameLabel->setProperty("field", QVariant(true));

        nameField->addWidget(nameLabel);

        bugName = new QLineEdit(editor);
        bugName->setObjectName("bugName");

        nameField->addWidget(bugName);


        basicFields->addLayout(nameField);

        typeField = new QVBoxLayout();
        typeField->setObjectName("typeField");
        typeLabel = new QLabel(editor);
        typeLabel->setObjectName("typeLabel");
        typeLabel->setProperty("field", QVariant(true));

        typeField->addWidget(typeLabel);

        bugType = new QComboBox(editor);
        bugType->addItem(QString());
        bugType->addItem(QString());
        bugType->addItem(QString());
        bugType->addItem(QString());
        bugType->addItem(QString());
        bugType->addItem(QString());
        bugType->setObjectName("bugType");

        typeField->addWidget(bugType);


        basicFields->addLayout(typeField);


        editorLayout->addLayout(basicFields);

        codeLabel = new QLabel(editor);
        codeLabel->setObjectName("codeLabel");
        codeLabel->setProperty("field", QVariant(true));

        editorLayout->addWidget(codeLabel);

        bugCode = new QPlainTextEdit(editor);
        bugCode->setObjectName("bugCode");
        bugCode->setMinimumSize(QSize(0, 150));

        editorLayout->addWidget(bugCode);

        reasonLabel = new QLabel(editor);
        reasonLabel->setObjectName("reasonLabel");
        reasonLabel->setProperty("field", QVariant(true));

        editorLayout->addWidget(reasonLabel);

        bugReason = new QPlainTextEdit(editor);
        bugReason->setObjectName("bugReason");
        bugReason->setMinimumSize(QSize(0, 110));

        editorLayout->addWidget(bugReason);

        actionRow = new QHBoxLayout();
        actionRow->setObjectName("actionRow");
        statusLabel = new QLabel(editor);
        statusLabel->setObjectName("statusLabel");

        actionRow->addWidget(statusLabel);

        actionSpacer = new QSpacerItem(30, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        actionRow->addItem(actionSpacer);

        saveBtn = new QPushButton(editor);
        saveBtn->setObjectName("saveBtn");
        saveBtn->setMinimumSize(QSize(150, 42));
        saveBtn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        actionRow->addWidget(saveBtn);


        editorLayout->addLayout(actionRow);

        shanchu = new QPushButton(editor);
        shanchu->setObjectName("shanchu");

        editorLayout->addWidget(shanchu);


        contentLayout->addWidget(editor);


        workspaceOuter->addLayout(contentLayout);

        pages->addWidget(workspacePage);

        rootLayout->addWidget(pages);

        BugCollector->setCentralWidget(centralwidget);

        retranslateUi(BugCollector);

        pages->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BugCollector);
    } // setupUi

    void retranslateUi(QMainWindow *BugCollector)
    {
        BugCollector->setWindowTitle(QCoreApplication::translate("BugCollector", "BugCollector", nullptr));
        logoBadge->setText(QCoreApplication::translate("BugCollector", "\360\237\220\233", nullptr));
        welcomeTitle->setText(QCoreApplication::translate("BugCollector", "BugCollector", nullptr));
        welcomeSubtitle->setText(QCoreApplication::translate("BugCollector", "\346\212\212\346\257\217\344\270\200\346\254\241\351\224\231\350\257\257\357\274\214\345\217\230\346\210\220\344\270\213\344\270\200\346\254\241\350\277\233\346\255\245\347\232\204\347\272\277\347\264\242", nullptr));
        startBtn->setText(QCoreApplication::translate("BugCollector", "\345\274\200\345\247\213\346\225\264\347\220\206  \342\206\222", nullptr));
        welcomeFoot->setText(QCoreApplication::translate("BugCollector", "\350\256\260\345\275\225 \302\267 \345\210\206\346\236\220 \302\267 \345\244\215\347\233\230", nullptr));
        brandLabel->setText(QCoreApplication::translate("BugCollector", "\360\237\220\233  BugCollector", nullptr));
        backBtn->setText(QCoreApplication::translate("BugCollector", "\350\277\224\345\233\236\351\246\226\351\241\265", nullptr));
        sectionTitle->setText(QCoreApplication::translate("BugCollector", "Bug \350\265\204\346\226\231\345\272\223", nullptr));
        countLabel->setText(QCoreApplication::translate("BugCollector", "0 \346\235\241\350\256\260\345\275\225", nullptr));
        newBtn->setText(QCoreApplication::translate("BugCollector", "\357\274\213  \346\226\260\345\273\272\350\256\260\345\275\225", nullptr));
        emptyHint->setText(QCoreApplication::translate("BugCollector", "\350\277\230\346\262\241\346\234\211\350\256\260\345\275\225\357\274\214\345\210\233\345\273\272\347\254\254\344\270\200\345\217\252 Bug \345\220\247", nullptr));
        editorTitle->setText(QCoreApplication::translate("BugCollector", "\350\256\260\345\275\225\344\270\200\344\270\252 Bug", nullptr));
        editorSubtitle->setText(QCoreApplication::translate("BugCollector", "\344\277\235\347\225\231\347\216\260\345\234\272\357\274\214\344\271\237\345\206\231\344\270\213\344\275\240\346\234\200\347\273\210\346\211\276\345\210\260\347\232\204\345\216\237\345\233\240\343\200\202", nullptr));
        nameLabel->setText(QCoreApplication::translate("BugCollector", "BUG \345\220\215\347\247\260", nullptr));
        bugName->setPlaceholderText(QCoreApplication::translate("BugCollector", "\344\276\213\345\246\202\357\274\232\346\225\260\347\273\204\350\266\212\347\225\214\345\257\274\350\207\264\345\264\251\346\272\203", nullptr));
        typeLabel->setText(QCoreApplication::translate("BugCollector", "\351\224\231\350\257\257\347\261\273\345\236\213", nullptr));
        bugType->setItemText(0, QCoreApplication::translate("BugCollector", "RE", nullptr));
        bugType->setItemText(1, QCoreApplication::translate("BugCollector", "WA", nullptr));
        bugType->setItemText(2, QCoreApplication::translate("BugCollector", "TLE", nullptr));
        bugType->setItemText(3, QCoreApplication::translate("BugCollector", "MLE", nullptr));
        bugType->setItemText(4, QCoreApplication::translate("BugCollector", "CE", nullptr));
        bugType->setItemText(5, QCoreApplication::translate("BugCollector", "Other", nullptr));

        codeLabel->setText(QCoreApplication::translate("BugCollector", "\351\227\256\351\242\230\344\273\243\347\240\201 / \347\216\260\345\234\272", nullptr));
        bugCode->setPlaceholderText(QCoreApplication::translate("BugCollector", "\347\262\230\350\264\264\347\233\270\345\205\263\344\273\243\347\240\201\343\200\201\346\212\245\351\224\231\344\277\241\346\201\257\346\210\226\345\244\215\347\216\260\346\255\245\351\252\244\342\200\246", nullptr));
        reasonLabel->setText(QCoreApplication::translate("BugCollector", "\345\216\237\345\233\240\344\270\216\350\247\243\345\206\263\346\226\271\346\263\225", nullptr));
        bugReason->setPlaceholderText(QCoreApplication::translate("BugCollector", "\346\230\257\344\273\200\344\271\210\345\257\274\350\207\264\344\272\206\345\256\203\357\274\237\346\234\200\345\220\216\345\246\202\344\275\225\344\277\256\345\244\215\357\274\237", nullptr));
        statusLabel->setText(QCoreApplication::translate("BugCollector", "\345\206\205\345\256\271\344\274\232\344\277\235\345\255\230\345\234\250\346\234\254\346\234\272", nullptr));
        saveBtn->setText(QCoreApplication::translate("BugCollector", "\344\277\235\345\255\230\350\256\260\345\275\225", nullptr));
        shanchu->setText(QCoreApplication::translate("BugCollector", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BugCollector: public Ui_BugCollector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUG_H
