#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;
Mat lenna;
bool applyGray = false;
bool applyBlur = false;
bool applySobel = false;
void grayCallback(int state, void* userData);
void bgrCallback(int state, void* userData);
void sobelCallback(int state, void* userData);
void blurCallback(int state, void* userData);
void applyFilters();
int main(int argc, char const *argv[])
{
    lenna = imread("../assets/lenna.jpg");
    namedWindow("lenna", WINDOW_KEEPRATIO);

    createButton("Blur", blurCallback, NULL, QT_CHECKBOX, 0);
    createButton("RGB", bgrCallback, NULL, QT_RADIOBOX, 1);
    createButton("Gray", grayCallback, NULL, QT_RADIOBOX, 0);
    createButton("Soble", sobelCallback, NULL, QT_PUSH_BUTTON, 0);

    waitKey(0);

    destroyWindow("lenna"); 
    return 0;
}

void grayCallback(int state, void* userData){
    applyGray = true;
    applyFilters();
}
void sobelCallback(int state, void* userData){
    applySobel = !applySobel;
    applyFilters();
}
void blurCallback(int state, void* userData){
    applyBlur = (bool)state;
    applyFilters();
}
void bgrCallback(int state, void* userData){
    applyGray = false;
    applyFilters();
}

void applyFilters(){
    Mat result;
    lenna.copyTo(result);
    if(applyGray){
        cvtColor(result, result, COLOR_RGB2GRAY);
    }
    if(applyBlur){
        blur(result, result, Size(5, 5));
    }
    if(applySobel){
        Sobel(result, result, CV_8U, 1, 1);
    }

    imshow("lenna", result);
}