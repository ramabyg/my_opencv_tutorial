#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  char *imageName = argv[1];

  Mat image;
  image = imread(imageName, IMREAD_COLOR);

  if((argc != 2) || !image.data)
    {
      cout << "No Image data" << endl;
      return -1;
    }
  Mat image_gray;
  cvtColor(image, image_gray, COLOR_BGR2GRAY);
  imwrite( "../outputs/Lena_Gray_Image.jpg", image_gray );
  namedWindow( imageName, WINDOW_AUTOSIZE );
  namedWindow( "Gray image", WINDOW_AUTOSIZE );


  imshow( imageName, image );
  imshow( "Gray image", image_gray );

  waitKey(0);

  return 0;

}
