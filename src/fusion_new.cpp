#include "include/fusion_new.h"

int* gen_bad_points(vector<Point3d> real_point3d){
    static int bad_obj_points[307200];
    for (int i = 0; i < 307200; i++) {
        if (real_point3d[i].z == 0) {
            bad_obj_points[i] = 1;
        }
        else bad_obj_points[i] = 0;
    }
    return bad_obj_points;
}

int main(int argc, char** argv )
{
    int ret;
    int fd;
    struct v4l2_capability cap;
    long frame=0;     // First frame number enumeration
    char video[20];   // To store Video Port Device
    char label[50];   // To display the information
    char thermal_sensor_name[20];  // To store the sensor name
    char filename[60];  // PATH/File_count
    char folder_name[30];  // To store the folder name
    char video_frames_str[30];
    // Default Program options
    int  video_mode=RAW16;
    int  video_frames=0;
    int  zoom_enable=0;
    int  record_enable=0;
    sensor_types my_thermal=Boson320;

    //input calibration data
    cv::Mat rgbIntrinsic = readxml(rgbIn);
    cv::Mat rgbDistortion = readxml(rgbDis);
    cv::Mat thermalIntrinsic = readxml(thermalIn);
    cv::Mat thermalDistortion = readxml(thermalDis);
    cv::Mat relative_R = readxml(rel_R);
    cv::Mat relative_T = readxml(rel_T);
    cv::Mat x_real_imgplane = readxml("x_real_imgplane");
    cv::Mat y_real_imgplane = readxml("y_real_imgplane");
    x_real_imgplane.convertTo(x_real_imgplane,CV_64FC1);
    y_real_imgplane.convertTo(y_real_imgplane,CV_64FC1);

    Mat trans_mat;
    hconcat(relative_R,relative_T,trans_mat);
    Mat relative_Rvct;
    Rodrigues(relative_R,relative_Rvct);


    float fx = rgbIntrinsic.at<double>(0,0);
    float fy = rgbIntrinsic.at<double>(1,1);
    float cx = rgbIntrinsic.at<double>(0,2);
    float cy = rgbIntrinsic.at<double>(1,2);

    // To record images
    std::vector<int> compression_params;
    compression_params.push_back(IMWRITE_PXM_BINARY);


    // Video device by default
    sprintf(video, "/dev/video8");
    sprintf(thermal_sensor_name, "Boson_320");

    // Read command line arguments
    for (int i=0; i<argc; i++) {
        // Check if RAW16 video is desired
        if ( argv[i][0]=='r') {
            video_mode=RAW16;
        }
        // Check if AGC video is desired
        if ( argv[i][0]=='y') {
            video_mode=YUV;
        }
        // Check if ZOOM to 640x512 is enabled
        if ( argv[i][0]=='z') {
            zoom_enable=1;
        }
        // Check if recording is enabled
        if ( argv[i][0]=='f') {  // File name has to be more than two chars
            record_enable=1;
            if ( strlen(argv[i])>2 ) {
                strcpy(folder_name, argv[i]+1);
            }
        }
        // Look for type/size of sensor
        if ( argv[i][0]=='s') {
            switch ( argv[i][1] ) {
                case 'B'/* value */:
                    my_thermal=Boson640;
                    sprintf(thermal_sensor_name, "Boson_640");
                    break;
                default:
                    my_thermal=Boson320;
                    sprintf(thermal_sensor_name, "Boson_320");
            }
        }
        // Look for feedback in ASCII
        if (argv[i][0]>='0' && argv[i][0]<='9') {
            sprintf(video, "/dev/video%c",argv[i][0]);
        }
        // Look for frame count
        if ( argv[i][0]=='t') {
            if ( strlen(argv[i])>=2 ) {
                strcpy(video_frames_str, argv[i]+1);
                video_frames = atoi( video_frames_str );
                printf(WHT ">>> Number of frames to record =" YEL "%i" WHT "\n", video_frames);
            }
        }
    }

    // Folder name
    if (record_enable==1) {
        if ( strlen(folder_name)<=1 ) {  // File name has to be more than two chars
            strcpy(folder_name, thermal_sensor_name);
        }
        mkdir(folder_name, 0700);
        chdir(folder_name);
        printf(WHT ">>> Folder " YEL "%s" WHT " selected to record files\n", folder_name);
    }

    // Printf Sensor defined
    printf(WHT ">>> " YEL "%s" WHT " selected\n", thermal_sensor_name);

    // We open the Video Device
    printf(WHT ">>> " YEL "%s" WHT " selected\n", video);
    if((fd = open(video, O_RDWR)) < 0){
        perror(RED "Error : OPEN. Invalid Video Device" WHT "\n");
        exit(1);
    }

    // Check VideoCapture mode is available
    if(ioctl(fd, VIDIOC_QUERYCAP, &cap) < 0){
        perror(RED "ERROR : VIDIOC_QUERYCAP. Video Capture is not available" WHT "\n");
        exit(1);
    }

    if(!(cap.capabilities & V4L2_CAP_VIDEO_CAPTURE)){
        fprintf(stderr, RED "The device does not handle single-planar video capture." WHT "\n");
        exit(1);
    }

    struct v4l2_format format;

    // Two different FORMAT modes, 8 bits vs RAW16
    if (video_mode==RAW16) {
        printf(WHT ">>> " YEL "16 bits " WHT "capture selected\n");

        // I am requiring thermal 16 bits mode
        format.fmt.pix.pixelformat = V4L2_PIX_FMT_Y16;

        // Select the frame SIZE (will depend on the type of sensor)
        switch (my_thermal) {
            case Boson320:  // Boson320
                width=320;
                height=256;
                break;
            case Boson640:  // Boson640
                width=640;
                height=512;
                break;
            default:  // Boson320
                width=320;
                height=256;
                break;
        }

    } else { // 8- bits is always 640x512 (even for a Boson 320)
        printf(WHT ">>> " YEL "8 bits " WHT "YUV selected\n");
        format.fmt.pix.pixelformat = V4L2_PIX_FMT_YVU420; // thermal, works   LUMA, full Cr, full Cb
        width = 640;
        height = 512;
    }

    // Common varibles
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    format.fmt.pix.width = width;
    format.fmt.pix.height = height;

    // request desired FORMAT
    if(ioctl(fd, VIDIOC_S_FMT, &format) < 0){
        perror(RED "VIDIOC_S_FMT" WHT);
        exit(1);
    }

    // we need to inform the device about buffers to use.
    // and we need to allocate them.
    // we’ll use a single buffer, and map our memory using mmap.
    // All this information is sent using the VIDIOC_REQBUFS call and a
    // v4l2_requestbuffers structure:
    struct v4l2_requestbuffers bufrequest;
    bufrequest.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    bufrequest.memory = V4L2_MEMORY_MMAP;
    bufrequest.count = 1;   // we are asking for one buffer

    if(ioctl(fd, VIDIOC_REQBUFS, &bufrequest) < 0){
        perror(RED "VIDIOC_REQBUFS" WHT);
        exit(1);
    }

    // Now that the device knows how to provide its data,
    // we need to ask it about the amount of memory it needs,
    // and allocate it. This information is retrieved using the VIDIOC_QUERYBUF call,
    // and its v4l2_buffer structure.

    struct v4l2_buffer bufferinfo;
    memset(&bufferinfo, 0, sizeof(bufferinfo));

    bufferinfo.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    bufferinfo.memory = V4L2_MEMORY_MMAP;
    bufferinfo.index = 0;

    if(ioctl(fd, VIDIOC_QUERYBUF, &bufferinfo) < 0){
        perror(RED "VIDIOC_QUERYBUF" WHT);
        exit(1);
    }


    // map fd+offset into a process location (kernel will decide due to our NULL). lenght and
    // properties are also passed
    printf(WHT ">>> Image width  =" YEL "%i" WHT "\n", width);
    printf(WHT ">>> Image height =" YEL "%i" WHT "\n", height);
    printf(WHT ">>> Buffer lenght=" YEL "%i" WHT "\n", bufferinfo.length);

    void * buffer_start = mmap(NULL, bufferinfo.length, PROT_READ | PROT_WRITE,MAP_SHARED, fd, bufferinfo.m.offset);

    if(buffer_start == MAP_FAILED){
        perror(RED "mmap" WHT);
        exit(1);
    }

    // Fill this buffer with ceros. Initialization. Optional but nice to do
    memset(buffer_start, 0, bufferinfo.length);

    // Activate streaming
    int type = bufferinfo.type;
    if(ioctl(fd, VIDIOC_STREAMON, &type) < 0){
        perror(RED "VIDIOC_STREAMON" WHT);
        exit(1);
    }


    // Declarations for RAW16 representation
    // Will be used in case we are reading RAW16 format
    // Boson320 , Boson 640
    Mat thermal16(height, width, CV_16U, buffer_start);   // OpenCV input buffer  : Asking for all info: two bytes per pixel (RAW16)  RAW16 mode`
    Mat thermal16_linear(height,width, CV_8U, 1);         // OpenCV output buffer : Data used to display the video

    // Declarations for Zoom representation
    // Will be used or not depending on program arguments
    Size size(640,512);
    Mat thermal16_linear_zoom;   // (height,width, CV_8U, 1);    // Final representation
    Mat thermal_rgb_zoom;   // (height,width, CV_8U, 1);    // Final representation

    int luma_height ;
    int luma_width ;
    int color_space ;;

    // Declarations for 8bits YCbCr mode
    // Will be used in case we are reading YUV format
    // Boson320, 640 :  4:2:0
    luma_height = height+height/2;
    luma_width = width;
    color_space = CV_8UC1;
    Mat thermal_luma(luma_height, luma_width,  color_space, buffer_start);  // OpenCV input buffer
    Mat thermal_rgb(height, width, CV_8UC3, 1);    // OpenCV output buffer , BGR -> Three color spaces (640 - 640 - 640 : p11 p21 p31 .... / p12 p22 p32 ..../ p13 p23 p33 ...)

    // start to read realsense d455

    // 深度图像颜色
    rs2::colorizer c;
    // 创建数据管道
    rs2::pipeline pipe;
    rs2::config pipe_config;
    pipe_config.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
    pipe_config.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_RGB8, 30);
    // start() 函数返回数据管道的profile
    rs2::pipeline_profile profile = pipe.start(pipe_config);
    // rs2::pipeline_profile profile = pipe.start();
    // 使用数据管道的 profile 获取深度图像像素对应于长度单位（米）的转换比例
    float depth_scale = get_depth_scale(profile.get_device());

    // 选择彩色图像数据流来作为对齐对象
    rs2_stream align_to = RS2_STREAM_COLOR; // 对齐的是彩色图，所以彩色图是不变的
    // // 将深度图对齐到RGB图
    rs2::align align(align_to);

    //define pointcloud data
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud (new pcl::PointCloud<pcl::PointXYZRGB>);
    // set viewer parameter
    viewer->setCameraPosition(0, 0, -3.0, 0, -1, 0);
    viewer->addCoordinateSystem(1);
    bool showFPS = true;
    viewer->setShowFPS(showFPS);

    // define variable out of the main loop here
    Mat thermal_data;
    Mat thermal_img_gray, thermalImage, depthdata, rgbImage, depth_colormap, RGBImage;
    Mat real_point_depth;
    vector<Point2d> imagePoints;
    Mat projected_image, temp_colormap;
    Mat high_temp_image, temp_mask;

//    int bad_obj_points[307200];
    int* bad_obj_points;
    int temp_thres = 120;
    int max_temp;

    Mat w_x;
    Mat w_y;

    vector<Point3d> real_point3d;
    vector<Point2i> imagePoints_int;

    // Main loop
    for (;;) {

        // Put the buffer in the incoming queue.
        if(ioctl(fd, VIDIOC_QBUF, &bufferinfo) < 0){
            perror(RED "VIDIOC_QBUF" WHT);
            exit(1);
        }

        // The buffer's waiting in the outgoing queue.
        if(ioctl(fd, VIDIOC_DQBUF, &bufferinfo) < 0) {
            perror(RED "VIDIOC_QBUF" WHT);
            exit(1);
        }


        // -----------------------------
        // RAW16 DATA
        if ( video_mode==RAW16 ) {
            AGC_Basic_Linear(thermal16, thermal16_linear, height, width);

        }

        // Stop if frame limit reached.
        if (video_frames>0 && frame+1 > video_frames) {
            printf(WHT ">>>" GRN "'Done'" WHT " Frame limit reached, Quitting !\n");
            break;
        }
        //thermal16 for raw data, thermal16_linear for regularization data
        //end of load boson image

        // start to get realsense data
        // 堵塞程序直到新的一帧捕获
        rs2::frameset frameset = pipe.wait_for_frames();
        // 正在对齐深度图到其他图像流，我们要确保对齐的图像流不发生改变
        if (profile_changed(pipe.get_active_profile().get_streams(), profile.get_streams()))
        {
            // 如果profile发生改变，则更新align对象，重新获取深度图像像素到长度单位的转换比例
            profile = pipe.get_active_profile();
            align = rs2::align(align_to);
            depth_scale = get_depth_scale(profile.get_device());
        }
        // 获取对齐后的帧
        auto processed = align.process(frameset);
        // 尝试获取对齐后的深度图像帧和其他帧
        rs2::frame aligned_color_frame = processed.get_color_frame();                 // RGB图
        rs2::frame aligned_depth_frame = processed.get_depth_frame(); // 深度图
        // 获取对齐之前的color图像
        rs2::frame before_depth_frame = frameset.get_depth_frame().apply_filter(c); // 获取对齐之前的深度图
        // 获取宽高
        const int depth_w = aligned_depth_frame.as<rs2::video_frame>().get_width();
        const int depth_h = aligned_depth_frame.as<rs2::video_frame>().get_height();
        const int color_w = aligned_color_frame.as<rs2::video_frame>().get_width();
        const int color_h = aligned_color_frame.as<rs2::video_frame>().get_height();
        const int b_color_w = before_depth_frame.as<rs2::video_frame>().get_width();
        const int b_color_h = before_depth_frame.as<rs2::video_frame>().get_height();
        // 如果其中一个未能获取，继续迭代
        if (!aligned_depth_frame || !aligned_color_frame)
        {
            continue;
        }

        // try not to make new cv::Mat in each loop 
        // define them only onces and try to reuse them in every iteration
        // otherwise, it would slow down the whole iteration 



        // 创建opencv类型，并传入数据
        Mat aligned_depth_image(Size(depth_w, depth_h), CV_16UC1, (void *)aligned_depth_frame.get_data(), Mat::AUTO_STEP);
        Mat aligned_color_image(Size(color_w, color_h), CV_8UC3, (void *)aligned_color_frame.get_data(), Mat::AUTO_STEP);
//        Mat before_depth_image(Size(b_color_w, b_color_h), CV_8UC3, (void *)before_depth_frame.get_data(), Mat::AUTO_STEP);
        // 彩色图RGB转BGR
        cvtColor(aligned_color_image, aligned_color_image, COLOR_RGB2BGR);



        // try not to make new cv::Mat in each loop 
        // same as above

        thermal_data = thermal16_linear.clone();
        resize(thermal_data,thermal_data,Size(640,480));

        // Below for projection

        // try not to make new cv::Mat in each loop 
        // same as above
        // if all the cv::Mat and vector<Point2d> will remain same size in every iteration
        // then please define them out of loop anď resue them



        // i'm sure the size of vector<Point2d> imagePoints will remain same 
        // try to define out of loop and repopulate in each iteration




        // obtain realsense output
        depthdata = aligned_depth_image.clone();
//        rgbImage = aligned_color_image.clone();
        RGBImage = aligned_color_image.clone();



        depthdata.convertTo(depthdata, CV_64FC1);
        w_x = x_real_imgplane.mul(depthdata);
        w_y = y_real_imgplane.mul(depthdata);
        // Here I try many method to avoid creating new Mat, but failed
        Mat real_point_depth_temp[] = {w_x,w_y,depthdata};
        merge(real_point_depth_temp, 3,real_point_depth);
        Mat real_point = real_point_depth.reshape(3, 307200);


        // i'm sure the size of vector<Point3d> real_point3d will remain same 
        // try to define out of loop and repopulate in each iteration
        // Ok, transform it to a function
        // Then need to transform the 3 channels points to Point3d

        real_point3d = Mat2Point(real_point);

//        for (int i = 0; i < 307200; i++) {
//            if (real_point3d[i].z == 0) {
//                bad_obj_points[i] = 1;
//            }
//            else bad_obj_points[i] = 0;
//        }
        // convert this loop to
        bad_obj_points = gen_bad_points(real_point3d);


        projectPoints(real_point3d, relative_Rvct, relative_T, thermalIntrinsic, thermalDistortion, imagePoints);

        // if the vector<Point2i> imagePoints_int will nerver change try to 
        // define out of loop and then call the function and pass the argument by reference
        // to avoid unneccessary copying   
        imagePoints_int = Pointf2i(imagePoints);


        // if the projected_image will nerver change try to 
        // define out of loop and then call the function and pass the argument by reference
        // to avoid unneccessary copying   
        projected_image = testfunc(imagePoints_int,thermal_data,bad_obj_points);


        // Filter the high temperature regieon
        high_temp_image = projected_image.clone();
        threshold(high_temp_image, high_temp_image, temp_thres, 255, THRESH_TOZERO);
        high_temp_image.convertTo(high_temp_image, CV_8UC1);
        temp_mask = high_temp_image.clone();
        // generate a high temperature mask
        for (int i = 0; i < 480; i++) {
            for (int j = 0; j < 640; j++) {
                if (temp_mask.at<uchar>(i, j) == 0) {
                    temp_mask.at<uchar>(i, j) = 1;
                }
            }
        }

        Mat find_max_temp = high_temp_image.reshape(1,1);
        double minValue,maxValue;
        Point minIdx,maxIdx;
        minMaxLoc(find_max_temp,&minValue,&maxValue,&minIdx,&maxIdx);
        max_temp = floor(maxValue);

        for (int i = 0; i < 480; i++) {
            for (int j = 0; j < 640; j++) {
                if (high_temp_image.at<uchar>(i, j) != 0) {
                    high_temp_image.at<uchar>(i, j) = floor(float((high_temp_image.at<uchar>(i, j) - temp_thres)) / float((max_temp - temp_thres)) * 255);
                }
            }
        }

        applyColorMap(high_temp_image, temp_colormap, COLORMAP_HOT);


        for (int i = 0; i < 480; i++) {
            for (int j = 0; j < 640; j++) {
                if (temp_mask.at<uchar>(i, j) == 1) {
                    temp_colormap.at<Vec3b>(i, j) = RGBImage.at<Vec3b>(i, j);
                }
            }
        }

        // if the cloud will nerver change try to 
        // define out of loop and then call the function and pass the argument by reference
        // to avoid unneccessary copying   
        cloud = pcl_generator(temp_colormap,aligned_depth_image);
//        pcl_generator(cloud,temp_colormap,aligned_depth_image);
        viewer->removeAllPointClouds();
        viewer->addPointCloud(cloud,"Cloud Viewer");
        viewer->updatePointCloud(cloud,"Cloud Viewer");
        viewer->spinOnce(0.000000000001);

    }

    // Finish Loop . Exiting.

    // Deactivate streaming
    if( ioctl(fd, VIDIOC_STREAMOFF, &type) < 0 ){
        perror(RED "VIDIOC_STREAMOFF" WHT);

        exit(1);
    };

    close(fd);
    return EXIT_SUCCESS;
}