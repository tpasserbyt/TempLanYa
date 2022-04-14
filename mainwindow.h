#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QBluetoothSocket>
#include <QMessageBox>
#include <QListWidgetItem>

 // 绘图
#include <QChartView>
#include <QChart>
#include <QLabel>
#include <Qtcharts/QScatterSeries>
#include <QtCharts/QLineSeries>
#include <QMediaPlayer>

QT_CHARTS_USE_NAMESPACE

//#include <QtBluetooth/qtbluetoothglobal.h>
#include <QtBluetooth/qbluetoothglobal.h>
#include <QtBluetooth/qbluetoothlocaldevice.h>
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <qbluetoothsocket.h>

#include <QTextCodec>
#include <QDateTime>
#include <QTimer>//定时器
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //

    void saveDate(double data);

    void creatChart();
    QChartView *chartView;
    QChart *mainChart;
    QScatterSeries *dotSerices;
    //警戒线
    QLineSeries *alertlineSeries;
    //连接线
    QLineSeries* connectLineSeries;


    QLabel *currentTempLabel;

    QMediaPlayer *alertPlayer;

void blueStates();
private slots:
     void on_pushButton_openBLE_clicked();
     void on_pushButton_upDateBLE_clicked();
     void addBlueToothDevicesToList(const QBluetoothDeviceInfo &info);
     void findFinish();
     void connectBLE(QListWidgetItem *item);
     void connectOK();
     void connectNot();
     void readBluetoothDataEvent();

     void on_pushButton_forward_clicked();
     void on_pushButton_back_clicked();
     void on_pushButton_stop_clicked();
     void on_pushButton_lift_clicked();
     void on_pushButton_right_clicked();

     void on_pushButton_speedUp_clicked();
     void on_pushButton_slowDown_clicked();
     void on_pushButton_closeBLE_clicked();
     void on_pushButton_clearReceive_clicked();
     void on_pushButton_send_clicked();
     void on_btn_clear2_clicked();


     void on_pushButton_sendtest_clicked();

     void Open_File();

private:
    Ui::MainWindow *ui;

        QBluetoothDeviceDiscoveryAgent *discoveryAgent;//用来对周围蓝牙进行搜寻
        QBluetoothLocalDevice *localDevice;//对本地设备进行操作，比如进行设备的打开，设备的关闭等等
        QBluetoothSocket *socket;//就是用来进行蓝牙配对链接和数据传输的
        QTimer *timer;


        QString comStr;
};
#endif // MAINWINDOW_H
