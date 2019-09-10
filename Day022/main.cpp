#include "main.hpp"

#define stars 1000

int main(){
    Star star[stars];
    
    while(1){
        Mat starField = Mat::zeros(window_height, window_width, CV_8UC3);
        for(int i=0; i<stars; i++){
            star[i].show(starField);
            star[i].update();
        }
        
        imshow("Star Field", starField);
        if(waitKey(.1*stars)>0) exit(0);
    }
    return 0;
}