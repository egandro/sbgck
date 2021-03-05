#include <stdio.h>
#include <opencv2/opencv.hpp>

#include "displayimage.hpp"
#include "version.hpp"

using namespace cv;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("usage: %s <Image_Path>\n", argv[0]);
        return -1;
    }

    printf("opencv version: %s\n", getOpenCVVersion());

    if (!displayImage(argv[1]))
    {
        return -1;
    }

    waitKey(0);
    return 0;
}
