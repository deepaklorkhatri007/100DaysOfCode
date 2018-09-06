#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;


int main(){
    // 8UC3 8-bit unsigned with 3 channels
    Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
    cout<<M<<endl<<endl;

    Mat L(3,3, CV_8UC(1), Scalar::all(0));
    cout<<L<<endl<<endl;
    
    M.create(4, 4, CV_8UC(1));
    cout<<M<<endl<<endl;    

    Mat O, E, Z;
    O = Mat::ones(4, 4, CV_64F);
    E = Mat::eye(4, 4, CV_32F);
    Z = Mat::zeros(4, 4, CV_8UC1);
    cout<<O<<endl<<endl;
    cout<<E<<endl<<endl;
    cout<<Z<<endl<<endl;

    Mat C = (Mat_<double>(3,3)<< 0, -1, 0, -1, 5, -1, 0, -1, 0);
    cout<<C<<endl<<endl;
    
    C = (Mat_<double>({0, -1, 0, -1, 5, -1, 0, -1, 0})).reshape(3);
    cout<<C<<endl<<endl;

    Mat RowClone = C.row(1).clone();
    cout<<RowClone<<endl<<endl;

    Mat R = Mat(3, 2, CV_8UC3);
    randu(R, Scalar::all(0), Scalar::all(255));
    cout<<R<<endl<<endl;
    cout<<format(R, Formatter::FMT_PYTHON)<<endl<<endl;
    cout<<format(R, Formatter::FMT_C)<<endl<<endl;
    cout<<format(R, Formatter::FMT_CSV)<<endl<<endl;
    cout<<format(R, Formatter::FMT_NUMPY)<<endl<<endl;
    

    Point2f P(5, 1);
    cout<<P<<endl<<endl;
    Point3f P3f(1, 2, 3);
    cout<<P3f<<endl<<endl;

    vector<float> v;
    v.push_back((float)CV_PI);
    v.push_back(2);
    v.push_back(23);
    cout<<Mat(v)<<endl<<endl;

    vector<Point2f> vPoints(10);
    for(int i=0; i<10; i++)
        vPoints[i] = Point2f((float)(i*5), float(i%7));
    cout<<vPoints<<endl<<endl; 
    return 0;
}