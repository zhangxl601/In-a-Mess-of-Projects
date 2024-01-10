#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


//#include<iostream>
//#include "plateManager.h"

//using namespace std;

//int main()
//{
//    plateManager manager;
//    manager.run();
//    return 0;
//}
