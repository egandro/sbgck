#ifndef IMAGEDETECTION_H
#define IMAGEDETECTION_H

#include "opencv2/opencv.hpp"
#include "assetmanager.hpp"

using namespace cv;

// RECT: https://cpp.hotexamples.com/examples/cv/Rect/-/cpp-rect-class-examples.html


class ImageDetection
{
public:
    static Asset detectBoard(Mat frame, Asset board);

    static Rect detectTemplate(Asset frame, Asset asset);
};

#endif