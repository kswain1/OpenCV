//
//  ReadImageandFileDispaly.cpp
//  openctest2
//
//  Created by kehlin swain on 1/8/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
// This class is used to read in images and display them using opencv

#include "ReadImageandFileDispaly.h"
//
void ReadImageandFileDispaly()
{
    cv::Mat img = cv::imread("/Users/kehlinswain/Pictures/FaceShot.png",CV_LOAD_IMAGE_UNCHANGED);
    
    if (img.data)
    {
        std::cout << "I found your image!" << std::endl;
    }else {
        std::cout<< "Image not loaded" << std::endl;
        
    }
    //create a window with the name "MYWindow"
    cv::namedWindow("MyWindowSwain", CV_WINDOW_AUTOSIZE);
    cv::imshow("MyWindowSwain", img);
    
    cv::waitKey(0);
    cv::destroyWindow("MyWindowSwain");
    
}