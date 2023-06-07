#include "Tests.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Tests w;
    //w.show();
    QTest::qExec(new Tests);
    return a.exec();
}
