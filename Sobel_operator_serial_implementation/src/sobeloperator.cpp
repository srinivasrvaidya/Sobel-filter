#include "sobeloperator.h"
#include "omp.h"

#define M_PI	3.14159265358979323846

void calcSobelEdge(Mat image_gray,Mat& image_sobel)
{
	// 3x3 Sobel mask
	const int maskX[3][3]={ -1, 0, 1,
						    -2, 0, 2,
				      		-1, 0, 1};

	const int maskY[3][3]={  1, 2, 1,
				       		 0, 0, 0,
				      		-1,-2,-1};	

	double sum = 0.0;
	double dx = 0.0, dy = 0.0;
	int i, j;

	Mat image=image_gray.clone();
	
	int rows = image.rows-1, cols = image.cols-1;
	printf(" \n Image info: ");
	printf("\n No:OfRows = %d ",rows);
	printf("\n No:OfCols = %d ",cols);
	
	
	double start = omp_get_wtime( );	
	// Loop - ignoring the edges
	for(int y=1; y<image.rows-1; y++)
	{
		for(int x=1; x<image.cols-1; x++)
		{
			dx=0.0;
			dy=0.0;		 
			sum=0.0;
			// Horizontal gradient (X)
			for(j=-1;j<=1;j++)
			{
				for(i=-1;i<=1;i++)
				{
					dx = dx + (double) ( (int) image.at<uchar>(x+i,y+j) * maskX[j+1][i+1] );
					//dx = dx + (unsigned char)(img->imageData[(x+i)+(y+j)*img->widthStep])*maskX[j+1][i+1];
				}
			}
			// Vertical gradient (Y)
			for(j=-1;j<=1;j++)
			{
				for(i=-1;i<=1;i++)
				{
					dy = dy + (double) ( (int) image.at<uchar>(x+i,y+j) * maskY[j+1][i+1] );
					//dy= dy + (unsigned char)(img->imageData[(x+i)+(y+j)*img->widthStep])*maskY[j+1][i+1];					  
				}
			}
		
			//Gradient magnitude
			sum += sqrt((dx*dx)+(dy*dy));
			//cout<<sum<<endl;
			//sum = sum > 255 ? 255:sum;
           // sum = sum < 0 ? 0 : sum;
            image_sobel.at<uchar>(x,y) = sum;
		}
	}
	double end = omp_get_wtime( );
	printf("\n ------------- TIMING :: Serial Version -------------- ");
	printf("\nStart = %.16g\nend = %.16g\nDiff_time = %.16g\n",start, end, end - start);

}

