#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.set_LCD_AGL(400);
    w.set_LCD_ASL(1600);

    w.set_LCD_Pitch(-24);
    w.set_LCD_Roll_1(160);
    w.set_LCD_Roll_2(-20);
    QIcon icon("icon.png");
    w.setWindowIcon(icon);
    w.setWindowTitle(QObject::tr("Flying object"));
    w.show();

    return a.exec();
}
