#include "MyPointFrame.h"

MyPointFrame::MyPointFrame()
{

}

int MyPointFrame::HitTest(int HitX, int HitY)
{
    if( abs(x - HitX) < HitAcceptRange &&
        abs(y - HitY) < HitAcceptRange    )
    {
        bHitFlag = HITTED;
        return bHitFlag;
    }

    bHitFlag = NONE;
    return bHitFlag;
}

void MyPointFrame::ReleaseHitStatus()
{
    bHitFlag = NONE;
}

void MyPointFrame::DragFrame(int HitX, int HitY)
{
    if(bHitFlag!=HITTED) return;
    x = HitX;
    y = HitY;
    return;
}

void MyPointFrame::DrawFrame(Mat& DstMat)
{
    // set frame
    Point FrameP1(this->x - HitAcceptRange, this->y - HitAcceptRange);
    Point FrameP2(this->x + HitAcceptRange, this->y - HitAcceptRange);
    Point FrameP3(this->x + HitAcceptRange, this->y + HitAcceptRange);
    Point FrameP4(this->x - HitAcceptRange, this->y + HitAcceptRange);

    //draw frame
    line(DstMat, FrameP1, FrameP2, Scalar(255,0,0));
    line(DstMat, FrameP2, FrameP3, Scalar(255,0,0));
    line(DstMat, FrameP3, FrameP4, Scalar(255,0,0));
    line(DstMat, FrameP4, FrameP1, Scalar(255,0,0));
    line(DstMat, FrameP1, FrameP3, Scalar(0,255,0));
    line(DstMat, FrameP2, FrameP4, Scalar(0,255,0));

    return;
}
