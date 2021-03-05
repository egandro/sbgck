#include <opencv2/opencv.hpp>

#include "displayimage.hpp"
#include "version.hpp"

#include "log.hpp"

using namespace cv;

structlog LOGCFG = {};

int main(int argc, char **argv)
{
    LOGCFG.headers = false;
    LOGCFG.level = DEBUG;

    if (argc != 2)
    {
        Log(DEBUG) << "usage: " << argv[0] << " <Image_Path>";

        return -1;
    }

    Log(DEBUG) << "opencv version: " << getOpenCVVersion();

    if (!displayImage(argv[1]))
    {
        return -1;
    }
    return 0;
}
