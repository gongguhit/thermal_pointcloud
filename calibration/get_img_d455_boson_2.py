##============================================================================##
##  This program is to :                                                      ##
##  1. Get world coorrdinate to get extrinsics                                ##
##  2. get pixel coordinate of feature point both RGB and thermal             ##
##  3. store the data of world coordinate ,RGBD and thermal pixel coordinate  ##
##  4. Store the data of image, both for RGB and thermal cameras.             ##
##============================================================================##

## import necessary module 
import cv2
import numpy as np

## import realsense module
import pyrealsense2 as rs

## import IR module
from flirpy.camera.boson import Boson

# print opencv version 
print("OpenCV version is ", cv2.__version__)

## initialize image counter
index_p = 0

## setup realsense
# Configure depth and color streams
pipeline = rs.pipeline()
config = rs.config()
config.enable_stream(rs.stream.depth, 640, 480, rs.format.z16, 30)
config.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, 30)

# Start streaming of realsense and IR camera
pipeline.start(config)
thermal_cam = Boson()

## setup windows as free size
# cv2.namedWindow("Realsense D455", cv2.WINDOW_NORMAL) # make windows' size is changeable
# cv2.namedWindow('Boson320', cv2.WINDOW_NORMAL) # make windows' size is changeable

## Define board enveroment ##
#Define the real world coordinate of each circle_central_point(for a RGB picture)
point_coordinate = []

# Vector for 2D pixels points for RGB camera
rgbTwoDPoints = [] 

# Vector for 2D pixels points for Thermal camera
thermalTwoDPoints = [] 

# Define the dimensions of checkerboard 
CHECKERBOARD = (7, 5) 

# stop the iteration when specified accuracy, epsilon, is reached or specified number of iterations are completed. 
criteria = (cv2.TERM_CRITERIA_EPS +cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001) 

def detectCircle(colorImg) :
    colorImgCopy = cv2.cvtColor(colorImg, cv2.COLOR_BGR2BGRA)
    grayColor = cv2.cvtColor(colorImg, cv2.COLOR_BGR2GRAY)

    #bolb detect
    params = cv2.SimpleBlobDetector_Params()
    params.maxArea = 500
    params.minArea = 40
    params.minDistBetweenBlobs = 5
    detector = cv2.SimpleBlobDetector_create(params)
    try :
        # Find the chess board corners 
        # If desired number of corners are 
        # found in the image then ret = true 
        ret, corners = cv2.findCirclesGrid(grayColor, CHECKERBOARD, cv2.CALIB_CB_SYMMETRIC_GRID, blobDetector=detector)    #For symmetric circle calibration board
        # If desired number of corners can be detected then, 
        # refine the pixel coordinates and display 
        # them on the images of checker board 

        #if find the circle calibration board, return the x,y of point
        if ret == True: 
            # Refining pixel coordinates 
            # for given 2d points. 
            # Draw and display the corners 
            circle_det = cv2.drawChessboardCorners(colorImg, CHECKERBOARD, corners, ret)
            return circle_det, corners ,colorImgCopy     #two parameter return, one is image, the other is pixel coordinate

        # if not find the circle calibration board, return coordinate is none
        else :
            return  colorImg ,[],colorImgCopy
    except :
        return  colorImg ,[],colorImgCopy

## main function
if __name__ == "__main__":
    try :

        while True :
            ## circle the rgb image
            # Wait for a coherent pair of frames: color
            frames = pipeline.wait_for_frames()
            color_rgb_frame = frames.get_color_frame()
            if not color_rgb_frame:
                continue
            color_rgb_image = np.asanyarray(color_rgb_frame.get_data())
            circle_rgb, corner_rgb, raw_rgb = detectCircle(color_rgb_image)
            cv2.imshow('Realsense D455', circle_rgb)

            # circle the thermal camera
            # Capture thermal camera frame-by-frame
            # sometimes lost frame and get None on thermal frame ,lead error
            try :
                thermal_img_raw = thermal_cam.grab().astype(np.float32) # get raw thermal data ,16bit, Kelvin temperature scale

                # Rescale to 8 bit # normalize raw data
                thermal_img_gray = (255*(thermal_img_raw - thermal_img_raw.min())/(thermal_img_raw.max()-thermal_img_raw.min())).astype(np.uint8)
                thermal_img_low_res =  cv2.cvtColor(thermal_img_gray, cv2.COLOR_GRAY2BGR)
                thermal_img = cv2.resize(thermal_img_low_res[:,:], (640, 480))
                circle_thermal, Corner_thermal, raw_thermal = detectCircle(thermal_img)
                # cv2.imshow('Boson320', circle_thermal)
                imgs = np.hstack([circle_rgb,circle_thermal])
                cv2.imshow("calibration",imgs)
            except :
                continue
            key = cv2.waitKey(3)

            if key & 0xFF == ord("s") :   # save pixel coordinate of thermal camera and RGB camera && thermal and RGB image && sorld coordinate 
            # If RGB and thermal get feature point
                if len(corner_rgb) != 0 and len(Corner_thermal) != 0 :
                    rgbTwoDPoints.append(corner_rgb)
                    thermalTwoDPoints.append(Corner_thermal)

                    cv2.imwrite('/home/gg/Downloads/calibration/test_data_2/RealSense_RGB'+str(index_p)+'.png', circle_rgb)   #save raw RGB images
                    cv2.imwrite('/home/gg/Downloads/calibration/test_data_2/boson'+str(index_p)+'.png', circle_thermal)   #save raw thermal images
                    cv2.imwrite('/home/gg/Downloads/calibration/test_data_2/RealSense_RGB_raw'+str(index_p)+'.png', raw_rgb)
                    cv2.imwrite('/home/gg/Downloads/calibration/test_data_2/boson_raw'+str(index_p)+'.png', raw_thermal)
                    print("take picture %s" % index_p)
                    index_p += 1
                
                else : # have not detect the feature point
                    print("Undetect feature point...")
            

            elif key == 27 :  #ESC and save coordinate datas if press Esc
                rgbTwoDPoints = np.array(rgbTwoDPoints)
                np.save("/home/gg/Downloads/calibration/test_data_2/RGB_boson_pixel_coordinate.npy", rgbTwoDPoints)
                thermalTwoDPoints = np.array(thermalTwoDPoints)
                np.save("/home/gg/Downloads/calibration/test_data_2/boson_pixel_coordinate.npy", thermalTwoDPoints)
                break  

    finally :
        # Stop streaming
        pipeline.stop()
        #shutdown thermal camera
        thermal_cam.close()
        #close all windows
        cv2.destroyAllWindows()
