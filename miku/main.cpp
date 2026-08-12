#include "miku_exe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    miku_EXE w;
    w.show();
    return QCoreApplication::exec();
}
