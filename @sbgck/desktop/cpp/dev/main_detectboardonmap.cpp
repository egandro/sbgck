#include <opencv2/opencv.hpp>

#include "assetmanager.hpp"
#include "camera.hpp"
#include "imagedetection.hpp"

#include "log.hpp"

using namespace cv;

structlog LOGCFG = {};

int main(int argc, char **argv)
{
    LOGCFG.prefix = (char *)"main_camera";
    LOGCFG.headers = true;
    LOGCFG.level = DEBUG;

    if (argc != 4)
    {
        Log(DEBUG) << "usage: " << argv[0] << " <ImageFileOrUrl> <BoardFile> <OutFile>";
        return -1;
    }

    Asset board = AssetManager::addBoard(argv[2]);
    AssetManager::setCurrentBoard(board);

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

    Camera camPtr(cfg);
    Mat mat = camPtr.getFrame();
    Asset frame = Asset(mat);

    Asset detectedBoard = ImageDetection::detectBoard(mat, (*AssetManager::getCurrentBoard()));

    imshow("Good Matches & Object detection", detectedBoard.getDefault().image);
    waitKey();

   // imwrite(argv[3], frame);
    return 0;
}
