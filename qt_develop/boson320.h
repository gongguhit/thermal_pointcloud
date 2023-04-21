#ifndef FUSION_BOSON320_H
#define FUSION_BOSON320_H

#include "dependencies.h"

#define YUV   0
#define RAW16 1

using namespace cv;
using namespace std;

#define v_major 1
#define v_minor 0

// Define COLOR CODES
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

// Global variables to keep this simple
int width;
int height;

// Types of sensors supported
enum sensor_types {
    Boson320, Boson640
};

/* ---------------------------- 16 bits Mode auxiliary functions ---------------------------------------*/
// AGC Sample ONE: Linear from min to max.
// Input is a MATRIX (height x width) of 16bits. (OpenCV mat)
// Output is a MATRIX (height x width) of 8 bits (OpenCV mat)
void AGC_Basic_Linear(Mat input_16, Mat output_8, int height, int width) {
    int i, j;  // aux variables

    // auxiliary variables for AGC calcultion
    unsigned int max1=0;         // 16 bits
    unsigned int min1=0xFFFF;    // 16 bits
    unsigned int value1, value2, value3, value4;

    // RUN a super basic AGC
    for (i=0; i<height; i++) {
        for (j=0; j<width; j++) {
            value1 =  input_16.at<uchar>(i,j*2+1) & 0XFF ;  // High Byte
            value2 =  input_16.at<uchar>(i,j*2) & 0xFF  ;    // Low Byte
            value3 = ( value1 << 8) + value2;
            if ( value3 <= min1 ) {
                min1 = value3;
            }
            if ( value3 >= max1 ) {
                max1 = value3;
            }
            //printf("%X.%X.%X  ", value1, value2, value3);
        }
    }
    //printf("max1=%04X, min1=%04X\n", max1, min1);

    for (int i=0; i<height; i++) {
        for (int j=0; j<width; j++) {
            value1 =  input_16.at<uchar>(i,j*2+1) & 0XFF ;  // High Byte
            value2 =  input_16.at<uchar>(i,j*2) & 0xFF  ;    // Low Byte
            value3 = ( value1 << 8) + value2;
            value4 = ( ( 255 * ( value3 - min1) ) ) / (max1-min1)   ;
            // printf("%04X \n", value4);

            output_8.at<uchar>(i,j)= (uchar)(value4&0xFF);
        }
    }

}


#endif //FUSION_BOSON320_H
