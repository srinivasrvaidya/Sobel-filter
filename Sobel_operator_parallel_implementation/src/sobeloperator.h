#ifndef __sobel_operator
#define __sobel_operator

#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "omp.h"

using namespace std;
using namespace cv;

void calcSobelEdge(Mat image_gray,Mat& image_sobel);

#endif
