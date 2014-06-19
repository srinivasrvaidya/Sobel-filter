#include "sobeloperator.h"

int main(int argc, char **argv)
{
	if( argc != 2)
    {
     cout <<" Usage: ./sobel <image>" << endl;
     return -1;
    }

    Mat image,image_gray;
    
    image = imread(argv[1], CV_LOAD_IMAGE_COLOR);   

    if(! image.data )                              
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }
	
	/// Convert it to gray
	cvtColor( image, image_gray, CV_RGB2GRAY );
	Mat image_sobel(image.cols,image.rows,CV_8UC1);
	calcSobelEdge(image_gray,image_sobel);
	
    namedWindow( "Original Image", WINDOW_AUTOSIZE );
    imshow( "Original Image", image );                   
    
    namedWindow( "Gray Image", WINDOW_AUTOSIZE );
    imshow( "Gray Image", image_gray );  
                     
    namedWindow( "Sobel Image", WINDOW_AUTOSIZE );
    imshow( "Sobel Image", image_sobel );  
    
    waitKey(0);   
    imwrite("sobel_output.bmp", image_sobel);                                       
    return 0;
}
