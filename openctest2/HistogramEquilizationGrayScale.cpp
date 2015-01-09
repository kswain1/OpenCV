//
//  HistogramEquilizationGrayScale.cpp
//  openctest2
//
//  Created by kehlin swain on 1/9/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include "HistogramEquilizationGrayScale.h"
using namespace cv;
using namespace std;

void HistogramEquilizationGrayScale(){
    //open and read image
    Mat image = imread("/Users/kehlinswain/Pictures/FaceShot.png", CV_LOAD_IMAGE_COLOR);
    
    if(image.empty())
    {
        cout<< " Ohh no! I cannot find your image!" << endl;
        return ;
    }
    
    //change the color to gray scale
    Mat imageGray;
    cvtColor(image, imageGray, CV_RGB2GRAY);
    
    //equalize the images with the use of histogram algorithm
    Mat imageHistogramEqualized;
    equalizeHist(imageGray, imageHistogramEqualized);
    
    //create the windows
    namedWindow("Original Image", CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Image",CV_WINDOW_AUTOSIZE);
    
    //show the image
    imshow("Original Image", imageGray);
     imshow("Histogram Image", imageHistogramEqualized);
    
    waitKey(0);
    
    destroyAllWindows();
    
}



