#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    float x, y, h, diff;
    cout<<"Enter the value of h : ";
    cin>>h;
    cout<<"The value of h, the change in the input is : "<<h<<endl;
    for(x=-5.0; x<=5.0; x+=0.5){
        y = 1.0/(1.0+exp(-x));
        diff = (1.0/(1.0+exp(x+h)))-y;
        printf("IN = %6.4f OUT = %6.4f increase/h = %6.4f OUT*(1-OUT) = %6.4f\n", x, y, diff/h, y*(1.0-y));
    }
    return 0;
}
