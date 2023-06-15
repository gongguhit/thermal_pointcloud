## import necessary module 
import cv2
import numpy as np

## import realsense module
import pyrealsense2 as rs

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


## setup windows as free size
#cv2.namedWindow("Realsense D455", cv2.WINDOW_NORMAL) # make windows' size is changeable

## Define board enveroment ##
#Define the real world coordinate of each circle_central_point(for a RGB picture)
point_coordinate = []

# Vector for 2D pixels points for RGB camera
rgbTwoDPoints = [] 


# Define the dimensions of checkerboard 
CHECKERBOARD = (7, 5) 

# stop the iteration when specified accuracy, epsilon, is reached or specified number of iterations are completed. 
criteria = (cv2.TERM_CRITERIA_EPS +cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001) 

# Fake 3D point to get intrinsics
fakeThreeDPoint = []
objectp3d = np.zeros((1, CHECKERBOARD[0] * CHECKERBOARD[1], 3), np.float32) 
objectp3d[0, :, :2] = 70*np.mgrid[0:CHECKERBOARD[0], 0:CHECKERBOARD[1]].T.reshape(-1, 2) 

# print(objectp3d)
for each_pic in range(55) : ## the image number
    fakeThreeDPoint.append(objectp3d)
fakeThreeDPoint = np.array(fakeThreeDPoint)



def detectCircle(colorImg) :
    colorImgCopy = cv2.cvtColor(colorImg, cv2.COLOR_BGR2BGRA)
    grayColor = cv2.cvtColor(colorImg, cv2.COLOR_BGR2GRAY)

    #blob detect
    params = cv2.SimpleBlobDetector_Params()
    params.maxArea = 500
    params.minArea = 40
    params.minDistBetweenBlobs = 5
    detector = cv2.SimpleBlobDetector_create(params)
    try :
        ret, corners = cv2.findCirclesGrid(grayColor, CHECKERBOARD, cv2.CALIB_CB_SYMMETRIC_GRID, blobDetector=detector)    #For symmetric circle calibration board

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
            # cv2.imshow('Realsense D455', circle_rgb)

            key = cv2.waitKey(3)

            if key & 0xFF == ord("s") :   # save pixel coordinate of thermal camera and RGB camera && thermal and RGB image && sorld coordinate 
            # If RGB and thermal get feature point
                if len(corner_rgb) != 0 :
                    rgbTwoDPoints.append(corner_rgb)
                    print("take picture %s" % index_p)
                    index_p += 1
                
                else : # have not detect the feature point
                    print("Undetect feature point...")
            

            elif key == 27 :  #ESC and save coordinate datas if press Esc
                rgbTwoDPoints
                break
          

    finally :
        # Stop streaming
        pipeline.stop()
        #shutdown thermal camera
        #close all windows
        cv2.destroyAllWindows()
