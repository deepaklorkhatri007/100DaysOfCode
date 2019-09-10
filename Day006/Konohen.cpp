#include <iostream>
#include <random>
#include <math.h>
using namespace std;

float w[3][144], w1, w2, testx, testy, dst, bestdst;
int i, j, k, besti = 0, bestj = 0;
char c;
int index(int i, int j);
void normalize(float *x, float *y);

int main(int argc, char const *argv[])
{
    cout<<"Please wait. This takes a while."<<endl;

    /*random number generation*/
    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(0, 999);
    uniform_int_distribution<> dist2(0, 1);

    for(j=0; j<144; j++){
        w1 = dist(eng)/1000.0 - 0.5;
        w2 = dist(eng)/1000.0 - 0.5;

        normalize(&w1, &w2);
        w[1][j] = w1;
        w[2][j] = w2;
    }

    /*adjust weights*/
    for(k=1; k<=100; k++){
        testx = 0;
        testy = 0;
        while(testx + testy == 0){
            testx = 3*dist2(eng) + dist(eng)/1000.00 - 0.5;
            testy = 3*dist(eng) + dist(eng)/1000.00 - 0.5;
        }
        
        normalize(&testx, &testy);
        for(i=1; i<3; i++){
            for(j=1; j<=10; j++){
            dst = 2-2*(testx*w[1][index(i, j)] + testy*w[2][index(i, j)]);
            if(dst<1) c = '*';
            else c = '-';
            cout<<c;
            } /*end j loop*/
            cout<<"\n";
        }
    }
    return 0;
}

int index(int i, int j){
    int k;
    k = 12*i + j;
    return(k);
} /*end of index function*/

void normalize(float *x, float *y){
    float dst;
    dst = sqrt(*x**x + *y**y);
    *x = *x/dst;
    *y = *y/dst;
} /*end normalize*/
