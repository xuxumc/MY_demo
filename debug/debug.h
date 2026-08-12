#ifndef DEBUG_H
#define DEBUG_H

#include "bug.h"

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class BugCollector; }
QT_END_NAMESPACE

class QListWidgetItem;
class QWidget;

class BugCollector : public QMainWindow
{
    Q_OBJECT

public:
    explicit BugCollector(QWidget *parent = nullptr);
    ~BugCollector() override;

private:
    void startAnimation();
    void showWorkspace();
    void animatePage(QWidget *page, int duration = 420);
    void saveCurrentBug();
    void loadBugs();
    bool saveBugs() const;
    void refreshBugList();
    void showBug(int index);
    void showStatus(const QString &text, bool success);

    Ui::BugCollector *ui;
    QVector<bug> bugs;
};

#endif // DEBUG_H
