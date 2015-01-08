//
//  ErodingFilter.cpp
//  openctest2
//
//  Created by kehlin swain on 1/8/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include "ErodingFilter.h"
//#include <opencv2/opencv.hpp>
#include <opencv/cv.h>
#include <opencv/highgui.h>


void ErodingFilter()
{
     //display origiinal image window
    IplImage *img = cvLoadImage("/Users/kehlinswain/Pictures/FaceShot.png");
    cvNamedWindow("Image Filter Window");
    cvShowImage("Image Filter Window", img);
    
    //erode and display the eroded image
    cvNot(img,img);
    cvNamedWindow("Eroded");
    cvShowImage("Eroded", img);
    
    cvWaitKey(0);
    
    //clean up the image
    cvDestroyWindow("My Window");
    cvDestroyWindow("Eroded");
    cvReleaseImage(&img);
   
    
}