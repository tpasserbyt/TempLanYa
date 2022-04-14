#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextEdit>
#include <QCheckBox>
#include <QFile>
#include <QDir>
#include <cstdlib>
#include "math.h"


//
#include <QtCharts/QValueAxis>
void MainWindow::creatChart()
{
    mainChart = new QChart();
    dotSerices = new QScatterSeries;
    alertlineSeries = new QLineSeries;
    connectLineSeries = new QLineSeries;

    QValueAxis *axisX = new QValueAxis;
    QValueAxis *axisY = new QValueAxis;

    axisX->setRange(0,60);
    axisX->setLabelFormat("%.2f");
    axisX->setGridLineVisible(true);
    axisX->setTickCount(7);
    axisX->setTitleText("时间");

    axisY->setRange(15,30);
    axisY->setLabelFormat("%.2f");
    axisY->setTickCount(8);
    axisY->setTitleText("温度");

    mainChart->addAxis(axisX,Qt::AlignBottom);
    mainChart->addAxis(axisY,Qt::AlignLeft);
    mainChart->addSeries(connectLineSeries);
    mainChart->addSeries(alertlineSeries);
    mainChart->addSeries(dotSerices);



    mainChart->legend()->hide();
    dotSerices->setMarkerSize(9);
    dotSerices->attachAxis(axisX);
    dotSerices->attachAxis(axisY);

    alertlineSeries->setPen(QPen(Qt::red,1,Qt::DashDotLine));
    alertlineSeries->attachAxis(axisX);
    alertlineSeries->attachAxis(axisY);
    connectLineSeries->attachAxis(axisX);
    connectLineSeries->attachAxis(axisY);

    alertlineSeries->append(0,26);
    alertlineSeries->append(60,26);

}

/*
 在蓝牙中，每个服务和服务属性都唯一地由"全球唯一标识符" （UUID）来校验。正如它的名字所暗示的，
每一个这样的标识符都要在时空上保证唯一。UUID类可表现为短整形（16或32位）和长整形（128位）UUID。
他提供了分别利用String和16位或32位数值来创建类的构造函数，提供了一个可以比较两个UUID（如果两个
都是128位）的方法，还有一个可以转换一个UUID为一个字符串的方法。UUID实例是不可改变的（immutable），
只有被UUID标示的服务可以被发现。在Linux下你用一个命令uuidgen -t可以生成一个UUID值；在Windows下
则执行命令uuidgen 。UUID看起来就像如下的这个形式：2d266186-01fb-47c2-8d9f-10b8ec891363。
当使用生成的UUID去创建一个UUID对象，你可以去掉连字符。

在我们的项目中，用到的模式是串口模式，我们需要建立一个存储Uuid的机制，如下：
static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
*/

static const QLatin1String serviceUuid("00001101-0000-1000-8000-00805F9B34FB");
/* 全局变量 方便控制端调用蓝牙连接成功后的socket发送数据 */
QBluetoothSocket *socket;
static int judge = 28 ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),currentTempLabel(new QLabel(this))
    , ui(new Ui::MainWindow)
{
    //ui->label_2->setPixmap(QPixmap(":/img/92.jpg"));
    //
    creatChart();
    chartView = new QChartView(this);
    chartView->setGeometry(5,340,401,331);
    chartView->setChart(mainChart);

    currentTempLabel->setGeometry(190,20,61,21);
    currentTempLabel->setText("当前温度");
    QFont f;
    f.setBold(true);
    f.setPointSize(10);
    currentTempLabel->setFont(f);
    currentTempLabel->setStyleSheet("color:red");

    alertPlayer = new QMediaPlayer;
   // qDebug()<<qApp->applicationDirPath();
   // alertPlayer->setMedia(QUrl::fromLocalFile(qApp->applicationDirPath()+ "/" + "alert.wav"));
    alertPlayer->setMedia(QUrl("qrc:/alert.wav"));

    ui->setupUi(this);
    discoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    timer = new QTimer();
    localDevice = new QBluetoothLocalDevice();
    //给socket分配内存，限定套接字协议
    socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
    //发现设备时会触发deviceDiscovered信号，转到槽显示蓝牙设备
    connect(discoveryAgent,SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)),this,SLOT(addBlueToothDevicesToList(QBluetoothDeviceInfo)));
    connect(discoveryAgent,SIGNAL(finished()),this,SLOT(findFinish()));
    //双击listwidget的项目，触发连接蓝牙的槽
    connect(ui->listWidget,SIGNAL(itemActivated(QListWidgetItem*)),this,SLOT(connectBLE(QListWidgetItem*)));
    //蓝牙连接设备成功后会停止搜索设备，显示连接成功
    connect(socket,SIGNAL(connected()),this,SLOT(connectOK()));
    //蓝牙连断开连接后，会显示已断开连接
    connect(socket,SIGNAL(disconnected()),this,SLOT(connectNot()));
    //接受到上位机传来的数据后显示，会触发接受数据函数

    connect(socket,SIGNAL(readyRead()),this,SLOT(readBluetoothDataEvent()));

    //清除查看长度窗口
    connect(ui->btn_lengthClear,&QPushButton::clicked,[=](){
        ui->Read_tohex->clear();
        ui->W_Max->clear();
    });

    //查看文件
    connect(ui->btn_check,&QPushButton::clicked,[=](){
        QString s = qApp->applicationDirPath()+ "/" + "数据.txt" ;

        QFile file(s);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        ui->Read_tohex->setText(array);
    });

    //打开文件测试
    connect(ui->open_file,&QPushButton::clicked,[=](){
        Open_File();
    });

    //关闭程序按钮
    connect(ui->quit,&QPushButton::clicked,[=](){
        QApplication::closeAllWindows();
    });

    // 修改温度临界值
    connect(ui->btn_setJudge,&QPushButton::clicked,[=](){
        QString get = ui->setJudge->toPlainText();
        judge = get.toInt();
        QMessageBox::information(this, tr("提示"), tr("临界值修改成功"));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
//打开蓝牙并查找蓝牙设备
void MainWindow::on_pushButton_openBLE_clicked()
{
    if( localDevice->hostMode() == QBluetoothLocalDevice::HostPoweredOff)//开机没有打开蓝牙
    {
        localDevice->powerOn();//调用打开本地的蓝牙设备
        discoveryAgent->start();//开始扫描蓝牙设备
    }
    else
    {
         QMessageBox::information(this, tr("成功"), tr("蓝牙已打开"));
    }

}
// 关闭 断开已连接的蓝牙设备 close设备和我们的open设备的方法在形式上不一样，只能用这样的方法对蓝牙进行关闭。
void MainWindow::on_pushButton_closeBLE_clicked()
{
    socket->close();
    QMessageBox::information(this, tr("成功"), tr("已断开连接"));

}
//刷新 重新查找蓝牙设备
void MainWindow::on_pushButton_upDateBLE_clicked()
{
    discoveryAgent->start();
    ui->listWidget->clear();
}
//在ListWidget上显示查找到的蓝牙设备
void MainWindow::addBlueToothDevicesToList(const QBluetoothDeviceInfo &info)
{
    QString label = QString("%1 %2").arg(info.address().toString()).arg(info.name());
    QList<QListWidgetItem *> items = ui->listWidget->findItems(label, Qt::MatchExactly);

    if (items.empty())
    {
        QListWidgetItem *item = new QListWidgetItem(label);
        QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(info.address());
        /* 蓝牙状态pairingStatus，Pairing枚举类型
         * 0:Unpaired没配对
         * 1:Paired配对但没授权
         * 2:AuthorizedPaired配对且授权 */
        if (pairingStatus == QBluetoothLocalDevice::Paired || pairingStatus == QBluetoothLocalDevice::AuthorizedPaired )
            item->setTextColor(QColor(Qt::red));
        else
            item->setTextColor(QColor(Qt::black));
        ui->listWidget->addItem(item);
    }
}
//刷新完成
void MainWindow::findFinish()
{
    ui->pushButton_upDateBLE->setEnabled(true);
    QMessageBox::information(this, tr("刷新"), tr("刷新完成!"));
}
//蓝牙连接
void MainWindow::connectBLE(QListWidgetItem *item)
{
    QString text = item->text();
    int index = text.indexOf(' ');
    if (index == -1)
        return;
    QBluetoothAddress address(text.left(index));
    QString name(text.mid(index + 1));
    QMessageBox::information(this,tr("提示"),tr("设备正在连接中..."));
    socket->connectToService(address, QBluetoothUuid(serviceUuid) ,QIODevice::ReadWrite);
}
//连接成功
void MainWindow::connectOK()
{
    discoveryAgent->stop();  //停止搜索设备
    QMessageBox::information(this, tr("成功"), tr("连接成功!"));
}
//连接失败
void MainWindow::connectNot()
{
    QMessageBox::information(this, tr("提示"), tr("已断开连接"));
}


//窗口显示串口传来的数据
static qreal passMinute = QTime::currentTime().minute();
void MainWindow::readBluetoothDataEvent()
{
    //这里数据需要自己做处理，不然发送接受不成功，提示：用定时器定时接受
    QByteArray line = socket->readAll();
    QString strData1 = QString::fromLocal8Bit(line);

    double strData = line.toDouble();
    // saveDate(strData);

    //double temp = strData.toDouble();
    double temp = strData;
    if(passMinute != QTime::currentTime().minute())
    {
        dotSerices->clear();
        connectLineSeries->clear();
        passMinute = QTime::currentTime().minute();
    }
    dotSerices->append(QTime::currentTime().second(),temp);
    connectLineSeries->append(QTime::currentTime().second(),temp);

    //
    QString strData2 = QString::number(temp,6,2);
    comStr.append(strData1);
    if(comStr.length() >= 4)
    {
//        bool isT = comStr[0] == 'T'||'t';
//        if(isT)
//        {
//            QString tyt;
//            for(int i=1;i<comStr.length();i++)
//            {
//               tyt = comStr[i];
//            }
//            ui->textBrowser_receive->append(tyt + "\n");

//        }else{
//             ui->textBrowser_receive->append(comStr + "\n");
//        }
        ui->textBrowser_receive->append(comStr + "\n");
        ui->btn_text2->setText(tr("温度： %1").arg(strData) + "\n");
        comStr.clear();
        strData = 0;

    }


    QString tt("当前温度：");
    tt +=QString("%1").arg(temp);
    currentTempLabel->setText(tt);

    if(temp > judge)
    {
        if(alertPlayer->state() == QMediaPlayer::PlayingState)
        {
            alertPlayer->stop();
        }
        alertPlayer->play();
    }

}

//蓝牙状态
void MainWindow::blueStates()
{
    if(socket == nullptr)
    QMessageBox::information(this, "错误", "蓝牙未连接");
}


void MainWindow::on_pushButton_clearReceive_clicked()
{
    ui->textBrowser_receive->clear();
}

void MainWindow::on_pushButton_send_clicked()
{
    QByteArray arrayData;
    QString s("temp:25\n");
    socket->write(s.toLocal8Bit());
}

void MainWindow::on_btn_clear2_clicked()
{
    ui->btn_text2->clear();
}



void MainWindow::on_pushButton_sendtest_clicked()
{

    blueStates();
    QString get1 = ui->Read_tohex->toPlainText();
    QString get2 = ui->W_Max->toPlainText();
    QString get = get1 + " " + get2;
    socket->write(get.toLocal8Bit() + "\n");


}

 void MainWindow::saveDate(double data)
 {
     //保存为TXT文件
     bool exist;
     QString fileName;

     QString path = qApp->applicationDirPath();

     QDir *folder = new QDir;
     exist = folder->exists(path);//查看目录是否存在

//     if(!exist){//不存在就创建
//         bool ok = folder->mkdir(path);
//         if(ok){
//             QMessageBox::warning(this,tr("创建目录"),tr("创建成功!"));//添加提示方便查看是否成功创建
//         }else{
//             QMessageBox::warning(this,tr("创建目录"),tr("创建失败"));
//         }
//     }
     fileName = path + "/" + "数据.txt";

     QFile f(fileName);
     if(!f.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)){//追加写入 添加结束符\r\n
         // QMessageBox::warning(this,tr("错误"),tr("打开文件失败,数据保存失败"));
         return ;
     }else{
         QString str = QString::number(data,'f',2);
         f.write(str.toUtf8());
         f.write(" ");
     }
     f.close();
 }

 //存储文件
 void MainWindow::Open_File()
 {
     QDateTime qtimeObj = QDateTime::currentDateTime();//获取时间
     QString alltext;
     //创建UIDdate文件夹
     QDir *folder = new QDir;
     bool exist = folder->exists("/storage/emulated/0/UIDdate");
     if(exist)
     {
         //QMessageBox::warning(this, tr("createDir"), tr("Dir is already existed!"));
     }
     else
     {
         //创建文件夹
         bool ok = folder->mkdir("/storage/emulated/0/UIDdate");
         if(ok)
             QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir success!"));
         else
             QMessageBox::warning(this, tr("CreateDir"), tr("Create Dir fail"));
     }
     //存储文件到UIDdate文件夹内
     QString fileName;
     fileName = tr("/storage/emulated/0/UIDdate/数据文件%1.txt").arg(qtimeObj.toString("yyyyMMddhhmmss"));

     QFile file(fileName);
     if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
     {
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败，数据保存失败"));
        return;
     }
     else
     {
        if(!file.isReadable())
        {
            QMessageBox::warning(this,tr("错误"),tr("该文件不可读，数据保存失败"));
        }
        else
        {

            QMessageBox::warning(this,tr("信息"),tr("信息存储成功！\n可在系统根目录文件'UIDdate'文件夹中查看！"));
        }
     }
     file.close();
 }

