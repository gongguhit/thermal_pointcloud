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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
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

    void setupUi(QWidget *QvtkTestClass)
    {
        if (QvtkTestClass->objectName().isEmpty())
            QvtkTestClass->setObjectName(QString::fromUtf8("QvtkTestClass"));
        QvtkTestClass->resize(1297, 755);
        openGLWidget = new QVTKOpenGLNativeWidget(QvtkTestClass);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(500, 100, 751, 491));
        label = new QLabel(QvtkTestClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 150, 301, 211));
        QFont font;
        font.setPointSize(40);
        label->setFont(font);
        label_2 = new QLabel(QvtkTestClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 380, 351, 21));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        label_2->setFont(font1);
        label_3 = new QLabel(QvtkTestClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 630, 1291, 121));
        pushButton_pcd = new QPushButton(QvtkTestClass);
        pushButton_pcd->setObjectName(QString::fromUtf8("pushButton_pcd"));
        pushButton_pcd->setGeometry(QRect(880, 60, 161, 25));

        retranslateUi(QvtkTestClass);

        QMetaObject::connectSlotsByName(QvtkTestClass);
    } // setupUi

    void retranslateUi(QWidget *QvtkTestClass)
    {
        QvtkTestClass->setWindowTitle(QCoreApplication::translate("QvtkTestClass", "QvtkTest", nullptr));
        label->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p>Multi-modal</p><p>Perception</p><p>System</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("QvtkTestClass", "Fusion with multi-modal sensors", nullptr));
        label_3->setText(QCoreApplication::translate("QvtkTestClass", "<html><head/><body><p><img src=\":/icons/icons/icon.jpg\"/></p></body></html>", nullptr));
        pushButton_pcd->setText(QCoreApplication::translate("QvtkTestClass", "Thermal Point Cloud", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QvtkTestClass: public Ui_QvtkTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVTKTEST_H
