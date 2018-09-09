#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <random>
using namespace std;
using namespace cv;

#define window_height 500
#define window_width 500

float randomNumber(float x, float y){
    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(x, y);
    return dist(eng);
}

float map(float value,
    float start1, float stop1,
    float start2, float stop2) {
    float outgoing = start2 + (stop2 - start2) * ((value - start1) / (stop1 - start1));
    return outgoing;
    }

Mat translateImg(Mat &img, int offsetx, int offsety){
    Mat trans_mat = (Mat_<double>(2,3) << 1, 0, offsetx, 0, 1, offsety);
    warpAffine(img,img,trans_mat,img.size());
    return trans_mat;
}


class Star {
    float x, y, z;
    public:
    Star();
    void update();
    void show(Mat input);
};

Star::Star(){
    x = randomNumber(-window_width, window_width);
    y = randomNumber(-window_height, window_height);
    z = window_width;
}

void Star::update(){
    z = z - randomNumber(-1, 1);
}

void Star::show(Mat input){
    float sx = map(x/z, 0, 1, 0, window_width);
    float sy = map(y/z, 0, 1, 0, window_height);
    circle(input, Point(sx, sy), 2*(window_width/100+window_height/100)/10, Scalar(randomNumber(0, 255), randomNumber(0, 255), randomNumber(0, 255)), FILLED, LINE_8);
    
}