#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

//#include "log.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

class Asset {
    public:
    std::string fileName;
    Mat material;

    Asset() {}

    Asset(const Asset &value) {
        fileName = value.fileName;
        material = value.material;
    }

    ~Asset() {
        material.release();
        //Log(DEBUG) << "~Asset";
    }
};

class AssetManager
{
private:
    static std::list<Asset> boards;
    static std::list<Asset> assets;
    static Asset *currentBoard;

public:
    static Asset& addBoard(const char *fileName);
    static Asset& addAsset(const char *fileName);

    static Asset * getCurrentBoard() {
        return AssetManager::currentBoard;
    }

    static void setCurrentBoard(Asset& value);

    static void release();
};

#endif