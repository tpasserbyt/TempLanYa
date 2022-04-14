#include "mainwindow.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    //解决Qt应用在Android手机中显示比例不对的问题，实现自适应高分辨率。

#if (QT_VERSION >= QT_VERSION_CHECK(5,9,0))
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
