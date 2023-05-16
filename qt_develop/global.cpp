#include "global.h"

bool pcd_viewer_running = true; // 在源文件中定义全局变量 g_num 的值
boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer (new pcl::visualization::PCLVisualizer ("pclviewer"));
pcl::PointCloud<pcl::PointXYZRGB>::Ptr point_cloud_ptr (new pcl::PointCloud<pcl::PointXYZRGB>);
bool shouldStop = false;
cv::Mat thermal_uchar_cut = cv::Mat(cv::Size(280,340),CV_8UC3,cv::Scalar(0,0,0));
int thermal_u = 0;
int thermal_v = 0;
float temp_text = 0;

// default temperature threshold
float temp_threshold = 190;

