# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build

# Include any dependencies generated for this target.
include CMakeFiles/QvtkTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/QvtkTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QvtkTest.dir/flags.make

QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../images.qrc
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: CMakeFiles/QvtkTest_autogen.dir/AutoRcc_images_EWIEGA46WW_Info.json
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../icons/imat2.png
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../icons/imat1.png
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../icons/romilogo.jpeg
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../icons/icon.jpg
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: ../icons/polyu.jpg
QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp: /opt/Qt5.14.2/5.14.2/gcc_64/bin/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic RCC for images.qrc"
	/usr/bin/cmake -E cmake_autorcc /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles/QvtkTest_autogen.dir/AutoRcc_images_EWIEGA46WW_Info.json 

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o: CMakeFiles/QvtkTest.dir/flags.make
CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o: QvtkTest_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o -c /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/mocs_compilation.cpp

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/mocs_compilation.cpp > CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.i

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/mocs_compilation.cpp -o CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.s

CMakeFiles/QvtkTest.dir/main.cpp.o: CMakeFiles/QvtkTest.dir/flags.make
CMakeFiles/QvtkTest.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QvtkTest.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QvtkTest.dir/main.cpp.o -c /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/main.cpp

CMakeFiles/QvtkTest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QvtkTest.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/main.cpp > CMakeFiles/QvtkTest.dir/main.cpp.i

CMakeFiles/QvtkTest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QvtkTest.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/main.cpp -o CMakeFiles/QvtkTest.dir/main.cpp.s

CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o: CMakeFiles/QvtkTest.dir/flags.make
CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o: ../QvtkTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o -c /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/QvtkTest.cpp

CMakeFiles/QvtkTest.dir/QvtkTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QvtkTest.dir/QvtkTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/QvtkTest.cpp > CMakeFiles/QvtkTest.dir/QvtkTest.cpp.i

CMakeFiles/QvtkTest.dir/QvtkTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QvtkTest.dir/QvtkTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/QvtkTest.cpp -o CMakeFiles/QvtkTest.dir/QvtkTest.cpp.s

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o: CMakeFiles/QvtkTest.dir/flags.make
CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o: QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o -c /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp > CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.i

CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp -o CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.s

# Object files for target QvtkTest
QvtkTest_OBJECTS = \
"CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QvtkTest.dir/main.cpp.o" \
"CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o" \
"CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o"

# External object files for target QvtkTest
QvtkTest_EXTERNAL_OBJECTS =

QvtkTest: CMakeFiles/QvtkTest.dir/QvtkTest_autogen/mocs_compilation.cpp.o
QvtkTest: CMakeFiles/QvtkTest.dir/main.cpp.o
QvtkTest: CMakeFiles/QvtkTest.dir/QvtkTest.cpp.o
QvtkTest: CMakeFiles/QvtkTest.dir/QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp.o
QvtkTest: CMakeFiles/QvtkTest.dir/build.make
QvtkTest: /usr/local/lib/libpcl_surface.so
QvtkTest: /usr/local/lib/libpcl_keypoints.so
QvtkTest: /usr/local/lib/libpcl_tracking.so
QvtkTest: /usr/local/lib/libpcl_recognition.so
QvtkTest: /usr/local/lib/libpcl_stereo.so
QvtkTest: /usr/local/lib/libpcl_outofcore.so
QvtkTest: /usr/local/lib/libpcl_people.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_system.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libboost_regex.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libqhull.so
QvtkTest: /usr/lib/libOpenNI.so
QvtkTest: /usr/lib/libOpenNI2.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libflann_cpp.so
QvtkTest: /usr/local/lib/libvtkChartsCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkInfovisCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOGeometry-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOLegacy-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOPLY-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingLOD-8.2.so.1
QvtkTest: /usr/local/lib/libvtkViewsContext2D-8.2.so.1
QvtkTest: /usr/local/lib/libvtkViewsCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingContextOpenGL2-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingQt-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersTexture-8.2.so.1
QvtkTest: /usr/local/lib/libvtkGUISupportQt-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingLabel-8.2.so.1
QvtkTest: /home/gg/librealsense/build/librealsense2.so
QvtkTest: /home/gg/software/build/lib/libvtkGUISupportQt-8.2.so
QvtkTest: /usr/local/lib/libopencv_dnn.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_highgui.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_ml.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_objdetect.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_shape.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_stitching.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_superres.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_videostab.so.3.4.14
QvtkTest: /usr/local/lib/libpcl_registration.so
QvtkTest: /usr/local/lib/libpcl_segmentation.so
QvtkTest: /usr/local/lib/libpcl_features.so
QvtkTest: /usr/local/lib/libpcl_filters.so
QvtkTest: /usr/local/lib/libpcl_sample_consensus.so
QvtkTest: /usr/local/lib/libpcl_ml.so
QvtkTest: /usr/local/lib/libpcl_visualization.so
QvtkTest: /usr/local/lib/libpcl_search.so
QvtkTest: /usr/local/lib/libpcl_kdtree.so
QvtkTest: /usr/local/lib/libpcl_io.so
QvtkTest: /usr/local/lib/libpcl_octree.so
QvtkTest: /usr/local/lib/libpcl_common.so
QvtkTest: /usr/local/lib/libvtkInteractionWidgets-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersModeling-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersHybrid-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingGeneral-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingSources-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingHybrid-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOImage-8.2.so.1
QvtkTest: /usr/local/lib/libvtkDICOMParser-8.2.so.1
QvtkTest: /usr/local/lib/libvtkmetaio-8.2.so.1
QvtkTest: /usr/local/lib/libvtkpng-8.2.so.1
QvtkTest: /usr/local/lib/libvtktiff-8.2.so.1
QvtkTest: /usr/local/lib/libvtkjpeg-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingAnnotation-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingColor-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingVolume-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOXML-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOXMLParser-8.2.so.1
QvtkTest: /usr/local/lib/libvtkIOCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkdoubleconversion-8.2.so.1
QvtkTest: /usr/local/lib/libvtklz4-8.2.so.1
QvtkTest: /usr/local/lib/libvtklzma-8.2.so.1
QvtkTest: /usr/local/lib/libvtkexpat-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingContext2D-8.2.so.1
QvtkTest: /opt/Qt5.14.2/5.14.2/gcc_64/lib/libQt5Widgets.so.5.14.2
QvtkTest: /opt/Qt5.14.2/5.14.2/gcc_64/lib/libQt5Gui.so.5.14.2
QvtkTest: /opt/Qt5.14.2/5.14.2/gcc_64/lib/libQt5Core.so.5.14.2
QvtkTest: /usr/local/lib/libvtkInteractionStyle-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersExtraction-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersStatistics-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingFourier-8.2.so.1
QvtkTest: /usr/local/lib/libvtkImagingCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingOpenGL2-8.2.so.1
QvtkTest: /usr/local/lib/libvtkglew-8.2.so.1
QvtkTest: /usr/lib/x86_64-linux-gnu/libSM.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libICE.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libX11.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libXext.so
QvtkTest: /usr/lib/x86_64-linux-gnu/libXt.so
QvtkTest: /usr/local/lib/libvtkRenderingFreeType-8.2.so.1
QvtkTest: /usr/local/lib/libvtkRenderingCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonColor-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersGeometry-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersSources-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersGeneral-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonComputationalGeometry-8.2.so.1
QvtkTest: /usr/local/lib/libvtkFiltersCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonExecutionModel-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonDataModel-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonTransforms-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonMisc-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonMath-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonSystem-8.2.so.1
QvtkTest: /usr/local/lib/libvtkCommonCore-8.2.so.1
QvtkTest: /usr/local/lib/libvtksys-8.2.so.1
QvtkTest: /usr/local/lib/libvtkfreetype-8.2.so.1
QvtkTest: /usr/local/lib/libvtkzlib-8.2.so.1
QvtkTest: /usr/local/lib/libopencv_calib3d.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_features2d.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_flann.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_photo.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_video.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_videoio.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_imgcodecs.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_imgproc.so.3.4.14
QvtkTest: /usr/local/lib/libopencv_core.so.3.4.14
QvtkTest: CMakeFiles/QvtkTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable QvtkTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QvtkTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QvtkTest.dir/build: QvtkTest

.PHONY : CMakeFiles/QvtkTest.dir/build

CMakeFiles/QvtkTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QvtkTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QvtkTest.dir/clean

CMakeFiles/QvtkTest.dir/depend: QvtkTest_autogen/EWIEGA46WW/qrc_images.cpp
	cd /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles/QvtkTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QvtkTest.dir/depend

