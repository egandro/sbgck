#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include "log.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;

enum DetectorMode
{
    None,
    Feature2D,
    SIFT
};

enum ScaleMode
{
    NotScaled,
    Normalized // max 640x480 - honoring aspect
};

enum ColorMode
{
    Unchanged,
    GreyScale, // COLOR_BGR2GRAY
};

class AssetMat
{
public:
    DetectorMode detector;
    ScaleMode scale;
    ColorMode color;
    Mat image;
    std::vector<KeyPoint> keypoints;
    Mat descriptors;

    AssetMat()
    {
        //Log(INFO) << "AssetMat";
        detector = None;
        scale = NotScaled;
        color = Unchanged;
    }

    AssetMat(const AssetMat &value)
    {
        //Log(INFO) << "AssetMat cctor";
        detector = value.detector;
        scale = value.scale;
        detector = value.detector;
        color = value.color;
        image = Mat(value.image);

        std::vector<KeyPoint> kps = value.keypoints;
        for (std::vector<KeyPoint>::iterator it = kps.begin();
             it != kps.end();
             ++it)
        {
            KeyPoint kp = KeyPoint(*it);
            keypoints.push_back(kp);
        }
    }

    ~AssetMat()
    {
        image.release();
        keypoints.clear();
        descriptors.release();
        //Log(INFO) << "~AssetMat";
    }
};

class Asset
{
public:
    std::string fileName;
    std::list<AssetMat> assetMats;

    Asset() {
        //Log(INFO) << "Asset";
    }

    Asset(const Asset &value)
    {
        //Log(INFO) << "Asset cctor";

        fileName = value.fileName;

        std::list<AssetMat> am = value.assetMats;
        for (std::list<AssetMat>::iterator it = am.begin();
             it != am.end();
             ++it)
        {
            AssetMat am = AssetMat(*it);
            assetMats.push_back(am);
        }
    }

    ~Asset()
    {
        assetMats.clear();
        //Log(INFO) << "~Asset";
    }
};

class AssetManager
{
private:
    static std::list<Asset> boards;
    static std::list<Asset> assets;
    static Asset *currentBoard;

public:
    static Asset addBoard(const char *fileName);
    static Asset addAsset(const char *fileName);

    static Asset *getCurrentBoard()
    {
        return AssetManager::currentBoard;
    }

    static void setCurrentBoard(Asset &value);

    static void release();
};

#endif