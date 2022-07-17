#include "selectmenu.h"
#include "database.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SelectMenu w;
    w.show();
    return a.exec();
}
