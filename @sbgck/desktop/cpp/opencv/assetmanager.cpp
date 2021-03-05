#include <stdlib.h>
#include "assetmanager.hpp"
#include "log.hpp"

std::list<Mat> AssetManager::boards;
std::list<Mat> AssetManager::assets;
Mat AssetManager::currentBoard;

Mat AssetManager::addBoard(const char *fileName)
{
    Log(INFO) << "AssetManager addBoard";

    Mat img = imread(fileName, IMREAD_UNCHANGED);
    AssetManager::boards.push_back(img);
    return img;
}

Mat AssetManager::addAsset(const char *fileName)
{
    Log(INFO) << "AssetManager addAsset";

    Mat img = imread(fileName, IMREAD_UNCHANGED);
    AssetManager::assets.push_back(img);
    return img;
}

void AssetManager::release()
{
    Log(INFO) << "AssetManager release";

    AssetManager::currentBoard.release();

    std::list<Mat>::iterator it;

    for (it = AssetManager::boards.begin(); it != AssetManager::boards.end(); ++it)
    {
        (*it).release();
    }
    AssetManager::boards.clear();

    for (it = AssetManager::assets.begin(); it != AssetManager::assets.end(); ++it)
    {
        (*it).release();
    }
    AssetManager::assets.clear();
}