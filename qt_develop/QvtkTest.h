#pragma once

#include <pcl/common/common_headers.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/common/common.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkGenericOpenGLRenderWindow.h>

#include <QtWidgets/QWidget>
#include "build/QvtkTest_autogen/include/ui_QvtkTest.h"


class QvtkTest : public QWidget {
  Q_OBJECT

 signals:
    void thermal_rs_signal(QString message1);
 public:
  QvtkTest(QWidget *parent = Q_NULLPTR);
 public slots:
  void thermal_rs_stream(pcl::PointCloud<pcl::PointXYZRGB>::Ptr &point_cloud_ptr);
  void thermal_rs_stream_close();
 private slots:
  void updateOpenGLWidget(boost::shared_ptr<pcl::visualization::PCLVisualizer> &viewer,pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr);

 protected:
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr;
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered;
  bool pcd_viewer_running;

 private:
  Ui::QvtkTestClass ui;
  void initialVtkWidget();
};



