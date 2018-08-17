#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    float  sigmoid_value, gain, amplify = 50.0;
    cout<<"Enter the value of gain (<=100) : ";
    cin>>gain, amplify;
    for(float x=-5.0; x<=5.0; x+=0.5){
        sigmoid_value = 1.0/(1.0 + exp(-x*gain));
        printf("IN=%6.2f OUT=%6.2f | ", x, sigmoid_value);
        cout<<setw(sigmoid_value*amplify)<<"+"<<endl;
    }
    return 0;
}
