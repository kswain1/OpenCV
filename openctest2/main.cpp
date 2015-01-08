//
//  main.cpp
//  openctest2
//
//  Created by kehlin swain on 1/8/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
void VideoCapture();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    VideoCapture();
    return 0;
}



void VideoCapture(){
    cv::VideoCapture capture(0); //open default camera
    if( capture.isOpened() == false)
        return ;
    
    cv::namedWindow("OpenCV Window Work!",1);
    cv::Mat frame;
    
    while (true) {
        capture >> frame;
        cv::imshow("OpenCV Window Work!", frame);
        int key = cv::waitKey(1);
        if (key == 27)
            break;
    }
}