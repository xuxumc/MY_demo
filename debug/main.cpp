#include "debug.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("BugCollector");
    QApplication::setOrganizationName("BugCollector");

    BugCollector window;
    window.show();
    return app.exec();
}
