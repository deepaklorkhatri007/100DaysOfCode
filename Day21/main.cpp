#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;

#define w 400

void myEllipse(Mat img, double angle);
void filledCircle(Mat img, Point center);


int main(){
    char atom_window[] = "Atom";
    Mat atom_image = Mat::zeros(w, w, CV_8UC3);

    for(int i=0; i<5; i++){
        for(int j=0; j<45; j++){
            myEllipse(atom_image, 90+j);
            myEllipse(atom_image, 0+j);
            myEllipse(atom_image, 45+j);
            myEllipse(atom_image, -45+j);
            filledCircle(atom_image, Point(w/2, w/2));
            imshow(atom_window, atom_image);
            atom_image = Mat::zeros(w, w, CV_8UC3);
            if(waitKey(40)>0) exit(0);
        }
    }
    
    return 0;
}

void myEllipse(Mat img, double angle){
    int thickness = 2;
    int lineType = 8;
      ellipse( img,
       Point( w/2, w/2 ),
       Size( w/4, w/16 ),
       angle,
       0,
       360,
       Scalar( 255, 0, 0 ),
       thickness,
       lineType );
}

void filledCircle(Mat img, Point center){
    circle(img,
    center,
    w/32,
    Scalar(0, 0, 255),
    FILLED,
    LINE_8);
}