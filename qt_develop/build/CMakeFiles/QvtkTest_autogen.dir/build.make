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

# Utility rule file for QvtkTest_autogen.

# Include the progress variables for this target.
include CMakeFiles/QvtkTest_autogen.dir/progress.make

CMakeFiles/QvtkTest_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QvtkTest"
	/usr/bin/cmake -E cmake_autogen /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles/QvtkTest_autogen.dir/AutogenInfo.json ""

QvtkTest_autogen: CMakeFiles/QvtkTest_autogen
QvtkTest_autogen: CMakeFiles/QvtkTest_autogen.dir/build.make

.PHONY : QvtkTest_autogen

# Rule to build all files generated by this target.
CMakeFiles/QvtkTest_autogen.dir/build: QvtkTest_autogen

.PHONY : CMakeFiles/QvtkTest_autogen.dir/build

CMakeFiles/QvtkTest_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QvtkTest_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QvtkTest_autogen.dir/clean

CMakeFiles/QvtkTest_autogen.dir/depend:
	cd /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build /home/gg/Downloads/calibcpp/thermal_pointcloud/thermal_pointcloud/qt_develop/build/CMakeFiles/QvtkTest_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QvtkTest_autogen.dir/depend
