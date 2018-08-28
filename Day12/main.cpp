#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

// OPenCV command line parser functions
// Keys accepted by command line parser

const char* keys = {
    "{help h usage ? | | print this message}"
    "{@video | | Video file, if not defined try to use webcamera}"
};

int main(int argc, char const *argv[])
{
    CommandLineParser parser(argc, argv, keys);
    parser.about("Program v1.0.0");

    //If requires help show
    if(parser.has("help")){
        parser.printMessage();
        return 0;
    }
    String videoFile = parser.get<String> (0);

    // Checking
    if(!parser.check()){
        parser.printErrors();
        return 0;
    }

    VideoCapture cap; //open the default camera
    if(videoFile != ""){
        cap.open(videoFile);
    } else {
        cap.open(0);
    }

    if(!cap.isOpened()) // check if we succeeded
        return -1;

    namedWindow("Video", 1);
    for(;;){
        Mat frame;
        cap>>frame;
        imshow("Video", frame);
        if(waitKey(30) >= 0) break;
    }
    // Release the camera or video cap
    cap.release();
    return 0;
}