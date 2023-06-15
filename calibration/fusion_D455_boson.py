##
## dispaly the fusing image

## import time for calc fps
import time

## import necessary module 
import cv2
import numpy as np
from numpy.lib.format import _filter_header

## import realsense module
import pyrealsense2 as rs

## import IR module
from flirpy.camera.boson import Boson

# cv2.namedWindow('fusion image', cv2.WINDOW_NORMAL)

img_num = 0

## read the datas ##
#RGBD data
rgbIntrinsic = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_RGB_intrinsic.npy")
rgbDistortion = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_RGB_distortion.npy")

#thermal data
thermalIntrinsic = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_Thermal_intrinsic.npy")
thermalDistortion = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_Thermal_distortion.npy")

# rotation and translation data
relative_R = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_Ralative_rotation_matrix.npy")
relative_T = np.load("/home/gg/Downloads/calibration/test_data/boson_realsense_Ralative_translation_matrix.npy")
trans_mat = np.c_[relative_R,relative_T] #creat relative translation matrix 
relative_Rvct = (cv2.Rodrigues(relative_R))[0]
## read image of RGB and thermal camera and to get size of images
rgbImage = cv2.imread('/home/gg/Downloads/calibration/test_data/RealSense_RGB0.png')
rgbImage_g = cv2.cvtColor(rgbImage, cv2.COLOR_BGR2GRAY)   #graylize
thermalImage = cv2.imread('/home/gg/Downloads/calibration/test_data/boson0.png')
# thermalImage_g = cv2.cvtColor(thermalImage, cv2.COLOR_BGR2GRAY)   #graylize
rgbShape = rgbImage_g.shape[::-1]
thermalShape = thermalImage.shape[::-1]


## setup realsense
# Configure depth and color streams
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 15)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 15)

# Start streaming
profile = pipeline.start(config)
thermal_cam = Boson() ## boson camera

# Getting the depth sensor's depth scale (see rs-align example for explanation)
depth_sensor = profile.get_device().first_depth_sensor()
depth_scale = depth_sensor.get_depth_scale()
# print("Depth Scale is: " , depth_scale)

# Create an align object
# rs.align allows us to perform alignment of depth frames to others frames
# The "align_to" is the stream type to which we plan to align depth frames.
align_to = rs.stream.color
align = rs.align(align_to)

def get_rgbd_stream(): # with depth and color aligned
    # Wait for a coherent pair of frames: color
    frames = pipeline.wait_for_frames()
    aligned_frames = align.process(frames)
    aligned_depth_frame = aligned_frames.get_depth_frame() # aligned_depth_frame is a 640x480 depth image
    color_frame = aligned_frames.get_color_frame()
    depth_image = np.asanyarray(aligned_depth_frame.get_data())
    # depth_image = np.multiply(depth_scale,depth_image)
    color_image = np.asanyarray(color_frame.get_data())

    # return rgb image
    return depth_image, color_image

def get_thermal_stream():
    thermal_img_raw = thermal_cam.grab().astype(np.float32) # get raw thermal data ,16bit, Kelvin temperature scale

    # Rescale to 8 bit # normalize raw data
    # thermal_img_gray = (255*(thermal_img_raw - thermal_img_raw.min())/(thermal_img_raw.max()-thermal_img_raw.min())).astype(np.uint8)
    thermal_img_gray = ((thermal_img_raw-27313)*0.04).astype(np.uint8)
    thermal_img = cv2.resize(thermal_img_gray[:,:], (640, 480))
    thermal_data = cv2.resize(thermal_img_raw[:,:], (640, 480))
    return thermal_img, thermal_data


## from pixel coordinate to image coordinate
fx = rgbIntrinsic[0,0]
fy = rgbIntrinsic[1,1]
cx = rgbIntrinsic[0,2]
cy = rgbIntrinsic[1,2]
x = np.arange(0,640)
y = np.arange(0,480)
x_c = np.tile(x, (480, 1))
y_c = np.tile(y,(640,1))
y_c = np.transpose(y_c)
x_real_imgplane = (x_c-cx)/fx
y_real_imgplane = (y_c-cy)/fy

# undistort image
def undist (frame, mtx, dist,imsize):
    newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, imsize, 1)## change the value 1 (with black bounder)or 0 (remove black bounder), 
    udst = cv2.undistort(frame, mtx, dist, None, newcameramtx)
    return udst

# cv2.namedWindow("fusion image", cv2.WINDOW_NORMAL) # make windows' size is changeable

if __name__ == "__main__" :
    # try :
      
    start_time = time.time()
    counter = 0
    counter_1 = 0
    while True :
        thermalImage, data = get_thermal_stream() #get thermal image
        depthdata, rgbImage = get_rgbd_stream()    #get aligned RGBD image
        counter += 1
        depth_colormap = cv2.applyColorMap(cv2.convertScaleAbs(depthdata, alpha=0.03), cv2.COLORMAP_JET) #convert depthdata to depth image
        RGBImage = rgbImage.copy()
        # get min max value
        # minVal, maxVal, minLoc, maxLoc = cv2.minMaxLoc(data)

        # ud_thermal = undist(thermalImage, thermalIntrinsic, thermalDistortion, (480, 640))    # undistort thermal image ## may do not need 
        ## aligned thermal image with RGB and depth image
        w_x = np.multiply(x_real_imgplane,depthdata)
        w_y = np.multiply(y_real_imgplane,depthdata)
        real_point = np.stack((w_x,w_y,depthdata),axis = -1)
    
        real_point = real_point.reshape(307200,3)
        bad_obj_points=np.where(real_point[:,2] == 0)

        # thermal_1D = thermalImage.reshape(307200)

        imagePoints, jacobian = cv2.projectPoints(real_point, relative_Rvct, relative_T, thermalIntrinsic, thermalDistortion)

        imagePoints = imagePoints[:,0,:]
        imagePoints =np.round((imagePoints).astype(int))
        imagePoints = np.flip(imagePoints,axis=1)

        row = imagePoints[:,0]
        row[row>=479] = np.array([479])
        row[row<0] = np.array([0])
        col = imagePoints[:,1]
        col[col>=639] = np.array([639])
        col[col<0] = np.array([0])

        projected_image = thermalImage[row,col]
        projected_image[bad_obj_points] = 1
        projected_image= 255 - (projected_image.reshape(480,640))
        # projected_img_color_1 = cv2.applyColorMap(projected_image, cv2.COLORMAP_HOT)
        # projected_img_color = cv2.cvtColor(projected_img_color_1,cv2.COLOR_RGB2BGR)
        ret,mask = cv2.threshold(projected_image,0,255,cv2.THRESH_BINARY)
        fusion_img = cv2.bitwise_not(projected_image,rgbImage,mask = mask)

        # cut wrong edge
        fusion_img_cut = fusion_img[102:378,135:503] # 3 time ,4 times
        RGBImage_cut = RGBImage[102:378,135:503] # the same
        depth_colormap_cut = depth_colormap[102:378,135:503]

        # fusion_img_cut_resize = cv2.resize(fusion_img_cut[:,:], (640, 480))
        # RGBImage_cut_resize = cv2.resize(RGBImage_cut[:,:], (640, 480))
        # depth_colormap_cut_resize = cv2.resize(depth_colormap_cut[:,:], (640, 480),cv2.INTER_NEAREST)
        # fusion_img_cut_resize_HSV = cv2.applyColorMap(fusion_img_cut_resize,cv2.COLORMAP_JET)
        # real_fus_img = cv2.addWeighted(RGBImage_cut_resize,0.5,fusion_img_cut_resize_HSV,0.5,0)

        fusion_img_cut_JET = cv2.applyColorMap(fusion_img_cut,cv2.COLORMAP_JET)
        real_fus_img = cv2.addWeighted(RGBImage_cut,0.5,fusion_img_cut_JET,0.5,0)
        print(real_fus_img.shape)
        
        thermal_inverse = 255-thermalImage
        
        
        thermal_color_resized = cv2.applyColorMap(cv2.resize(thermalImage[:,:], (368, 276)),cv2.COLORMAP_HOT)
        cv2.namedWindow('fusion image',0)
        cv2.resizeWindow('fusion image',640,480)
        cv2.imshow('fusion image',real_fus_img)
        cv2.imshow("depth image", depth_colormap_cut)

        if (time.time()-start_time)!=0:
            cv2.putText(thermal_color_resized,"FPS {0}".format(float('%.1f'%(counter/(time.time() - start_time)))),(200,50),cv2.FONT_HERSHEY_SIMPLEX,1,(0,0,255),3)
            cv2.imshow("thermal image", thermal_color_resized)
            print("FPS:",counter / (time.time()-start_time))
            counter = 0
            start_time = time.time()
        cv2.imshow("RGB image", RGBImage_cut)
        key = cv2.waitKey(10) & 0xFF

        # if key & 0xFF == ord("s") :   # save pixel coordinate of thermal camera and RGB camera && thermal and RGB image && sorld coordinate 
        #     cv2.imwrite('/home/zhangtanhao/Desktop/DynaSLAM/data/test_img/fustion_img%i.jpg'%img_num, fusion_img_cut_resize)
        #     # cv2.imwrite('/home/zhangtanhao/Desktop/DynaSLAM/data/test_img/thermal_img%i.jpg'%img_num, thermalImage)
        #     # cv2.imwrite('/home/zth/Desktop/pyProg/test_img/depth_IR_img%i.png'%img_num, depthImage)
        #     cv2.imwrite('/home/zhangtanhao/Desktop/DynaSLAM/data/test_img/RGB_img%i.jpg'%img_num, RGBImage_cut_resize)
        #     print("image saving.......")
        #     img_num  = img_num +1
        if key & 0xFF == 27 :
            break
            

# finally :
    # Stop streaming
    pipeline.stop()
    img_num = 0
    #shutdown thermal camera
    thermal_cam.close()
    #close all windows
    cv2.destroyAllWindows()
    print("close all successfully, ending......")
