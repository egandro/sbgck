#ifndef IMAGEDETECTION_H
#define IMAGEDETECTION_H

#include "opencv2/opencv.hpp"

using namespace cv;

class ImageDetection
{
public:
    static void detectTemplate(Mat frame, Mat templateImage);
};

#endif