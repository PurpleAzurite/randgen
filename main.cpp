#include "randgen.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RandGen w;
    w.show();
    return a.exec();
}
