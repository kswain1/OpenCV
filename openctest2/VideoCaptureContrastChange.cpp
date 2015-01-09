//
//  VideoCaptureContrastChange.cpp
//  openctest2
//
//  Created by kehlin swain on 1/8/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include "VideoCaptureContrastChange.h"
#include "VideoCapture.h"

void VideoCaptureContrastChange(){
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

    //kind of works web cams stops when the picture is going
    //comment out later please :P
    cv::namedWindow("Higher Contrast Video",CV_WINDOW_AUTOSIZE);
    cv::namedWindow("Lower Contrast Video",CV_WINDOW_AUTOSIZE);
    cv::Mat img1;
    
    //increase the contrast of the video
    frame.convertTo(img1, -1,2,0);
    
    cv::Mat img2;
    //decrease the contrast by half
    frame.convertTo(img2, -1,.5,0);
    
    //show the image
    while(1){
        cv::imshow("Higher Contrast Video", img1);
        cv::imshow("Lower Contrast Video", img2);
        if (cv::waitKey(1) == 27)
            break;
    }

}

