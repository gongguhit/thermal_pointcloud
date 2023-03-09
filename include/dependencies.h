//
// Created by gg on 3/9/23.
//

#ifndef FUSION_DEPENDENCIES_H
#define FUSION_DEPENDENCIES_H

#include <stdio.h>
#include <fcntl.h>               // open, O_RDWR
#include <opencv2/opencv.hpp>

#include <unistd.h>              // close
#include <sys/ioctl.h>           // ioctl
#include <asm/types.h>           // videodev2.h
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/videodev2.h>
#include <vector>
#include <string>
#include <chrono>
#include <array>
#include <cmath>
#include <numeric>
#include "cv-helpers.hpp"
//lib for read numpy data
#include "npy.hpp"
// realsense library
#include <librealsense2/rs.hpp>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <cstring>

// Matrix computing
#include <Eigen/Core>
#include <Eigen/Dense>

#include <opencv2/core/eigen.hpp>
#include <opencv2/core/core.hpp>
// visualization
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>


#endif //FUSION_DEPENDENCIES_H
