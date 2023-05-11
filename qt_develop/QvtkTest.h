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
#include <QProcess>

//external function
void thermal_rs_stream_thread(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &point_cloud_ptr);

class PcdvisThread:public QThread {
    Q_OBJECT
public:
    PcdvisThread(QObject* parent = nullptr) : QThread(parent) {}
    void run() override{
        while(!shouldStop){
        thermal_rs_stream_thread(point_cloud_ptr);
        }
        qDebug() << "thermal_rs_thread terminated";
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
  void thermal_rs_stream_close(){
      pcd_viewer_running = false;
      shouldStop = true;

  };
  // create new thread for press button
  void slotPushButtonPcd(){
      shouldStop = false;
      PcdvisThread* pcdvisthread = new PcdvisThread(this);
      pcdvisthread->start();
  }
  void on_runScriptButton_clicked();

 private slots:
  void updateOpenGLWidget(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer,pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr);

 public Q_SLOTS:
  void tempsliderReleased();
  void tempSliderValueChanged(int value);
 protected:

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered;


 private:
  Ui::QvtkTestClass ui;
  void initialVtkWidget();
  QTimer *timer;
  int temperature;
};


