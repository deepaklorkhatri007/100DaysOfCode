#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float a[10][10], b[10][10], c[10][10], x;
    int i, j, k, rows1, rows2, cols1, cols2;

    cout<<"The matrices can be up to 10x10 in size."<<endl;
    cout<<"The number of columns of the first matrix must"<<endl;
    cout<<"equals to the number of rows in the second matrix."<<endl;
   
    cout<<"Enter rows of the first matrix : ";
    cin>>rows1;
    
    cout<<"Enter cols of the first matrix : ";
    cin>>cols1;
    rows2 = cols1;

    cout<<"Enter cols of the second matrix : ";
    cin>>cols2;

    cout<<"input the first matrix"<<endl;

    for(i=0; i<rows1; i++){
        cout<<"What are the values for row "<<i+1<<" : ";
        for(j=0; j<cols1; j++) cin>>a[i][j];
    }

    cout<<"input the second matrix"<<endl;

    for(i=0; i<rows1; i++){
        cout<<"What are the values for row "<<i+1<<" : ";
        for(j=0; j<cols2; j++) cin>>b[i][j];
    }

    /*now let's multiply the matrices*/
    cout<<"The result is : "<<endl;
    for(i=0; i<rows1; i++){
        cout<<"Row "<<i+1<<" : ";
        for(j=0; j<cols2; j++){
            x = 0.0;
            for(k=0; k<cols1; k++) x+=a[i][k]*b[k][j];
            c[i][j] = x;
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
