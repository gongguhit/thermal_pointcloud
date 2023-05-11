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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QvtkTestClass
{
public:
    QVTKOpenGLNativeWidget *openGLWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_pcd;
    QPushButton *pushButton_stop;
    QLabel *label_4;
    QSlider *horizontalSlider_thresh;
    QLCDNumber *lcdNumber_thresh;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *pushButton_py;

    void setupUi(QWidget *QvtkTestClass)
    {
        if (QvtkTestClass->objectName().isEmpty())
            QvtkTestClass->setObjectName(QString::fromUtf8("QvtkTestClass"));
        QvtkTestClass->resize(1297, 755);
        QFont font;
        font.setPointSize(13);
        QvtkTestClass->setFont(font);
        openGLWidget = new QVTKOpenGLNativeWidget(QvtkTestClass);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(500, 90, 751, 491));
        label = new QLabel(QvtkTestClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 80, 301, 211));
        QFont font1;
        font1.setPointSize(40);
        label->setFont(font1);
        label_2 = new QLabel(QvtkTestClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 320, 351, 21));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        label_2->setFont(font2);
        label_3 = new QLabel(QvtkTestClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 630, 1291, 121));
        pushButton_pcd = new QPushButton(QvtkTestClass);
        pushButton_pcd->setObjectName(QString::fromUtf8("pushButton_pcd"));
        pushButton_pcd->setGeometry(QRect(20, 580, 341, 31));
        pushButton_stop = new QPushButton(QvtkTestClass);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setGeometry(QRect(1120, 600, 121, 31));
        label_4 = new QLabel(QvtkTestClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(80, 460, 221, 17));
        QFont font3;
        font3.setPointSize(15);
        label_4->setFont(font3);
        horizontalSlider_thresh = new QSlider(QvtkTestClass);
        horizontalSlider_thresh->setObjectName(QString::fromUtf8("horizontalSlider_thresh"));
        horizontalSlider_thresh->setGeometry(QRect(10, 520, 311, 16));
        horizontalSlider_thresh->setOrientation(Qt::Horizontal);
        lcdNumber_thresh = new QLCDNumber(QvtkTestClass);
        lcdNumber_thresh->setObjectName(QString::fromUtf8("lcdNumber_thresh"));
        lcdNumber_thresh->setGeometry(QRect(340, 510, 61, 31));
        lcdNumber_thresh->setFrameShadow(QFrame::Plain);
        lcdNumber_thresh->setLineWidth(2);
        lcdNumber_thresh->setSmallDecimalPoint(false);
        lcdNumber_thresh->setDigitCount(4);
        comboBox = new QComboBox(QvtkTestClass);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(150, 20, 71, 25));
        label_5 = new QLabel(QvtkTestClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 20, 111, 17));
        pushButton_py = new QPushButton(QvtkTestClass);
        pushButton_py->setObjectName(QString::fromUtf8("pushButton_py"));
        pushButton_py->setGeometry(QRect(10, 384, 351, 31));

        retranslateUi(QvtkTestClass);
        QObject::connect(horizontalSlider_thresh, SIGNAL(sliderMoved(int)), lcdNumber_thresh, SLOT(display(int)));

        QMetaObject::connectSlotsByName(QvtkTestClass);
    } // setupUi

    void retranslateUi(QWidget *QvtkTestClass)
    {
        QvtkTestClass->setWindowTitle(QCoreApplication::translate("QvtkTestClass", "QvtkTest", nullptr));
        label->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p>Multi-modal</p><p>Perception</p><p>System</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("QvtkTestClass", "Fusion with multi-modal sensors", nullptr));
        label_3->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p><img src=\":/icons/icons/icon.jpg\"/></p></body></html>", nullptr));
        pushButton_pcd->setText(QCoreApplication::translate("QvtkTestClass", "Visualize", nullptr));
        pushButton_stop->setText(QCoreApplication::translate("QvtkTestClass", "Stop streaming", nullptr));
        label_4->setText(QCoreApplication::translate("QvtkTestClass", "Temperature threshold", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("QvtkTestClass", "Set 1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("QvtkTestClass", "Set 2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("QvtkTestClass", "Set 3", nullptr));

        label_5->setText(QCoreApplication::translate("QvtkTestClass", "Calib param set", nullptr));
        pushButton_py->setText(QCoreApplication::translate("QvtkTestClass", "Manually calibrate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QvtkTestClass: public Ui_QvtkTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVTKTEST_H
