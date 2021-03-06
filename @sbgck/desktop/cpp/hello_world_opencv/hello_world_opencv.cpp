#include <stdio.h>

#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc, char** argv) {

    printf("open cv version: %s\n", CV_VERSION);

#ifdef XXX
    //create a gui window:
    namedWindow("Output",1);

    //initialize a 120X350 matrix of black pixels:
    Mat output = Mat::zeros( 120, 350, CV_8UC3 );

    //write text on the matrix:
    putText(output,
            "Hello World :)",
            cv::Point(15,70),
            FONT_HERSHEY_PLAIN,
            3,
            cv::Scalar(0,255,0),
            4);

    //display the image:
    imshow("Output", output);

    //wait for the user to press any key:
    waitKey(0);
#endif
    return 0;

}