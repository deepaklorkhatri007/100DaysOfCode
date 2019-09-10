#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

int main(int argc, char const *argv[])
{
    // Read images
    Mat color = imread("../assets/lenna.jpg");
    Mat gray = imread("../assets/lenna.jpg", 0);

    // Write images
    imwrite("LennaGray.jpg", gray);
    
    // Get same pixel with opencv function
    int myRow = color.cols - 10;
    int myCol = color.rows - 10;

    // Show images
    imshow("Lenna RGB", color);
    imshow("Lenna Gray", gray);

    //Wait for any key press
    waitKey(0);
    return 0;
}
