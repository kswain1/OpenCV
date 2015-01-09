//
//  HistogramEquilizationColorImage.cpp
//  openctest2
//
//  Created by kehlin swain on 1/9/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include "HistogramEquilizationColorImage.h"
using namespace cv;
using namespace std;


void HistogramEquilizationColorImage() {
    //open and read image
    Mat image1 = imread("/Users/kehlinswain/Pictures/FaceShot.png", CV_LOAD_IMAGE_COLOR);
    
    if (image1.empty())
    {
        cout<< "Oh No! I cannot find your image!"<< endl;
        return;
    }
    
    vector<Mat> imageChannel;
    Mat image_histogram_equalized;
    
    //change the color image fomat from bgr to ycrcb
    cvtColor(image1, image_histogram_equalized, CV_BGR2YCrCb);
    
    //split the image into channels
    split(image_histogram_equalized, imageChannel);
    
    //equalize the histogram on 1st channel
    equalizeHist(imageChannel[0], imageChannel[0]);
    
    //merge the channels together to be one
    merge(imageChannel,image_histogram_equalized);
    
    //transform the Ycrcrb back bgr to use imshow
    cvtColor(image_histogram_equalized, image_histogram_equalized, CV_YCrCb2BGR);
    
    //create windows
    namedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Image",CV_WINDOW_AUTOSIZE);
    
    //show the image
    imshow("Original Image", image1);
    imshow("Histogram Image", image_histogram_equalized);
    
    waitKey(0);
    
    //destroy all windows
    destroyAllWindows();
    
    
}