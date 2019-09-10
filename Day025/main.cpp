#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <math.h>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    Mat dark_image = imread("../assets/cloudy.jpg");
    Mat new_dark_image = dark_image.clone();

    double Gamma = 0.4;
    cout<<"Non Linear Transformation"<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Enter Gamma value 0-6.0 : ";cin>>Gamma;

    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();

    for(int i=0; i<256; i++){
        p[i] = saturate_cast<uchar>(pow(i/255.0, Gamma)*255.0);
    }
    LUT(dark_image, lookUpTable, new_dark_image);
    imshow("New image", new_dark_image);
    imshow("Old image", dark_image);
    waitKey();
    return 0;
}
