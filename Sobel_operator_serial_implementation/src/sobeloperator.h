#ifndef __sobel_operator
#define __sobel_operator

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <time.h>
#include <stdio.h>
using namespace std;
using namespace cv;

void calcSobelEdge(Mat image_gray,Mat& image_sobel);

#endif
