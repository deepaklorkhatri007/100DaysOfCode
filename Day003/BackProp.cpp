// Backpropagation algorithm for XOR problem
#include <iostream>
#include <random>
#include <math.h>
using namespace std;

float w03, w04, w05, w13, w14, w23, w24, w35, w45;
float act3, act4, act5;
float out3, out4, out5;
float cr3, cr4, cr5;
float b, r5, error, mse = 1;

/* The variables:
    w - the weights
    act - the activation levels of the nodes
    out - the outputs of the nodes
    cr - the corrections, multiplied by b
    mse - mean sqared error
    r5 - the correct response (output) from node 5
*/

float sig(float);

int main(int argc, char const *argv[])
{
    int i, in1, in2, iters;
    cout<<"What is the correction factor ? ";
    cin>>b;
    cout<<"How many iterations ? ";
    cin>>iters;

    //random number
    random_device rndm;
    seed_seq seed{{rndm(), rndm(), rndm(), rndm(), rndm()}};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(0, 1000);
    uniform_int_distribution<> dist2(0, 1);

    w03 = dist(eng)/100.0-5.0;
    w04 = dist(eng)/100.0-5.0;
    w05 = dist(eng)/100.0-5.0;
    w13 = dist(eng)/100.0-5.0;
    w14 = dist(eng)/100.0-5.0;
    w23 = dist(eng)/100.0-5.0;
    w24 = dist(eng)/100.0-5.0;
    w35 = dist(eng)/100.0-5.0;
    w45 = dist(eng)/100.0-5.0;
    
    for(i=i; (i<=iters)&&(mse>.01); i++){
        /*stop when the number of iteration
        is too large or when MSE is small*/

        in1 = dist2(eng);
        in2 = dist2(eng);
        act3 = w13*in1 + w23*in2 + w03;
        out3 = sig(act3);
        act4 = w14*in1 + w24*in2 + w04;
        out4 = sig(act4);
        act5 = w35*out3+w45*out4 + w05;
        out5 = sig(act5);
        r5 = in1+in2-2.00*in1*in2;
        error = r5-out5;
        mse = mse+.1*(error*error-mse);

        cr5 = error*out5*(1.0-out5);
        w05 = w05 + b*cr5;
        w35 = w35 + (b*cr5*out3);
        w45 = w45 + (b*cr5*out4);

        cr3 = w35*cr5*out3*(1.0-out3);
        cr4 = w45*cr5*out4*(1.0-out4);

        w03 = w03 + (b*cr3);
        w04 = w04 + (b*cr4);

        w13 = w13 + (b*cr3*in1);
        w14 = w14 + (b*cr4*in1);
        w23 = w23 + (b*cr3*in2);
        w24 = w24 + (b*cr4*in2);

        printf("i = %d input = %d %d output = %10.5f mse = %10.5f\n", i, in1, in2, out5, mse);
    }
    
    printf("\nw03 = %10.5f w13 = %10.5f w23 = %10.5f\n", w03, w13, w23);
    printf("\nw04 = %10.5f w14 = %10.5f w24 = %10.5f\n", w04, w14, w24);
    printf("\nw05 = %10.5f w35 = %10.5f w45 = %10.5f\n", w05, w35, w45);
    
    return 0;
}

float sig(float x){
    float y;
    y = 1.0/(1.0 + exp(-x));
    return(y);
}