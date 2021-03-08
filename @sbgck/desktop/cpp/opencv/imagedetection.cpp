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
    static const float GOOD_MATCH_PERCENT = 0.25f;
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
    Log(INFO) << "ImageDetection detectBoard";

    Asset frame(camFrame);

    // TODO: fix this!
    // normalized detection works, but I don't know how to scale the homography up
    // AssetMat normalizedFrame = frame.getNormalized();
    // AssetMat normalizedBoard = board.getNormalized();

    AssetMat normalizedFrame = frame.getDefault();
    AssetMat normalizedBoard = board.getDefault();

    ImageDetection::calculateKeypoints(normalizedFrame);
    ImageDetection::calculateKeypoints(normalizedBoard);

    std::vector<DMatch> matches;
    ImageDetection::calculateMatches(matches, normalizedFrame, normalizedBoard);

#ifdef xxx
    // Draw top matches
    Mat imMatches;
    drawMatches(normalizedFrame.image, normalizedFrame.keypoints, normalizedBoard.image, normalizedBoard.keypoints, matches, imMatches);
    imshow("Good Matches & Object detection", imMatches);
    waitKey();
#endif

    // Extract location of good matches
    std::vector<Point2f> points1, points2;

    for (size_t i = 0; i < matches.size(); i++)
    {
        points1.push_back(normalizedFrame.keypoints[matches[i].queryIdx].pt);
        points2.push_back(normalizedBoard.keypoints[matches[i].trainIdx].pt);
    }

    // Find homography
    Mat h = findHomography(points1, points2, RANSAC);

    Mat imgResult;

    // Use homography to warp image
    warpPerspective(camFrame, imgResult, h, board.getDefault().image.size());

    Asset result(imgResult);
    return result;
}

Rect ImageDetection::detectTemplate(Asset frame, Asset asset)
{
    Log(INFO) << "ImageDetection detectTemplate";

    Rect result;
    return result;
}