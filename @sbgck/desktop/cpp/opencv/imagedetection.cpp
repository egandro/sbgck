#include "imagedetection.hpp"
#include "log.hpp"

DetectorMode ImageDetection::detectorMode = DM_Feature2D;
//DetectorMode ImageDetection::detectorMode = DM_SIFT;

void ImageDetection::calculateKeypoints(AssetMat & am)
{
    if (detectorMode == DM_Feature2D)
    {
        calculateKeypointsFeature2D(am);
    }
    else if (detectorMode == DM_SIFT)
    {
        calculateKeypointsSIFT(am);
    }
}

void ImageDetection::calculateKeypointsFeature2D(AssetMat & am)
{
    // https://www.programmersought.com/article/18095237159/
    static const int MAX_FEATURES = 1500;
    static Ptr<Feature2D> detector = ORB::create(MAX_FEATURES);

    detector->detectAndCompute(am.image, Mat(), am.keypoints, am.descriptors);
}

void ImageDetection::calculateKeypointsSIFT(AssetMat & am)
{
    static Ptr<SIFT> detector = SIFT::create();
    detector->detectAndCompute(am.image, Mat(), am.keypoints, am.descriptors);
}

void ImageDetection::calculateMatches(std::vector<DMatch> &matches, const AssetMat &frame, const AssetMat &tpl)
{
    if (detectorMode == DM_Feature2D)
    {
        calculateMatchesFeature2D(matches, frame, tpl);
    }
    else if (detectorMode == DM_SIFT)
    {
        calculateMatchesSIFT(matches, frame, tpl);
    }
}

void ImageDetection::calculateMatchesFeature2D(std::vector<DMatch> &matches, const AssetMat &frame, const AssetMat &tpl)
{
    // https://learnopencv.com/image-alignment-feature-based-using-opencv-c-python/
    static const float GOOD_MATCH_PERCENT = 0.15f;
    static Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");

    matcher->match(frame.descriptors, tpl.descriptors, matches, Mat());

    // Sort matches by score
    std::sort(matches.begin(), matches.end());

    // Remove not so good matches
    const int numGoodMatches = (int)(matches.size() * GOOD_MATCH_PERCENT);
    matches.erase(matches.begin() + numGoodMatches, matches.end());
}

void ImageDetection::calculateMatchesSIFT(std::vector<DMatch> &matches, const AssetMat &frame, const AssetMat &tpl)
{
    static const float GOOD_MATCH_PERCENT = 0.30f;
    static Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);

    matcher->match(frame.descriptors, tpl.descriptors, matches, Mat());

    // Sort matches by score
    std::sort(matches.begin(), matches.end());

    // Remove not so good matches
    const int numGoodMatches = (int)(matches.size() * GOOD_MATCH_PERCENT);
    matches.erase(matches.begin() + numGoodMatches, matches.end());
}

Asset ImageDetection::detectBoard(Mat camFrame, Asset board)
{
    // https://learnopencv.com/feature-based-image-alignment-using-opencv-c-python/

    Log(INFO) << "ImageDetection detectBoard";

    Asset frame(camFrame);

    AssetMat downscaleFrame = frame.getScaled();

    // do a proportioned scaled version of the board (relative to the frame)
    double scaleFactor = (double)board.getDefault().image.size().width / (double)frame.getDefault().image.size().width;
    double size = (double) DEFAULT_SCALE_WIDTH * scaleFactor;

    AssetMat downscaleBoard = board.getScaled(size);

    ImageDetection::calculateKeypoints(downscaleFrame);
    ImageDetection::calculateKeypoints(downscaleBoard);

    std::vector<DMatch> matches;
    ImageDetection::calculateMatches(matches, downscaleFrame, downscaleBoard);

#ifdef xxx
    // Draw top matches
    Mat imMatches;
    drawMatches(downscaleFrame.image, downscaleFrame.keypoints, downscaleBoard.image, downscaleBoard.keypoints, matches, imMatches);
    imshow("Good Matches & Object detection", imMatches);
    waitKey();
#endif

    // Extract location of good matches
    std::vector<Point2f> points1, points2;

    double scaleUp1 = (double)1.0 / (double)downscaleFrame.scaleFactor;
    double scaleUp2 = (double)1.0 / (double)downscaleBoard.scaleFactor;

    for (size_t i = 0; i < matches.size(); i++)
    {
        // upscale the points relative to the original frame and board
        Point2f p;

        p = downscaleFrame.keypoints[matches[i].queryIdx].pt;
        p.x *= scaleUp1;
        p.y *= scaleUp1;
        points1.push_back(p);

        p = downscaleBoard.keypoints[matches[i].trainIdx].pt;
        p.x *= scaleUp2;
        p.y *= scaleUp2;
        points2.push_back(p);

#ifdef xxx
        // this was the original idea
        points1.push_back(downscaleFrame.keypoints[matches[i].queryIdx].pt);
        points2.push_back(downscaleBoard.keypoints[matches[i].trainIdx].pt);
#endif
    }

    // Find homography
    Mat h = findHomography(points1, points2, RANSAC);

    Mat imgResult;

    // Use homography to warp image
    warpPerspective(camFrame, imgResult, h, board.getDefault().image.size());

    // Print estimated homography
    // Log(INFO) <<  "Estimated homography : \n" << h;

    Asset result(imgResult);
    return result;
}

Rect ImageDetection::detectTemplate(Asset frame, Asset asset)
{
    Log(INFO) << "ImageDetection detectTemplate";

    Rect result;
    return result;
}