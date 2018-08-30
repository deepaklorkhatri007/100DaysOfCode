#include <iostream>
#include <string>
#include <sstream>
using namespace std;
// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;


int main( int argc, const char** argv )
{
// Read images
Mat lena= imread("../assets/lenna.jpg");
Mat photo= imread("../assets/puppies.jpg");
// Create windows
namedWindow("Lena", CV_GUI_NORMAL);
namedWindow("Photo", CV_GUI_NORMAL);
// Move window
moveWindow("Lena", 10, 10);
moveWindow("Photo", 520, 10);
// show images
imshow("Lena", lena);
imshow("Photo", photo);
// Resize window, only non autosize
resizeWindow("Lena", 512, 512);
// wait for any key press
waitKey(0);
destroyWindow("Lena");
destroyWindow("Photo");
// Create 10 windows
for(int i =0; i< 10; i++)
{
ostringstream ss;
ss << "Photo " << i;
namedWindow(ss.str(), CV_GUI_NORMAL);
moveWindow(ss.str(), 20*i, 20*i);
imshow(ss.str(), photo);
}
waitKey(0);
// Destroy all windows
destroyAllWindows();
return 0;
}

