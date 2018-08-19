// Simple McPitts neuron model
#include<iostream>
#include<iomanip>
using namespace std;

int x1, x2, out; // inputs and output
float w1, w2, T; // wieghts and threshold

int main(int argc, char const *argv[])
{
    cout<<"Enter Weight w1 : ";
    cin>>w1;
    cout<<"Enter Weight w2 : ";
    cin>>w2;
    cout<<"Enter Threshold T : ";
    cin>>T;

    cout<<setw(11)<<"X1"<<setw(10)<<"X2"<<setw(12)<<"Output"<<endl;
    for(x1=0; x1<2; x1++){
        for(x2=0; x2<2; x2++){
            out = (w1*x1 + w2*x2 >= T);
            cout<<setw(10)<<x1<<setw(10)<<x2<<setw(10)<<out<<endl;
        }
    }
    return 0;
}
