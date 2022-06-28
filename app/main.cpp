#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main()
{
    // open camera
    int cam_index = 0;
    VideoCapture cap = VideoCapture(cam_index);

    // capture webcap
    Mat img;
    while(1)
    {
        cap.read(img);
        cv::imshow( "img", img );

        // escape
        if( cv::waitKey(30) == 27 ) //'escape key'
            return 0; 
    }

    return 0;
}
