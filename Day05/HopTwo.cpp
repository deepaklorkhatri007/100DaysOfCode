// Hopfield Network problem
#include <iostream>
#include <random>
#include <math.h>
using namespace std;

float sig(float);

int main(){
    float m[5][5], act, bigm = -100, sum = 0.0;
    int x[5][5], i1, i2, j1, j2, i, j, k;

    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(0, 1);
    uniform_int_distribution<> dist2(1, 4);
    cout<<"Type in the rows of cost like this";
    cout<<"12 13.6 16 23.1";

    /*get costs and initialize nodes*/
    for(i=1; i<5; i++){
        cout<<"What are the costs for row "<<i<<endl;
        for(j=1; j<5; j++){
            cin>>m[i][j];
            if(m[i][j]>bigm) bigm = m[i][j];
            x[i][j] = dist(eng); /*initialize node randomly*/
        }
    }

    /*randomly update nodes*/
    for(k=1; k<=250; k++){
        i1 = dist2(eng);
        j1 = dist2(eng);

        printf("old x %d %d = %d",i1, j1, x[i1][j1]);

        act = 2*bigm-m[i1][j1]; /*threshold bias*/

        for(i2=1; i2<5; i2++) if(i2!=i1) act-=2*bigm*x[i2][j1];
        /*inhibition from the row*/

        for(j2=1; j2<5; j2++) if(j2!=j1) act-=2*bigm*x[i1][j2];
        /*inhibition from the column*/

        x[i1][j1] = (act>=0.0);

        printf("Activation = %10.5f new x %d %d = %d\n", act, i1, j1, x[i1][j1]);
    } /*end k loop*/

    cout<<"\nThe final assignments are : \n\n";
    for(i=1; i<5; i++){
        for(j=1; j<5; j++){
            cout<<x[i][j];
            sum+=x[i][j]*m[i][j];
        }
        printf("\n");
    }

    cout<<"\nThe total cost is : "<<sum;
}

float sig(float x){
    float y;
    y = 1.0/(1.0+exp(-x));
    return(y);
} /*return function sig*/