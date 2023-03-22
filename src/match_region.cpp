//
// Created by gg on 3/22/23.
//
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int flags, void *userdata);

int main()
{
    // 读取图像
    Mat image = imread("../cmake-build-debug/realsense_output.jpg", IMREAD_COLOR);

    if (image.empty())
    {
        cout << "Error: Could not read the image!" << endl;
        return -1;
    }

    // 创建窗口并显示图像
    namedWindow("Image", WINDOW_AUTOSIZE);
    imshow("Image", image);

    // 设置鼠标回调函数
    setMouseCallback("Image", onMouse, &image);

    // 等待按键或关闭窗口
    waitKey(0);

    return 0;
}

// 鼠标回调函数
void onMouse(int event, int x, int y, int flags, void *userdata)
{
    if (event == EVENT_LBUTTONDOWN) // 检测鼠标左键点击
    {
        // 获取图像指针
        Mat *image = static_cast<Mat *>(userdata);

        // 在图像上绘制圆圈表示选定的点
        circle(*image, Point(x, y), 5, Scalar(0, 0, 255), -1);

        // 更新窗口显示
        imshow("Image", *image);

        // 输出点的坐标
        cout << "Point: (" << x << ", " << y << ")" << endl;
    }
}