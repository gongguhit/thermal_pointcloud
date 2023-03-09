# thermal_pointcloud

## Intro

realsense d455 + Boson 320 to generate thermal pointcloud.

## Dependencies

```
- CMake version>=2.8
- PCL 1.2
- Realsense SDK
- OpenCV
- v4l2
```
## Running

1. Install the dependencies above.
2. check the boson's device port with v4l2
```bash
v4l2-ctl -d /dev/video- --all
```
Change the port number at row51 in `fusion_new.cpp`
3. Edit the CMakeLists.txt

change the librealsense2.so path
```
      "/home/gg/librealsense/build/librealsense2.so"
)
```
4. navigate to the root folder.
```bash
mkdir build && cd build
cmake ..
make
```
## Example
```HTML
<video width="320" height="240" controls>
    <source src="video/thermalpcd.mp4" type="video/mp4">
</video>
```
