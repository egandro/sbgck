#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "opencv2/opencv.hpp"

using namespace cv;

class AssetManager
{
private:
    static std::list<Mat> boards;
    static std::list<Mat> assets;
    static Mat currentBoard;

public:
    static Mat addBoard(const char *fileName);
    static Mat addAsset(const char *fileName);

    static Mat getCurrentBoard() {
        return AssetManager::currentBoard;
    }

    static void setCurrentBoard(Mat value){
        AssetManager::currentBoard = value;
    }

    static void release();
};

#endif