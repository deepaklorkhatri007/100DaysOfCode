// Single learning neuron for AND, OR gates
#include <iostream>
#include <random>
using namespace std;

int x[4][3] = {
    {1, 0, 0},
    {1, 1, 0},
    {1, 0, 1},
    {1, 1, 1}
};

float w[3], corr;
int results[4], resp, diff, wrongresp=1, c;

int main(int argc, char const *argv[])
{
    for(int i=0; i<4; i++){
        printf("Type in the correct response for the inputs %d %d : ", x[i][1], x[i][2]);
        cin>>results[i];
    }
   
    random_device rndm;
    seed_seq seed{rndm(), rndm(), rndm(), rndm(), rndm()};
    mt19937 eng{seed};
    uniform_int_distribution<> dist(0, 1000);
    // cout<<dist(eng)/100.00<<endl; rnadom number
    for(int i=0; i<3; i++){
        w[i] = dist(eng)/1000.0;
    }

    printf("The initial weights are %f %f %f \n", w[1], w[2], w[0]);
    cout<<"Enter value of Correction factor : ";
    cin>>corr;
    cout<<endl<<endl;
    while(wrongresp){
        wrongresp = 0;
        for(int i=0; i<4; i++){
            resp = ((w[0]*x[i][0]+w[1]*x[i][1]+w[2]*x[i][2])>=0);
            diff = results[i]-resp;
            printf("test inputs %d %d, response %d, correct response %d\n", x[i][1], x[i][2], resp, results[i]);
            if(diff !=0 ){
                wrongresp = 1;
                w[0] = w[0] + diff*corr*x[i][0];
                w[1] = w[1]+diff*corr*x[i][1];
                w[2] = w[2]+diff*corr*x[i][2];
                printf("New weights %f %f %f \n\n", w[1], w[2], w[0]);
            }
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    printf("The final weights are w1=%f w2=%f w0=%f \n\n", w[1], w[2], w[0]);
    return 0;
}
