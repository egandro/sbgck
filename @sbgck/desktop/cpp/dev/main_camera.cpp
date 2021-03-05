#include <opencv2/opencv.hpp>

#include "camera.hpp"

#include "log.hpp"

using namespace cv;

structlog LOGCFG = {};

int main(int argc, char **argv)
{
    LOGCFG.prefix = (char *)"main_camera";
    LOGCFG.headers = true;
    LOGCFG.level = DEBUG;

    if (argc != 3)
    {
        Log(DEBUG) << "usage: " << argv[0] << " <ImageFileOrUrl> <TargetFile>";
        return -1;
    }

    CameraMode mode = DebugFile;

    char *input = strdup(argv[1]);
    for( char *p=input; *p; p++) *p = tolower(*p);
    if(strncmp(input, "http", 4)==0) {
        mode = IPCamera;
    }
    free((void*)input);

    CameraConfig cfg = {
        mode,
        std::string(argv[1])
    };

    Camera *camPtr = new Camera(cfg);

    Mat frame = camPtr->getFrame();

    // namedWindow("Display Image", WINDOW_AUTOSIZE);
    // imshow("Display Image", frame);
    // waitKey(0);

    imwrite(argv[2], frame);

    delete (camPtr);
    camPtr = NULL;

    return 0;
}
