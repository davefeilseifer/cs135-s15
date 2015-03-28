#include "image_to_array.h"
#include <stdio.h>

ImageData image_to_array( const char* filename, bool threshold )
{
	ImageData ret;

	cv::Mat image;
    image = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);   // Read the file

	// convert to gray
	cv::Mat grey;
	//printf( "image [%s] has %d channels\n", filename, image.channels());
	if( image.channels() > 1 )
	{
		cv::cvtColor(image, grey, CV_BGR2GRAY);
	}
	else 
	{
		//cv::cvtColor(image, grey, CV_BGR2GRAY);
		grey = image.clone();
	}

	//printf( "%d %d %ld\n", image.rows, image.cols, (long) image.data );
	//printf( "%d %d %ld\n", grey.rows, grey.cols, (long) grey.data );

	// threshold image

	if( threshold )
	{
		cv::Mat thresh;
		cv::threshold( grey, thresh, 127, 255, 0 );
		grey = thresh;
	}
	ret.height = grey.rows;
	ret.width = grey.cols;

    if(! grey.data )                              // Check for invalid input
    {
        printf("Could not open or find the image\n" );
        exit(-1);
    }

	// allocate memory for image
	ret.data = new unsigned char*[ret.height];
	for(int i = 0; i < ret.height; i++ )
	{
		ret.data[i] = new unsigned char[ret.width];
	}

	// set image data
	for( int i = 0; i < ret.height; i++ )
	{
		for( int j = 0; j < ret.width; j++ )
		{
			ret.data[i][j] = grey.at<uchar>(i,j);
		}
	}

	return ret;
}

cv::Mat array_to_image( ImageData data, const char* display_name )
{
	// initialize image
	cv::Mat out_image(data.height,data.width, CV_8UC1, cv::Scalar(0));

	// copy image data to array
	for( int i = 0; i < data.height; i++ )
	{
		for( int j = 0; j < data.width; j++ )
		{
			out_image.at<uchar>(i,j) = data.data[i][j];
		}
	}

	if( display_name != NULL )
	{

		// display image 
    	cv::namedWindow( display_name, cv::WINDOW_AUTOSIZE );// Create a window for display.
	    cv::imshow( display_name, out_image );                   // Show our image inside it.

	}
	return out_image;
}

