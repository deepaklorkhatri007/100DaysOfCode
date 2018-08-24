// Boltzman machine
#include <iostream>
#include <math.h>
#include <random>
using namespace std;

float sig(float);

int main(int argc, char const *argv[])
{   
    float m[5][5], act, bigm=-100, u, p, t, sum;
    int x[5][5], i1, i2, j1, j2, i, j, k;

    /*random numbers generator*/
    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(0, 1);
    uniform_int_distribution<> dist2(1, 4);
    uniform_int_distribution<> dist3(0, 99);

    cout<<"Type in the rows of costs like this : ";
    cout<<"0 1 0 1"<<endl;

    /*get costs and initialize nodes*/
    for(i=1; i<5; i++){
        cout<<"What are the costs for row : "<<i<<endl;
        for(j=1; j<5; j++){
            cin>>m[i][j];
            if(m[i][j]>bigm) bigm = m[i][j]; /*find biggest cost*/
            x[i][j] = dist(eng);    /*initialize node*/
        }
    }

    t = bigm*10.0; /*initialize temprature*/

    /*Randomly update nodes*/
    for(k=1; k<=250; k++){
        i1 = dist2(eng);
        j1 = dist2(eng);
        printf("old x %d %d = %d ", i1, j1, x[i1][j1]);

        act = 2*bigm - m[i1][j1];
        for(i2=1; i2<5; i2++) if(i2!=i1) act-= 2*bigm*x[i2][j1];
        for(j2=1; j2<5; j2++) if(j2!=j1) act-= 2*bigm*x[i1][j2];
        p = sig(act/t);
        u = dist3(eng)/1000.0;
        x[i1][j1] = (u<=p);

        printf("Activation = %10.5f new x %d %d = %d\n", act, i1, j1, x[i1][j1]);
        t = t*0.97; /*revise temprature*/

        /*  The above line decreases t geometrically
            Modify this if you wish, but don't let
            t becomes negative or zero!*/

    }   /*end k loop*/

    cout<<"The final assignments are : \n\n";
    for(i=1; i<5; i++){
        for(j=1; j<5; j++){
            cout<<x[i][j];
            sum+=x[i][j]*m[i][j];
        }
        cout<<"\n";
    }

    cout<<"\n The total cost is : "<<sum<<endl;
    return 0;
} /*end main*/

float sig(float x){
    float y;
    y = 1.0/(1.0+exp(-x));
    return y;
} /*end function sig*/