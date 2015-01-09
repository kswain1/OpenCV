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
#include "ReadImageandFileDispaly.h"
#include "ErodingFilter.h"
#include "VideoCaptureContrastChange.h"
#include "HistogramEquilizationGrayScale.h"



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //VideoCapture();
    //ReadImageandFileDispaly();
    //ErodingFilter();
    //VideoCaptureContrastChange();
    HistogramEquilizationGrayScale();
    
    return 0;
}

