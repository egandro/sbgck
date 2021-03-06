#include <stdlib.h>
#include "assetmanager.hpp"
#include "log.hpp"

std::list<Asset> AssetManager::boards;
std::list<Asset> AssetManager::assets;
Asset *AssetManager::currentBoard = NULL;

Asset AssetManager::addBoard(const char *fileName)
{
    Log(INFO) << "AssetManager addBoard";

    for (std::list<Asset>::iterator it = AssetManager::boards.begin();
         it != AssetManager::boards.end();
         ++it)
    {
        if (strncmp((*it).fileName.c_str(), fileName, (*it).fileName.length()) == 0)
        {
            Log(INFO) << "already have that board " << fileName;
            return (*it);
        }
    }

    Log(INFO) << "AssetManager added board " << fileName;

    Asset asset;
    asset.fileName = std::string(fileName);
    AssetManager::boards.push_back(asset);

    AssetMat mat;
    mat.image = imread(fileName, IMREAD_UNCHANGED);
    asset.assetMats.push_back(mat);

    return asset;
}

Asset AssetManager::addAsset(const char *fileName)
{
    Log(INFO) << "AssetManager addAsset";

    for (std::list<Asset>::iterator it = AssetManager::assets.begin();
         it != AssetManager::assets.end();
         ++it)
    {
        if (strncmp((*it).fileName.c_str(), fileName, (*it).fileName.length()) == 0)
        {
            Log(INFO) << "already have that asset " << fileName;
            return (*it);
        }
    }

    Asset asset;
    asset.fileName = std::string(fileName);
    AssetManager::assets.push_back(asset);

    AssetMat mat;
    mat.image = imread(fileName, IMREAD_UNCHANGED);
    asset.assetMats.push_back(mat);

    return asset;
}

void AssetManager::setCurrentBoard(Asset &value)
{
    Log(INFO) << "AssetManager setCurrentBoard";

    AssetManager::currentBoard = NULL;

    for (std::list<Asset>::iterator it = AssetManager::boards.begin();
         it != AssetManager::boards.end();
         ++it)
    {
        if (strncmp((*it).fileName.c_str(), value.fileName.c_str(), value.fileName.length()) == 0)
        {
            AssetManager::currentBoard = &(*it);
            Log(INFO) << "AssetManager current board is now " << value.fileName;
            return;
        }
    }

    Log(DEBUG) << "Asset is no board";
}

void AssetManager::release()
{
    Log(INFO) << "AssetManager release";

    AssetManager::currentBoard = NULL;
    AssetManager::boards.clear();
    AssetManager::assets.clear();
}