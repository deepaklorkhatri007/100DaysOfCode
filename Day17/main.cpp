#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
using namespace std;
using namespace cv;

int main(){
    double y[1000]; 
    int x;

    for(x=0; x<1000; x++){
        y[x] = 100 + 20*sin(0.4*.1*M_PI*x);
    }

    IplImage *grf = cvCreateImage(cvSize(200, 200), IPL_DEPTH_8U, 1);

    for(x=0; x<1000; x++){
        cvLine(grf, cvPoint(x, y[x]), cvPoint(x+1, y[x+1]), CV_RGB(255, 255, 255), 2, 4, 0);
    }

    cvNamedWindow("sine", CV_WINDOW_KEEPRATIO);
    cvShowImage("sine", grf);
    cvWaitKey(0);
    cvDestroyWindow("sine");
    cvReleaseImage(&grf);
    return 0;
}