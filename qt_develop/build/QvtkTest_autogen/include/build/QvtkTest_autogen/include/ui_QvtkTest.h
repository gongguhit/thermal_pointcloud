/********************************************************************************
** Form generated from reading UI file 'QvtkTest.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QVTKTEST_H
#define UI_QVTKTEST_H

#include <QVTKOpenGLNativeWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QvtkTestClass
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_py;
    QLabel *label;
    QSlider *horizontalSlider_thresh;
    QLCDNumber *lcdNumber_thresh;
    QPushButton *pushButton_pcd;
    QPushButton *pushButton_stop;
    QVTKOpenGLNativeWidget *openGLWidget;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *pushButton_resetpsp;
    QPushButton *pushButton_up;
    QPushButton *pushButton_left;
    QPushButton *pushButton_right;
    QPushButton *pushButton_down;
    QPushButton *pushButton_zoomin;
    QPushButton *pushButton_zoomout;
    QLabel *label_6;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *QvtkTestClass)
    {
        if (QvtkTestClass->objectName().isEmpty())
            QvtkTestClass->setObjectName(QString::fromUtf8("QvtkTestClass"));
        QvtkTestClass->resize(1365, 781);
        QvtkTestClass->setMinimumSize(QSize(1365, 781));
        QFont font;
        font.setPointSize(13);
        QvtkTestClass->setFont(font);
        label_2 = new QLabel(QvtkTestClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 250, 411, 21));
        label_2->setMinimumSize(QSize(351, 21));
        label_2->setMaximumSize(QSize(450, 30));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_3 = new QLabel(QvtkTestClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 670, 1291, 121));
        label_3->setMinimumSize(QSize(1291, 121));
        label_3->setMaximumSize(QSize(1600, 200));
        label_4 = new QLabel(QvtkTestClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 300, 300, 17));
        label_4->setMinimumSize(QSize(221, 17));
        label_4->setMaximumSize(QSize(300, 30));
        QFont font2;
        font2.setPointSize(15);
        label_4->setFont(font2);
        pushButton_py = new QPushButton(QvtkTestClass);
        pushButton_py->setObjectName(QString::fromUtf8("pushButton_py"));
        pushButton_py->setGeometry(QRect(240, 10, 151, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_py->sizePolicy().hasHeightForWidth());
        pushButton_py->setSizePolicy(sizePolicy);
        pushButton_py->setMinimumSize(QSize(1, 31));
        pushButton_py->setMaximumSize(QSize(450, 45));
        label = new QLabel(QvtkTestClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 301, 211));
        label->setMinimumSize(QSize(301, 211));
        label->setMaximumSize(QSize(500, 300));
        QFont font3;
        font3.setPointSize(40);
        label->setFont(font3);
        horizontalSlider_thresh = new QSlider(QvtkTestClass);
        horizontalSlider_thresh->setObjectName(QString::fromUtf8("horizontalSlider_thresh"));
        horizontalSlider_thresh->setGeometry(QRect(10, 330, 311, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider_thresh->sizePolicy().hasHeightForWidth());
        horizontalSlider_thresh->setSizePolicy(sizePolicy1);
        horizontalSlider_thresh->setMinimumSize(QSize(311, 16));
        horizontalSlider_thresh->setMaximumSize(QSize(400, 28));
        horizontalSlider_thresh->setOrientation(Qt::Horizontal);
        lcdNumber_thresh = new QLCDNumber(QvtkTestClass);
        lcdNumber_thresh->setObjectName(QString::fromUtf8("lcdNumber_thresh"));
        lcdNumber_thresh->setGeometry(QRect(340, 320, 61, 31));
        sizePolicy1.setHeightForWidth(lcdNumber_thresh->sizePolicy().hasHeightForWidth());
        lcdNumber_thresh->setSizePolicy(sizePolicy1);
        lcdNumber_thresh->setMinimumSize(QSize(61, 31));
        lcdNumber_thresh->setMaximumSize(QSize(100, 45));
        lcdNumber_thresh->setFrameShadow(QFrame::Plain);
        lcdNumber_thresh->setLineWidth(2);
        lcdNumber_thresh->setSmallDecimalPoint(false);
        lcdNumber_thresh->setDigitCount(4);
        pushButton_pcd = new QPushButton(QvtkTestClass);
        pushButton_pcd->setObjectName(QString::fromUtf8("pushButton_pcd"));
        pushButton_pcd->setGeometry(QRect(10, 370, 381, 31));
        sizePolicy1.setHeightForWidth(pushButton_pcd->sizePolicy().hasHeightForWidth());
        pushButton_pcd->setSizePolicy(sizePolicy1);
        pushButton_pcd->setMinimumSize(QSize(341, 31));
        pushButton_pcd->setMaximumSize(QSize(450, 45));
        pushButton_stop = new QPushButton(QvtkTestClass);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(260, 500, 126, 31));
        sizePolicy1.setHeightForWidth(pushButton_stop->sizePolicy().hasHeightForWidth());
        pushButton_stop->setSizePolicy(sizePolicy1);
        pushButton_stop->setMinimumSize(QSize(121, 31));
        pushButton_stop->setMaximumSize(QSize(200, 45));
        openGLWidget = new QVTKOpenGLNativeWidget(QvtkTestClass);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(440, 40, 900, 600));
        openGLWidget->setMinimumSize(QSize(900, 600));
        openGLWidget->setMaximumSize(QSize(1800, 1200));
        comboBox = new QComboBox(QvtkTestClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 10, 71, 25));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(71, 25));
        comboBox->setMaximumSize(QSize(150, 35));
        label_5 = new QLabel(QvtkTestClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 10, 131, 17));
        label_5->setMinimumSize(QSize(131, 17));
        label_5->setMaximumSize(QSize(200, 30));
        pushButton_resetpsp = new QPushButton(QvtkTestClass);
        pushButton_resetpsp->setObjectName(QString::fromUtf8("pushButton_resetpsp"));
        pushButton_resetpsp->setGeometry(QRect(10, 500, 211, 31));
        pushButton_up = new QPushButton(QvtkTestClass);
        pushButton_up->setObjectName(QString::fromUtf8("pushButton_up"));
        pushButton_up->setGeometry(QRect(300, 410, 41, 31));
        pushButton_left = new QPushButton(QvtkTestClass);
        pushButton_left->setObjectName(QString::fromUtf8("pushButton_left"));
        pushButton_left->setGeometry(QRect(250, 440, 41, 31));
        pushButton_right = new QPushButton(QvtkTestClass);
        pushButton_right->setObjectName(QString::fromUtf8("pushButton_right"));
        pushButton_right->setGeometry(QRect(350, 440, 41, 31));
        pushButton_down = new QPushButton(QvtkTestClass);
        pushButton_down->setObjectName(QString::fromUtf8("pushButton_down"));
        pushButton_down->setGeometry(QRect(300, 470, 41, 25));
        pushButton_zoomin = new QPushButton(QvtkTestClass);
        pushButton_zoomin->setObjectName(QString::fromUtf8("pushButton_zoomin"));
        pushButton_zoomin->setGeometry(QRect(110, 410, 89, 31));
        pushButton_zoomout = new QPushButton(QvtkTestClass);
        pushButton_zoomout->setObjectName(QString::fromUtf8("pushButton_zoomout"));
        pushButton_zoomout->setGeometry(QRect(110, 460, 89, 31));
        label_6 = new QLabel(QvtkTestClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 420, 91, 61));
        textBrowser = new QTextBrowser(QvtkTestClass);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(30, 540, 331, 131));

        retranslateUi(QvtkTestClass);

        QMetaObject::connectSlotsByName(QvtkTestClass);
    } // setupUi

    void retranslateUi(QWidget *QvtkTestClass)
    {
        QvtkTestClass->setWindowTitle(QCoreApplication::translate("QvtkTestClass", "QvtkTest", nullptr));
        label_2->setText(QCoreApplication::translate("QvtkTestClass", "Fusion with multi-modal sensors", nullptr));
        label_3->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p><img src=\":/icons/icons/icon.jpg\"/></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("QvtkTestClass", "Temperature threshold", nullptr));
        pushButton_py->setText(QCoreApplication::translate("QvtkTestClass", "Manually calibrate", nullptr));
        label->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p>Multi-modal</p><p>Perception</p><p>System</p></body></html>", nullptr));
        pushButton_pcd->setText(QCoreApplication::translate("QvtkTestClass", "Visualize", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("QvtkTestClass", "Stop streaming", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("QvtkTestClass", "Set 1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("QvtkTestClass", "Set 2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("QvtkTestClass", "Set 3", nullptr));

        label_5->setText(QCoreApplication::translate("QvtkTestClass", "Calib param set", nullptr));
        pushButton_resetpsp->setText(QCoreApplication::translate("QvtkTestClass", "Reset Camera Perspective", nullptr));
        pushButton_up->setText(QCoreApplication::translate("QvtkTestClass", "up", nullptr));
        pushButton_left->setText(QCoreApplication::translate("QvtkTestClass", "left", nullptr));
        pushButton_right->setText(QCoreApplication::translate("QvtkTestClass", "right", nullptr));
        pushButton_down->setText(QCoreApplication::translate("QvtkTestClass", "down", nullptr));
        pushButton_zoomin->setText(QCoreApplication::translate("QvtkTestClass", "zoom in", nullptr));
        pushButton_zoomout->setText(QCoreApplication::translate("QvtkTestClass", "zoom out", nullptr));
        label_6->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p>Perspection</p><p>Control</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QvtkTestClass: public Ui_QvtkTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVTKTEST_H
