#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "displayimage.hpp"

using namespace cv;

bool displayImage(const char *fileName)
{
    Mat image;
    image = imread(fileName, 1);
    if (!image.data)
    {
        printf("No image data %s\n", fileName);
        return false;
    }
    printf("displayImage %s\n", fileName);
    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", image);
    waitKey(0);
    return true;
}
