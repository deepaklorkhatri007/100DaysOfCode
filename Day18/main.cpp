#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

int main(){
    //create just the header parts
    Mat A, C;   
    //here we'll know the method used (allocate matrix)
    A = imread("../assets/lenna.jpg");    
    //use the copy constructor
    Mat B(A);   
    //Assignment operator
    C = A;      
    
    // Region of intrest (roi)
    // using a rectangle 
    Mat D (A, Rect(10, 10, 100, 100));
    // using row and column boundaries
    Mat E = A(Range::all(), Range(1, 10));
    
    Mat F = A.clone();
    Mat G;
    A.copyTo(G);


    namedWindow("lenna");
    imshow("lenna", E);
    waitKey(0);
    return 0;
}