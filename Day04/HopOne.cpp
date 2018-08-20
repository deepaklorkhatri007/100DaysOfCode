// Hopfield network One
#include <iostream>
#include <random>
using namespace std;

#define NUMPTS 8

int main(int argc, char const *argv[])
{
    int ax[NUMPTS + 1], bx[NUMPTS + 1], cx[NUMPTS + 1],
        ay[NUMPTS + 1], by[NUMPTS + 1], cy[NUMPTS + 1],
        x[NUMPTS + 1], y[NUMPTS + 1], t[NUMPTS + 1][NUMPTS + 1];

    /*  The variables x, ax, bx and cx stores the patters
        as 0's and 1's. The variables y, ay, by and cy
        stores the same patterns as -1's and 1's
    */   

    int i, j, k, act, converge;

    cout<<"Type in the patterns like this:\n 0 1 1 1 0 0 1 0\n\n";
    cout<<"Type in the first (A) pattern: \n";
    /*ax*/
    for(i=1; i<=NUMPTS; cin>>ax[i++]);
    cout<<"----------\n";
    for(i=1; i<=NUMPTS; cout<<ax[i++]);
    printf("\n\nType in the second (B) pattern: \n");
    /*bx*/
    for(i=1; i<=NUMPTS; cin>>bx[i++]);
    cout<<"----------\n";
    for(i=1; i<=NUMPTS; cout<<bx[i++]);
    printf("\n\nType in the second (C) pattern: \n");
    /*cx*/
    for(i=1; i<=NUMPTS; cin>>cx[i++]);
    cout<<"----------\n";
    for(i=1; i<=NUMPTS; cout<<cx[i++]);
    printf("\n\nType in the second (X) pattern: \n");
    /*x*/
    for(i=1; i<=NUMPTS; cin>>x[i++]);
    cout<<"----------\n";
    for(i=1; i<=NUMPTS; cout<<x[i++]);
    printf("\n");

    for(i=1; i<=NUMPTS; i++){
        ay[i] = 2*ax[i] - 1;
        by[i] = 2*bx[i] - 1;
        cy[i] = 2*cx[i] - 1;
        y[i] = 2*x[i] - 1;
    }

    for(i=1; i<=NUMPTS; i++){
        for(j=i; j<=NUMPTS; j++){
            if(j==i) t[i][j] = 0;
            else{
                t[i][j] = ay[i]*ay[j] + by[i]*by[j] + cy[i]*cy[j];
                t[j][i] = t[i][j];
            }
        }
    }

    cout<<"\nNow revising pattern....\n";

    /*randomply revise nodes*/
    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(1, 8);

    converge = 0;

    while(!converge){
        i = dist(eng);
        act = 0;
        for(j = 1; j<=NUMPTS; j++) act += t[i][j]*y[j];
        y[i] = 2*(act>=0)-1;
        /* +1 if act>=0, -1 otherwise*/

        for(j=1; j<=NUMPTS; cout<<(y[j++]>0));
        cout<<".... i = "<<i<<endl;
        converge = 1;
        for(k=1; k<=NUMPTS; k++){
            act = 0;
            for(j=1; j<=NUMPTS; j++) act += t[j][k]*y[j];
            converge *= (y[k]==(2*(act>=0)-1)); /*reverse flag*/
        }
    }

    cout<<"The final pattern is \n";
    for(i=1; i<=NUMPTS; cout<<(y[i++]>0));
    cout<<endl;
    return 0;
}
