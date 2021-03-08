#include "imagedetection.hpp"
#include "log.hpp"

Asset ImageDetection::detectBoard(Mat camFrame, Asset board)
{
    Log(INFO) << "ImageDetection detectBoard";

    Asset frame(camFrame);

    AssetMat normalizedFrame = frame.getNormalized();
    AssetMat normalizedBoard = board.getNormalized();

    imshow("normalizedFrame", normalizedFrame.image);
    imshow("normalizedBoard", normalizedBoard.image);
    waitKey();

    Asset result;
    return result;
}

Rect ImageDetection::detectTemplate(Asset frame, Asset asset)
{
    Log(INFO) << "ImageDetection detectTemplate";

    Rect result;
    return result;
}