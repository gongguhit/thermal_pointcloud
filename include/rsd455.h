//
// Created by gg on 3/9/23.
//
#ifndef FUSION_RSD455_H
#define FUSION_RSD455_H

#include "dependencies.h"

using namespace cv;
using namespace std;

float get_depth_scale(rs2::device dev)
{
    // 遍历设备的传感器
    for (rs2::sensor &sensor : dev.query_sensors())
    {
        // 检查传感器是否是深度传感器
        if (rs2::depth_sensor dpt = sensor.as<rs2::depth_sensor>())
            return dpt.get_depth_scale();
    }
    throw std::runtime_error("Device does not have a depth sensor");
}
bool profile_changed(const std::vector<rs2::stream_profile> &current, const std::vector<rs2::stream_profile> &prev)
{
    for (auto &&sp : prev)
    {
        // if previous profile is in current ( maybe just added another)
        auto itr = std::find_if(std::begin(current), std::end(current), [&sp](const rs2::stream_profile &current_sp)
        { return sp.unique_id() == current_sp.unique_id(); });
        if (itr == std::end(current))
        {
            return true;
        }
    }
    return false;
}
// 获取深度像素对应长度单位转换
float get_depth_scale(rs2::device dev);
// 检查摄像头数据管道设置是否改变
bool profile_changed(const std::vector<rs2::stream_profile> &current, const std::vector<rs2::stream_profile> &prev);

enum class direction
{
    to_depth,
    to_color
};

#endif //FUSION_RSD455_H
