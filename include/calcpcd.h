#ifndef FUSION_CALCPCD_H
#define FUSION_CALCPCD_H

#include "dependencies.h"
using namespace cv;
using namespace std;

// import calibration data
std::string dir_path = "../calib/";
// data name
std::string rgbIn = "boson_realsense_RGB_intrinsic";
std::string rgbDis = "boson_realsense_RGB_distortion";
std::string thermalIn = "boson_realsense_Thermal_intrinsic";
std::string thermalDis = "boson_realsense_Thermal_distortion";
std::string rel_R = "boson_realsense_Ralative_rotation_matrix";
std::string rel_T = "boson_realsense_Ralative_translation_matrix";

// function for generate scatters
template <typename T>
std::vector<T> range(T start, T end) {
    size_t N = (int)floor(end - start) + 1;
    std::vector<T> vec(N);
    std::iota(vec.begin(), vec.end(), start);
    return vec;
}
// readxml file of camera calibrating parameters
Mat readxml(std::string name){
    std::string path = dir_path + name + ".xml";
    cv::FileStorage file(path,cv::FileStorage::READ);
    if(!file.isOpened()){
        std::cout<<"Failed to open the xml file "<<path<<std::endl;
    }
    cv::Mat rst;
    file[name]>>rst;
    file.release();
    //std::cout << name << "is:" << rst << std::endl;
    return rst;
}
// 2D vector to cv::Mat
template<class T>
void vec2Mat(std::vector<std::vector<T>> const &myVec, Mat &myMat)
{
    int H = myVec.size();
    int W = myVec[0].size();
//std::cout<<"H is "<<H<<std::endl;
//std::cout<<"W is "<<W<<std::endl;

    for(int i=0; i<H; i++)
    {
        for(int j=0; j<W; j++)
        {
            myMat.at<T>(i,j) = myVec[i][j];
        }
    }

}
// function for change 3-channel Mat to point3f with fixed shape 307200
vector<Point3d> Mat2Point(Mat &src){
    vector<Point3d> dst;
    for (int i=0; i<307200; i++){
        Point3f p;
        //p.x = src.at<double>(0,i);
        p.x = (double)src.at<Vec3d>(i,0).val[0];
        //p.y = src.at<double>(1,i);
        p.y = (double)src.at<Vec3d>(i,0).val[1];
        //p.z = src.at<double>(2,i);
        p.z = (double)src.at<Vec3d>(i,0).val[2];
        dst.push_back(p);
    }
    return dst;
}
// function for change Point2d to Point2i with round, length = 307200
vector<Point2i> Pointf2i(vector<Point2d> &src){
    vector<Point2i> dst(src.size());
    for (int i=0; i<dst.size();i++){
//        Point2i p;
//        p.x = round(src[i].x);
//        p.y = round(src[i].y);
//        dst.push_back(p);
        dst[i].x = round(src[i].x);
        dst[i].y = round(src[i].y);
//        cout << "x= "<<dst[i].x<<" and y="<<dst[i].y<< endl;
    }
    return dst;
}
// function for filtering bad_object_points
Mat testfunc(vector<Point2i> imagePoints, Mat thermal_data, int bad_obj_points[307200]){

    Mat projected_image = Mat(Size(1,307200),CV_8UC1);
    int row[307200] = {0};
    int col[307200] = {0};
    // check boson data: wrong
//    for (int i =0; i<480;i++){
//        for (int j = 0; j< 640; j++){
//            if (thermal_data.at<int>(i,j)>255){
//                cout << "too much: "<<thermal_data.at<int>(i,j)<<endl;
//            }
//            if (thermal_data.at<int>(i,j)<0){
//                cout << "too little: "<<thermal_data.at<int>(i,j)<<endl;
//            }
//        }
//    }

    for (int i = 0; i < 307200; i++){
//        cout << count<<endl;
//        cout << imagePoints[i].x <<endl;
//        cout << imagePoints[i].y <<endl;
        row[i] = imagePoints[i].x;
        col[i] = imagePoints[i].y;
        if (row[i] >= 479)
        {row[i] = 479;}
        if (row[i] < 0)
        {row[i] = 0;}
        if (col[i] >= 639)
        {col[i] = 639;}
        if (col[i] < 0)
        {col[i] = 0;}


        projected_image.at<uchar>(i,0) = thermal_data.at<uchar>(col[i],row[i]);

        if (bad_obj_points[i] == 1)
        {projected_image.at<int>(i,0) = 0;
        }
    }
//    for (int i=100000; i < 100050;i++){
//        cout << projected_image.at<int>(i,0) <<endl;
//    }
    projected_image = projected_image.reshape(1, 480);

    return projected_image;
}
void print3Dpoints(vector<Point3d> real_point3d){
    for (int i = 10000; i<1000;i++){
        cout <<"x: "<< real_point3d[i].x<<endl;
        cout <<"y: "<< real_point3d[i].y<<endl;
        cout <<"z: "<< real_point3d[i].z<<endl;
    }
}
// functions for pointcloud visualization
pcl::PointCloud<pcl::PointXYZRGB>::Ptr pcl_generator (Mat &rgb, Mat &depth)
{

    double cx = 381.0;
    double cy = 379.2;
    double fx = 316.7;
    double fy = 233.7;
    double depthScale = 1000.0;


    typedef pcl::PointXYZRGB PointT;
    typedef pcl::PointCloud<PointT> PointCloud;



    PointCloud::Ptr pointCloud(new PointCloud);
    for (int v = 0; v < rgb.rows; v++)
        for (int u = 0; u < rgb.cols; u++) {
            unsigned int d = depth.ptr<unsigned short>(v)[u];
            if (d == 0)
                continue;
            PointT p;
            p.z = double(d) / depthScale;
            p.x = (u - cx) * p.z / fx;
            p.y = (v - cy) * p.z / fy;
            p.b = rgb.data[v * rgb.step + u * rgb.channels()];
            p.g = rgb.data[v * rgb.step + u * rgb.channels() + 1];
            p.r = rgb.data[v * rgb.step + u * rgb.channels() + 2];
            pointCloud->points.push_back(p);
        }


    return pointCloud;
}


#endif //FUSION_CALCPCD_H
