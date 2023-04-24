#include "global.h"

bool pcd_viewer_running = true; // 在源文件中定义全局变量 g_num 的值
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("pclviewer"));
pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
