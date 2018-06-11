#include "mainwindow.h"
#include <QApplication>
#include"win.h"
#include"health.h"
#include"player_hp.h"

MainWindow * w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w=new MainWindow();
    w->show();
    //MainWindow w;
    //w.show();


    return a.exec();
}
