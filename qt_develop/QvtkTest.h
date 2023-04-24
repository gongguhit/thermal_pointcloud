#pragma once

#include <pcl/common/common_headers.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/common/common.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <QtWidgets/QWidget>
#include "build/QvtkTest_autogen/include/ui_QvtkTest.h"
#include <QThread>
#include <QTimer>
#include "global.h"
#include <QDebug>

//external function
void thermal_rs_stream_thread(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &point_cloud_ptr);

class PcdvisThread:public QThread {
    Q_OBJECT
public:
    PcdvisThread(QObject* parent = nullptr) : QThread(parent) {}
    void run() override{
        thermal_rs_stream_thread(point_cloud_ptr);
    }
};

class QvtkTest : public QWidget {
  Q_OBJECT

 signals:
    void thermal_rs_signal(QString message1);
 public:
  QvtkTest(QWidget *parent = Q_NULLPTR);
//  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
//  pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr;
//  virtual void timerEvent(QTimerEvent *e);
 public slots:
  void thermal_rs_stream_close();
  // create new thread for press button
  void slotPushButtonPcd(){
      PcdvisThread* pcdvisthread = new PcdvisThread(this);
      pcdvisthread->start();
  }

 private slots:
  void updateOpenGLWidget(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer,pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr);

 protected:

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered;


 private:
  Ui::QvtkTestClass ui;
  void initialVtkWidget();
  QTimer *timer;
};


