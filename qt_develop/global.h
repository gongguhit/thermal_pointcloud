// global.h
#ifndef GLOBAL_H
#define GLOBAL_H

#include <pcl/common/common_headers.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/common/common.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkGenericOpenGLRenderWindow.h>
#include <opencv2/core/core.hpp>

extern bool pcd_viewer_running; // 声明全局变量 g_num
extern boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
extern pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr;
extern float temp_threshold;
extern bool shouldStop;
extern cv::Mat thermal_uchar_cut;
extern int thermal_u;
extern int thermal_v;
extern float temp_text;


//pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr;



#endif // GLOBAL_H
