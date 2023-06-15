##=====================================================================================================##
## This program is to use world coordinate and thermal RGB coordinate to get extrinsics and intrinsics ##
##=====================================================================================================##

import numpy as np
import cv2

# Define the dimensions of checkerboard 
CHECKERBOARD = (7, 5) 

# Fake 3D point to get intrinsics
fakeThreeDPoint = []
objectp3d = np.zeros((1, CHECKERBOARD[0] * CHECKERBOARD[1], 3), np.float32) 
objectp3d[0, :, :2] = 70*np.mgrid[0:CHECKERBOARD[0], 0:CHECKERBOARD[1]].T.reshape(-1, 2) 
# print(objectp3d)
for each_pic in range(55) : ## the image number
    fakeThreeDPoint.append(objectp3d)
fakeThreeDPoint = np.array(fakeThreeDPoint)

# load feature point data
thermalPixelCoordinate = np.load("/home/gg/Downloads/calibration/test_data_2/boson_pixel_coordinate.npy")
rgbPixelCoordinate = np.load("/home/gg/Downloads/calibration/test_data_2/RGB_boson_pixel_coordinate.npy")

# load image & image size
rgbImage = cv2.imread('/home/gg/Downloads/calibration/test_data_2/RealSense_RGB0.png')
rgbImage = cv2.cvtColor(rgbImage, cv2.COLOR_BGR2GRAY)   #graylize
thermalImage = cv2.imread('/home/gg/Downloads/calibration/test_data_2/boson0.png')
thermalImage = cv2.cvtColor(thermalImage, cv2.COLOR_BGR2GRAY)   #graylize
rgbShape = rgbImage.shape[::-1]
thermalShape = thermalImage.shape[::-1]

## calibrate rgb and thermal intrinsics, get fake extrinsics
rgbRet, rgbMatrix, rgbDistort, fakeRgbR_vecs, fakeRgbT_vecs = cv2.calibrateCamera( fakeThreeDPoint, rgbPixelCoordinate, rgbShape, None, None)
thermalRet, thermalMatrix, thermalDistort, fakeThermalR_vecs, fakeThermalT_vecs = cv2.calibrateCamera( fakeThreeDPoint, thermalPixelCoordinate, thermalShape, None, None)

# ## using intrinsics calibrate RGB and Thermal extrinsics, get real extrinsics
# ErgbRet, ErgbMatrix, ErgbDistort, rgbR_vecs, rgbT_vecs = cv2.calibrateCamera( threeDPoint, rgbPixelCoordinate, rgbShape, rgbMatrix,rgbDistort ,flags=(cv2.CALIB_USE_INTRINSIC_GUESS + cv2.CALIB_FIX_PRINCIPAL_POINT))
# EthermalRet, EthermalMatrix, EthermalDistort, thermalR_vecs, thermalT_vecs = cv2.calibrateCamera( threeDPoint, thermalPixelCoordinate, thermalShape,thermalMatrix,thermalDistort, flags=(cv2.CALIB_USE_INTRINSIC_GUESS + cv2.CALIB_FIX_PRINCIPAL_POINT))

## using stereo camera calibration to get 
# config
flags = 0
#flags |= cv2.CALIB_FIX_ASPECT_RATIO
flags |= cv2.CALIB_USE_INTRINSIC_GUESS
#flags |= cv2.CALIB_SAME_FOCAL_LENGTH
#flags |= cv2.CALIB_ZERO_TANGENT_DIST
flags |= cv2.CALIB_RATIONAL_MODEL
#flags |= cv2.CALIB_FIX_K1
#flags |= cv2.CALIB_FIX_K2
#flags |= cv2.CALIB_FIX_K3
#flags |= cv2.CALIB_FIX_K4
#flags |= cv2.CALIB_FIX_K5
#flags |= cv2.CALIB_FIX_K6
stereocalib_criteria = (cv2.TERM_CRITERIA_COUNT + cv2.TERM_CRITERIA_EPS, 100, 1e-5)

ret, M1, d1, M2, d2, R, T, E, F = cv2.stereoCalibrate(fakeThreeDPoint, rgbPixelCoordinate,thermalPixelCoordinate, rgbMatrix,rgbDistort,thermalMatrix,thermalDistort,rgbShape, criteria=stereocalib_criteria, flags=flags)
print("ret",ret)
print("R",R)
print("T",T)
print("E",E)
print("F",F)

relative_R = np.array(R)
relative_T = np.array(T)
essential_M = np.array(E)
fund_M = np.array(F)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Ralative_rotation_matrix.npy",relative_R)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Ralative_translation_matrix.npy",relative_T)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Essential_matrix.npy",essential_M)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Fundation_matrix.npy",fund_M)

## store camera intrinsics, distortion, extrinsics
# store orbbec RGB data
rgbIntrinsic = np.array(rgbMatrix)
rgbDistortion = np.array(rgbDistort)
rgbFakeRotation = np.array(fakeRgbR_vecs)
rgbFakeTranslation = np.array(fakeRgbT_vecs)
print(rgbIntrinsic)
print(rgbDistortion)
# print(rgbFakeRotation)
# print(rgbFakeTranslation)
# rgbRealRotation = np.array(rgbR_vecs)
# rgbRealTranslation = np.array(rgbT_vecs)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_RGB_intrinsic.npy",rgbIntrinsic)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_RGB_distortion.npy",rgbDistortion)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_RGB_fake_rotation.npy",rgbFakeRotation)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_RGB_fake_translation.npy",rgbFakeTranslation)
# np.save("/home/tanhaozhang/Desktop/pyProg/data/RGB_real_rotation.npy",rgbRealRotation)
# np.save("/home/tanhaozhang/Desktop/pyProg/data/RGB_real_translation.npy",rgbRealTranslation)

# store thermal camera data
thermalIntrinsic = np.array(thermalMatrix)
thermalDistortion = np.array(thermalDistort)
thermalFakeRotation = np.array(fakeThermalR_vecs)
thermalFakeTranslation = np.array(fakeThermalT_vecs)
print(thermalIntrinsic)
print(thermalDistortion)
# thermalRealRotation = np.array(thermalR_vecs)
# thermalRealTranslation = np.array(thermalT_vecs)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Thermal_intrinsic.npy",thermalIntrinsic)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Thermal_distortion.npy",thermalDistortion)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Thermal_fake_rotation.npy",thermalFakeRotation)
np.save("/home/gg/Downloads/calibration/test_data_2/boson_realsense_Thermal_fake_translation.npy",thermalFakeTranslation)
# np.save("/home/tanhaozhang/Desktop/pyProg/data/Thermal_real_rotation.npy",thermalRealRotation)
# np.save("/home/tanhaozhang/Desktop/pyProg/data/Thermal_real_translation.npy",thermalRealTranslation)
print("Finish...")
