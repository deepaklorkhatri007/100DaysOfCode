// Error response program (r-x)^2
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    float xmin, xmax, x, r, h, diff, newss, oldss;
    printf("What is the correct response (r) ? ");
    scanf("%f", &r);
    printf("What is the minimum value of x ? ");
    scanf("%f", &xmin);
    printf("What is the maximum value of x ? ");
    scanf("%f", &xmax);
    h = (xmax-xmin)/16.0;
    x = xmin;
    oldss = (r-x)*(r-x);
    printf("x sqared error change \n");
    printf("%8.4f %8.4f \n", x, oldss);
    for(x=x+h; x<=xmax; x+=h){
        newss = (r-x)*(r-x);
        diff = newss-oldss;
        printf("%8.4f %8.4f %8.4f \n", x, newss, diff);
        oldss = newss;
    }
    return 0;
}
