#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

int main(){
    Mat lenna = imread("../assets/lenna.jpg");
    Mat new_lenna = Mat::zeros(lenna.size(), lenna.type());
    double Alpha = 1.0; // contrast
    int Beta = 0;   // brightness
    
    cout<<"Basic Linear Transforms"<<endl;
    cout<<"......................."<<endl;
    cout<<"Enter the Alpha (contrast) value [1.0 - 3.0] : "; cin>>Alpha;
    cout<<"Enter the Beta (brightness) value [0-100] : "; cin>>Beta;

    for(int y=0; y<lenna.rows; y++){
        for(int x=0; x<lenna.cols; x++){
            for(int c=0; c<lenna.channels(); c++){
                new_lenna.at<Vec3b>(y,x)[c] =
                saturate_cast<uchar>(Alpha*lenna.at<Vec3b>(y,x)[c] + Beta); // new = Alpha*old + Beta
            }
        }
    }

    imshow("Orignal lenna", lenna);
    imshow("New lenna", new_lenna);
    waitKey(0);
    return 0;
}