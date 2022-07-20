#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int OpenDevice(VideoCapture& cap, int& cam_index, int& res_w, int& res_h);

int main()
{
    // open camera
    VideoCapture cap;
    int cam_index=-1;
    int res_w=1280, res_h=800;
    OpenDevice(cap, cam_index, res_w, res_h);


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

int OpenDevice(VideoCapture& cap, int& cam_index, int& res_w, int& res_h)
{
    int cam_idx_str = 0;
    int cam_idx_end = 10;
    if(cam_index != -1) cam_idx_str = cam_idx_end = cam_index;

    // try open device
    int deviceID = 0;
    int apiID    = CAP_ANY;
    for(int i=cam_idx_str; i<cam_idx_end; ++i)
    {
        cap.open(deviceID, apiID);
        if(cap.isOpened()) break;
    }
    if (!cap.isOpened())
    {
        std::cout << "ERROR! Unable to open camera\n";
        exit(-1);
    }

    //set resolution
    if(res_w != -1 ) cap.set(CAP_PROP_FRAME_WIDTH,  res_w);
    if(res_h != -1 ) cap.set(CAP_PROP_FRAME_HEIGHT, res_h);
    cap.set(CAP_PROP_FRAME_HEIGHT,res_h);
    res_w = cap.get(CAP_PROP_FRAME_WIDTH);
    res_h = cap.get(CAP_PROP_FRAME_HEIGHT);

    // try read image
    int mattype = -1;
    Mat test;
    bool b = cap.read(test);
    if(b==false)
    {
        std::cout << "ERROR! Unable to read image\n";
        exit(-1);
    }

    // print camera info
    res_w = test.cols;
    res_h = test.rows;
    mattype = test.type();

    cout << "deviceID : " << deviceID << endl;
    cout << "res      : " << res_w << " x " << res_h << endl;
    cout << "mat_type : " << mattype << endl;

//    // for opencv camera debug
//    int ret;
//    char* pchar = (char*)&ret;
//    ret = cap.get(CAP_PROP_POS_MSEC);             cout << "CAP_PROP_POS_MSEC             = " << ret << endl;
//    ret = cap.get(CAP_PROP_POS_FRAMES);           cout << "CAP_PROP_POS_FRAMES           = " << ret << endl;
//    ret = cap.get(CAP_PROP_POS_AVI_RATIO);        cout << "CAP_PROP_POS_AVI_RATIO        = " << ret << endl;
//    ret = cap.get(CAP_PROP_FRAME_WIDTH);          cout << "CAP_PROP_FRAME_WIDTH          = " << ret << endl;
//    ret = cap.get(CAP_PROP_FRAME_HEIGHT);         cout << "CAP_PROP_FRAME_HEIGHT         = " << ret << endl;
//    ret = cap.get(CAP_PROP_FPS);                  cout << "CAP_PROP_FPS                  = " << ret << endl;
//    ret = cap.get(CAP_PROP_FOURCC);               cout << "CAP_PROP_FOURCC               = " << ret << " : " << (int)pchar[0] << "," << (int)pchar[1] << "," << (int)pchar[2] << "," << (int)pchar[3] << endl;
//    ret = cap.get(CAP_PROP_FRAME_COUNT);          cout << "CAP_PROP_FRAME_COUNT          = " << ret << endl;
//    ret = cap.get(CAP_PROP_FORMAT);               cout << "CAP_PROP_FORMAT               = " << ret << endl;
//    ret = cap.get(CAP_PROP_MODE);                 cout << "CAP_PROP_MODE                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_BRIGHTNESS);           cout << "CAP_PROP_BRIGHTNESS           = " << ret << endl;
//    ret = cap.get(CAP_PROP_CONTRAST);             cout << "CAP_PROP_CONTRAST             = " << ret << endl;
//    ret = cap.get(CAP_PROP_SATURATION);           cout << "CAP_PROP_SATURATION           = " << ret << endl;
//    ret = cap.get(CAP_PROP_HUE);                  cout << "CAP_PROP_HUE                  = " << ret << endl;
//    ret = cap.get(CAP_PROP_GAIN);                 cout << "CAP_PROP_GAIN                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_EXPOSURE);             cout << "CAP_PROP_EXPOSURE             = " << ret << endl;
//    ret = cap.get(CAP_PROP_CONVERT_RGB);          cout << "CAP_PROP_CONVERT_RGB          = " << ret << endl;
//    ret = cap.get(CAP_PROP_WHITE_BALANCE_BLUE_U); cout << "CAP_PROP_WHITE_BALANCE_BLUE_U = " << ret << endl;
//    ret = cap.get(CAP_PROP_RECTIFICATION);        cout << "CAP_PROP_RECTIFICATION        = " << ret << endl;
//    ret = cap.get(CAP_PROP_MONOCHROME);           cout << "CAP_PROP_MONOCHROME           = " << ret << endl;
//    ret = cap.get(CAP_PROP_SHARPNESS);            cout << "CAP_PROP_SHARPNESS            = " << ret << endl;
//    ret = cap.get(CAP_PROP_AUTO_EXPOSURE);        cout << "CAP_PROP_AUTO_EXPOSURE        = " << ret << endl;
//    ret = cap.get(CAP_PROP_GAMMA);                cout << "CAP_PROP_GAMMA                = " << ret << endl;
//    ret = cap.get(CAP_PROP_TEMPERATURE);          cout << "CAP_PROP_TEMPERATURE          = " << ret << endl;
//    ret = cap.get(CAP_PROP_TRIGGER);              cout << "CAP_PROP_TRIGGER              = " << ret << endl;
//    ret = cap.get(CAP_PROP_TRIGGER_DELAY);        cout << "CAP_PROP_TRIGGER_DELAY        = " << ret << endl;
//    ret = cap.get(CAP_PROP_WHITE_BALANCE_RED_V);  cout << "CAP_PROP_WHITE_BALANCE_RED_V  = " << ret << endl;
//    ret = cap.get(CAP_PROP_ZOOM);                 cout << "CAP_PROP_ZOOM                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_FOCUS);                cout << "CAP_PROP_FOCUS                = " << ret << endl;
//    ret = cap.get(CAP_PROP_GUID);                 cout << "CAP_PROP_GUID                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_ISO_SPEED);            cout << "CAP_PROP_ISO_SPEED            = " << ret << endl;
//    ret = cap.get(CAP_PROP_BACKLIGHT);            cout << "CAP_PROP_BACKLIGHT            = " << ret << endl;
//    ret = cap.get(CAP_PROP_PAN);                  cout << "CAP_PROP_PAN                  = " << ret << endl;
//    ret = cap.get(CAP_PROP_TILT);                 cout << "CAP_PROP_TILT                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_ROLL);                 cout << "CAP_PROP_ROLL                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_IRIS);                 cout << "CAP_PROP_IRIS                 = " << ret << endl;
//    ret = cap.get(CAP_PROP_SETTINGS);             cout << "CAP_PROP_SETTINGS             = " << ret << endl;
//    ret = cap.get(CAP_PROP_BUFFERSIZE);           cout << "CAP_PROP_BUFFERSIZE           = " << ret << endl;
//    ret = cap.get(CAP_PROP_AUTOFOCUS);            cout << "CAP_PROP_AUTOFOCUS            = " << ret << endl;

    return 0;
}
