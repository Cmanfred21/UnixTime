#include "unixtime.h"
#include <QDateTime>
#include <QDate>
#include <QString>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UnixTime    clock;
    clock.show();
    return a.exec();
}
