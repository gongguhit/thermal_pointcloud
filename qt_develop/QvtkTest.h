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
#include <QMouseEvent>
#include <vtkPicker.h>

//external function
void thermal_rs_stream_thread(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &point_cloud_ptr,cv::Mat &thermal_uchar_cut);
void pointPick_callback(const pcl::visualization::PointPickingEvent& event, void* args);


// here for point cloud interaction
typedef pcl::PointXYZ PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::visualization::PCLVisualizer Visualizer;


class PcdvisThread:public QThread {
    Q_OBJECT
public:
    PcdvisThread(QObject* parent = nullptr) : QThread(parent) {}
    void run() override{
        while(!shouldStop){
        thermal_rs_stream_thread(point_cloud_ptr,thermal_uchar_cut);
        }
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
      if (pcdvis_thread != nullptr) {
          shouldStop = true;
          pcdvis_thread->quit();
          pcdvis_thread->wait();
          delete pcdvis_thread;
          qDebug() << "thermal_rs_thread terminated";
          pcdvis_thread = nullptr;
      }


  };
  // create new thread for press button
  void slotPushButtonPcd(){
      shouldStop = false;
      if (pcdvis_thread == nullptr){
          pcdvis_thread = new PcdvisThread();
          pcdvis_thread->start();
      }
//      PcdvisThread* pcdvisthread = new PcdvisThread(this);
//      pcdvisthread->start();
  }
  void on_runScriptButton_clicked();
  // Perspective control functions
  void on_resetCameraPerspective_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspup_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspdown_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspleft_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspright_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspzoomin_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void on_pspzoomout_clicked(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer);
  void lcdvis(int value);

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
  bool eventFilter(QObject *obj, QEvent *event);
  QTimer *timer;
  float temperature;
  PcdvisThread *pcdvis_thread;
  double cam_x, cam_y, cam_z, cam_view0, cam_view1, cam_view2,cam_up0,cam_up1,cam_up2;
  pcl::visualization::Camera camera;
};

