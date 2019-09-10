#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
int main( void )
{
   double alpha = 0.5; double beta; double input;
   Mat src1, src2, dst;
   cout << " Simple Linear Blender " << endl;
   cout << "-----------------------" << endl;
   cout << "* Enter alpha [0.0-1.0]: ";
   cin >> input;
   // We use the alpha provided by the user if it is between 0 and 1
   if( input >= 0 && input <= 1 )
     { alpha = input; }
   src1 = imread( "../assets/puppies.jpg" );
   src2 = imread( "../assets/lenna.jpg" );
   if( src1.empty() ) { cout << "Error loading src1" << endl; return -1; }
   if( src2.empty() ) { cout << "Error loading src2" << endl; return -1; }
   beta = ( 1.0 - alpha );
   resize(src2, src2, src1.size());
   addWeighted( src1, alpha, src2, beta, 0.0, dst);
   namedWindow("Linear-Blend", WINDOW_KEEPRATIO);
   imshow( "Linear-Blend", dst );
   waitKey(0);
   return 0;
}