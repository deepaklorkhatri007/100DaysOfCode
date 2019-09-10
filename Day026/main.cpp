#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;

int main(int argc, char const *argv[])
{
    Mat lenna = imread("../assets/lenna.jpg");
    imshow("lenna", lenna);
    waitKey();
    return 0;
}


