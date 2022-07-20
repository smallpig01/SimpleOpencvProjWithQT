#ifndef MYPOINTFRAME_H
#define MYPOINTFRAME_H

#include "MyPoint.h"
#include "opencv2/opencv.hpp"

using namespace cv;

class MyPointFrame : MyPoint
{
public:
    enum HitStatus
    {
        NONE = 0,
        HITTED =1,
    };

public:
    MyPointFrame();
    int HitTest(int HitX, int HitY);
    void ReleaseHitStatus();
    void DragFrame(int HitX, int HitY);
    void DrawFrame(Mat& DstMat);

private:
    HitStatus bHitFlag = NONE;
    int HitAcceptRange = 5;
};

#endif // MYPOINTFRAME_H
