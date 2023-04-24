cmake_minimum_required(VERSION 3.5)

project(QvtkTest LANGUAGES CXX)

# file(GLOB_RECURSE QRC_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.qrc)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(QRC_SOURCE_FILES images.qrc)
set(RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/images)
# Configure Source & Binary Directories ---------------------------------------

# select compile method

## 定义 CMAKE_BUILD_TYPE 变量
#set(CMAKE_BUILD_TYPE Debug)

## 在项目中使用 CMAKE_BUILD_TYPE 变量
#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    message("Debug build")
#else()
#    message("Release build")
#endif()

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package (VTK REQUIRED)
find_package(OpenCV REQUIRED)
find_package(PCL 1.11 REQUIRED)
find_package(realsense2 REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

qt5_add_resources(RESOURCES ${RESOURCES_DIR}/images.qrc)

# SOURCE_GROUP("Resource Files" FILES ${QRC_SOURCE_FILES})
add_definitions(${PCL_DEFINITIONS})


# Include directories ---------------------------------------------------------
include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${PCL_INCLUDE_DIRS}
        ${PROJECT_ROOT}
        ${PROJECT_SOURCE_DIR}
        ${PROJECT_INCLUDE_DIR}
        "/usr/local/include/"
        )

link_directories    (${PCL_LIBRARY_DIRS})

if(ANDROID)
  add_library(QvtkTest SHARED
      main.cpp
      QvtkTest.cpp
      QvtkTest.h
      boson320.h
      calcpcd.h
      dependencies.h
      fusion_new.h
      rsd455.h
      QvtkTest.ui
      images.qrc
  )
else()
  add_executable(QvtkTest
    main.cpp
    QvtkTest.cpp
    QvtkTest.h
    boson320.h
    calcpcd.h
    dependencies.h
    fusion_new.h
    rsd455.h
    QvtkTest.ui
    images.qrc
    global.h
    global.cpp
  )
endif()

target_link_libraries(QvtkTest PRIVATE Qt5::Widgets
    ${QT_LIBRARIES}
    ${PCL_LIBRARIES}
    ${VTK_LIBRARIES}
    "/home/gg/librealsense/build/librealsense2.so"
    "/home/gg/software/build/lib/libvtkGUISupportQt-8.2.so"
     ${OpenCV_LIBS}
    )
