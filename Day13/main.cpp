#include <iostream>
using namespace std;

// OpenCV
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;


int main(int argc, char const *argv[])
{
    // create our writer
    FileStorage fs("test.yml", FileStorage::WRITE);
    // Save an int
    int fps = 5;
    fs << "fps" <<fps;
    // Create some mat samples
    Mat m1 = Mat::eye(2, 3, CV_32F);
    Mat m2 = Mat::eye(3, 2, CV_32F);
    Mat result = (m1+1).mul(m1+3);
    // write the result
    fs<<"Result"<<result;
    // release the file
    fs.release();

    FileStorage fs2("test.yml", FileStorage::READ);

    Mat r;
    fs2["Result"] >> r;
    cout<<r<<endl;
    fs2.release();

    // Mat zeros = Mat::zeros(5,5, CV_32F);
    // Mat eye = Mat::eye(5, 5, CV_32F);
    // Mat ones = Mat::ones(5, 5, CV_32F);
    // Mat a = ones+eye;
    // Mat b = a*eye;
    // Mat d = b.t();
    // Mat e = b.inv();
    // cout<<d<<endl<<"\n\n";
    // cout<<e<<endl<<"\n\n";
    return 0;
}
