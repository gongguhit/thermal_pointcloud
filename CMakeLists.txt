## realsense boson fusion cmakelists


# Version Information ---------------------------------------------------------
cmake_minimum_required(VERSION 2.8)
project(fusion)
set(CMAKE_CXX_STANDARD 11)

# Configure Source & Binary Directories ---------------------------------------
SET (PROJECT_ROOT "${PROJECT_SOURCE_DIR}")
SET (PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
SET (PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

# Configure Depenency Package --------------------------------------------------
find_package(OpenCV REQUIRED)
find_package(PCL 1.2 REQUIRED)
find_package(realsense2 REQUIRED)
find_package(Eigen3 REQUIRED)


# Include directories ---------------------------------------------------------
include_directories(
	${OpenCV_INCLUDE_DIRS}
	${PCL_INCLUDE_DIRS}
	${PROJECT_ROOT}
	${PROJECT_SOURCE_DIR}
	${PROJECT_INCLUDE_DIR}
	"/usr/local/include/"
	)
# Add executable --------------------------------------------------------------
add_executable(fusion ${PROJECT_SOURCE_DIR}/fusion_new.cpp)

# Link libraries --------------------------------------------------------------
target_link_libraries(fusion
        "/home/gg/librealsense/build/librealsense2.so"
        ${PCL_LIBRARIES}
        ${OpenCV_LIBS}
)

