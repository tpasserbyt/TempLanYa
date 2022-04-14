/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *widget_7;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_openBLE;
    QPushButton *pushButton_closeBLE;
    QPushButton *pushButton_upDateBLE;
    QGroupBox *groupBox_2;
    QTextEdit *btn_text2;
    QPushButton *btn_setJudge;
    QPushButton *btn_clear2;
    QLabel *label;
    QLabel *label_3;
    QTextEdit *Read_tohex;
    QLabel *label_4;
    QTextEdit *W_Max;
    QPushButton *pushButton_sendtest;
    QPushButton *btn_lengthClear;
    QTextEdit *setJudge;
    QLabel *label_2;
    QPushButton *quit;
    QWidget *page_2;
    QWidget *widget;
    QTextBrowser *textBrowser_receive;
    QPushButton *pushButton_clearReceive;
    QPushButton *btn_check;
    QLabel *label_5;
    QPushButton *open_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(739, 754);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 441, 661));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget_7 = new QWidget(page);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setGeometry(QRect(-20, 0, 421, 681));
        widget_7->setStyleSheet(QString::fromUtf8(""));
        groupBox = new QGroupBox(widget_7);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 60, 371, 141));
        groupBox->setStyleSheet(QString::fromUtf8(""));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 22, 271, 109));
        listWidget->setStyleSheet(QString::fromUtf8("background-image: url(:/3.1.png);"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(290, 30, 77, 83));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_openBLE = new QPushButton(layoutWidget);
        pushButton_openBLE->setObjectName(QString::fromUtf8("pushButton_openBLE"));

        verticalLayout_3->addWidget(pushButton_openBLE);

        pushButton_closeBLE = new QPushButton(layoutWidget);
        pushButton_closeBLE->setObjectName(QString::fromUtf8("pushButton_closeBLE"));

        verticalLayout_3->addWidget(pushButton_closeBLE);

        pushButton_upDateBLE = new QPushButton(layoutWidget);
        pushButton_upDateBLE->setObjectName(QString::fromUtf8("pushButton_upDateBLE"));

        verticalLayout_3->addWidget(pushButton_upDateBLE);

        groupBox_2 = new QGroupBox(widget_7);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 210, 381, 111));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(170, 255, 255);"));
        btn_text2 = new QTextEdit(groupBox_2);
        btn_text2->setObjectName(QString::fromUtf8("btn_text2"));
        btn_text2->setGeometry(QRect(240, 30, 71, 31));
        btn_text2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        btn_setJudge = new QPushButton(groupBox_2);
        btn_setJudge->setObjectName(QString::fromUtf8("btn_setJudge"));
        btn_setJudge->setGeometry(QRect(320, 20, 31, 23));
        btn_clear2 = new QPushButton(groupBox_2);
        btn_clear2->setObjectName(QString::fromUtf8("btn_clear2"));
        btn_clear2->setGeometry(QRect(320, 60, 31, 41));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 10, 54, 12));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 51, 21));
        Read_tohex = new QTextEdit(groupBox_2);
        Read_tohex->setObjectName(QString::fromUtf8("Read_tohex"));
        Read_tohex->setGeometry(QRect(60, 30, 71, 21));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 70, 51, 21));
        W_Max = new QTextEdit(groupBox_2);
        W_Max->setObjectName(QString::fromUtf8("W_Max"));
        W_Max->setGeometry(QRect(60, 70, 71, 21));
        pushButton_sendtest = new QPushButton(groupBox_2);
        pushButton_sendtest->setObjectName(QString::fromUtf8("pushButton_sendtest"));
        pushButton_sendtest->setGeometry(QRect(140, 30, 51, 21));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_sendtest->sizePolicy().hasHeightForWidth());
        pushButton_sendtest->setSizePolicy(sizePolicy);
        btn_lengthClear = new QPushButton(groupBox_2);
        btn_lengthClear->setObjectName(QString::fromUtf8("btn_lengthClear"));
        btn_lengthClear->setGeometry(QRect(140, 70, 51, 21));
        setJudge = new QTextEdit(groupBox_2);
        setJudge->setObjectName(QString::fromUtf8("setJudge"));
        setJudge->setGeometry(QRect(240, 70, 71, 31));
        setJudge->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_2 = new QLabel(widget_7);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 20, 171, 16));
        quit = new QPushButton(widget_7);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(320, 20, 71, 21));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/3.1.png"), QSize(), QIcon::Normal, QIcon::Off);
        quit->setIcon(icon);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 670, 361, 81));
        widget->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:reflect, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(138, 155, 173, 255), stop:1 rgba(255, 255, 255, 255));"));
        textBrowser_receive = new QTextBrowser(widget);
        textBrowser_receive->setObjectName(QString::fromUtf8("textBrowser_receive"));
        textBrowser_receive->setGeometry(QRect(20, 20, 211, 61));
        textBrowser_receive->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 13pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        pushButton_clearReceive = new QPushButton(widget);
        pushButton_clearReceive->setObjectName(QString::fromUtf8("pushButton_clearReceive"));
        pushButton_clearReceive->setGeometry(QRect(240, 20, 61, 23));
        btn_check = new QPushButton(widget);
        btn_check->setObjectName(QString::fromUtf8("btn_check"));
        btn_check->setGeometry(QRect(240, 50, 61, 31));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 0, 54, 12));
        open_file = new QPushButton(widget);
        open_file->setObjectName(QString::fromUtf8("open_file"));
        open_file->setGeometry(QRect(310, 20, 41, 51));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\217\257\347\224\250\350\256\276\345\244\207", nullptr));
        pushButton_openBLE->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\350\223\235\347\211\231", nullptr));
        pushButton_closeBLE->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
        pushButton_upDateBLE->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\350\256\276\345\244\207", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        btn_setJudge->setText(QCoreApplication::translate("MainWindow", "\345\210\244", nullptr));
        btn_clear2->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\346\270\251\345\272\246", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\200\344\275\216\346\270\251\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\234\200\351\253\230\346\270\251\357\274\232", nullptr));
        pushButton_sendtest->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        btn_lengthClear->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\345\237\272\344\272\216QT+\345\215\225\347\211\207\346\234\272\347\232\204\346\270\251\345\272\246\347\233\221\346\216\247\347\263\273\347\273\237", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        pushButton_clearReceive->setText(QCoreApplication::translate("MainWindow", "\346\270\205\345\261\217", nullptr));
        btn_check->setText(QCoreApplication::translate("MainWindow", "\346\237\245\347\234\213", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\345\214\272", nullptr));
        open_file->setText(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
