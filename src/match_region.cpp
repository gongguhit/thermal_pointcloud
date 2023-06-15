//
// Created by gg on 3/22/23.
//
#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <Eigen/Dense>

typedef pcl::PointCloud<pcl::PointXYZRGB>::Ptr PointCloudPtr;

// 定义点云配准函数
void registration(PointCloudPtr& cloud1, PointCloudPtr& cloud2, Eigen::Matrix4f& transform) {
    pcl::IterativeClosestPoint<pcl::PointXYZRGB, pcl::PointXYZRGB> icp;
    icp.setInputSource(cloud1);
    icp.setInputTarget(cloud2);
    PointCloudPtr cloud_result(new pcl::PointCloud<pcl::PointXYZRGB>);
    icp.align(*cloud_result);
    std::cout << "ICP score: " << icp.getFitnessScore() << std::endl;
    transform = icp.getFinalTransformation();
    cloud1 = cloud_result;
}

// 定义点云可视化函数
void visualize(PointCloudPtr& cloud1, PointCloudPtr& cloud2, Eigen::Matrix4f& transform) {
    pcl::visualization::PCLVisualizer viewer("Cloud Viewer");
    viewer.addPointCloud(cloud1, "cloud1");
    viewer.addPointCloud(cloud2, "cloud2");
    viewer.setBackgroundColor(0.0, 0.0, 0.0);
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud1");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "cloud2");
    viewer.addCoordinateSystem(1.0);
    viewer.initCameraParameters();
    
    // 将变换矩阵应用到 cloud2 上
    PointCloudPtr cloud2_transformed(new pcl::PointCloud<pcl::PointXYZRGB>);
    pcl::transformPointCloud(*cloud2, *cloud2_transformed, transform);
    viewer.addPointCloud(cloud2_transformed, "cloud2_transformed");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_COLOR, 0.0, 1.0, 0.0, "cloud2_transformed");
    
    // 显示窗口
    while (!viewer.wasStopped()) {
        viewer.spinOnce();
    }
}

int main() {
    // 读取十个点云文件
    std::vector<PointCloudPtr> clouds;
    for (int i = 1; i <= 10; i++) {
        std::string filename = "./savedpcd/cloud_" + std::to_string(i) + ".pcd";
        PointCloudPtr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
        pcl::io::loadPCDFile(filename, *cloud);
        std::cout << "Loaded cloud: " << filename << ", size: " << cloud->size() << std::endl;
        clouds.push_back(cloud);
    }
    
    // 逐一进行点云配准
    std::vector<Eigen::Matrix4f> transforms;
    for (int i = 0; i < clouds.size() - 1; i++) {
        Eigen::Matrix4f transform;
        registration(clouds[i], clouds[i+1], transform);
        transforms.push_back(transform);
    }
    
    // 将变换矩阵应用到每个点云上
    for (int i = 0; i < clouds.size() - 1; i++) {
        pcl::transformPointCloud(*clouds[i+1], *clouds[i+1], transforms[i]);
    }
    
    // 进行点云可视化
    visualize(clouds[0], clouds[9], transforms[8]);
    
    return 0;
}


