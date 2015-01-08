//
//  main.cpp
//  openctest2
//
//  Created by kehlin swain on 1/8/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "VideoCapture.h"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //VideoCapture();
    //read the image data in the file "MYPic.JPG" and store it
    cv::Mat img = cv::imread("/Swain/Users/kehlinswain/Pictures/FaceShot.png",CV_LOAD_IMAGE_UNCHANGED);
    
    if (img.empty())
    {
        std::cout << "Error I cannot find your image!" << std::endl;
        return -1;
    }
//    //create a window with the name "MYWindow"
//    cv::namedWindow("MyWindowSwain", CV_WINDOW_AUTOSIZE);
//    cv::imshow("MyWindowSwain", img);
//    
//    cv::waitKey(0);
//    cv::destroyWindow("MyWindowSwain");
    return 0;
}


//void VideoCaptures(){
//    cv::VideoCapture capture(0); //open default camera
//    if( capture.isOpened() == false)
//        return ;
//    
//    cv::namedWindow("OpenCV Window Work!",1);
//    cv::Mat frame;
//    
//    while (true) {
//        capture >> frame;
//        cv::imshow("OpenCV Window Work!", frame);
//        int key = cv::waitKey(1);
//        if (key == 27)
//            break;
//    }
//}