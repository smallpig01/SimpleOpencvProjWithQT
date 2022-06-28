#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
    // webcam setting
    const int deviceID = 2;
    const int apiID    = cv::CAP_ANY;
    VideoCapture cap;
    cap.open(deviceID, apiID);
    if (!cap.isOpened())
    {
        std::cout << "ERROR! Unable to open camera\n";
        exit(-1);
    }

    // capture webcap
    Mat MyMatColor;
    while(1)
    {
        cap.read(MyMatColor);
        cv::imshow( "MyMatColor", MyMatColor );
        cv::waitKey(30);
    }

    return 0;
}
