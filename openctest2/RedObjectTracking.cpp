//
//  RedObjectTracking.cpp
//  openctest2
//
//  Created by kehlin swain on 1/9/15.
//  Copyright (c) 2015 Kehlin Swain. All rights reserved.
//

#include "RedObjectTracking.h"

void RedObjectTracking(){
    // if not success, exit program
    VideoCapture cap(0);
   
    
    // if not success, exit program
    if ( !cap.isOpened() )
    {
        cout << "Cannot open the web cam" << endl;
        return ;
    }
    
    namedWindow("Control",0);
    
    int lowValueHue = 0;
    int highValueHue = 179;
    
    int lowValueSat = 0;
    int highValueSat = 255;
    
    int lowValueVal = 0;
    int highValueVal = 255;
    
    //Create trackbars in "Control" Window
    cvCreateTrackbar("LowHue", "Control",&lowValueHue , 179,NULL);
    cvCreateTrackbar("HighHue", "Control",&highValueHue , 179,NULL);
    
    cvCreateTrackbar("LowSat", "Control",&lowValueSat , 255,NULL);
    cvCreateTrackbar("HighSat", "Control",&highValueSat , 255,NULL);
    
    cvCreateTrackbar("LowVal", "Control",&lowValueVal , 255,NULL);
    cvCreateTrackbar("HighVal", "Control",&highValueVal , 255,NULL);
    
    int iLastX = -1;
    int iLastY = -1;
    
    //Capture temporary imag from the camera
    Mat imageTemp;
    cap.read(imageTemp);
    
    //Capture a black image with size as the camera output
    Mat imageLines = Mat::zeros(imageTemp.size(),  CV_8UC3);;
    
    while (true)
    {
        Mat imageOriginal;
        
        //sets true reading an image from webcam
        bool frameSuccess = cap.read(imageOriginal);
        
        if(!frameSuccess)
        {
            cout << "Ohh no I cannot find your frame!" << endl;
            break;
        }

    
        Mat imageHSV;
        
        //convert the capture fram from BGR TO HSV
        cvtColor(imageOriginal, imageHSV, COLOR_BGR2HSV);
        
        Mat imageThresholded;
        
        //threshold the image
        inRange(imageHSV, Scalar(lowValueHue,lowValueSat,lowValueVal), Scalar(highValueHue,highValueSat,highValueVal), imageThresholded);
        
        //morphologoical opening(remove smalle objectsfrom teh foreground)
        erode(imageThresholded, imageThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        dilate(imageThresholded, imageThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        
        //morphological closing fill in small holes of the foreground)
        dilate(imageThresholded, imageThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        erode(imageThresholded, imageThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
        
        //Calculate the moments of the threshold image
        Moments theMoments = moments(imageThresholded);
        
        double dM01 = theMoments.m01;
        double dM10 = theMoments.m10;
        double dArea = theMoments.m00;
        
        // if the area <= 10000, lets consider that there are no objects in the image because of the noise
        if(dArea> 10000)
        {
            //calculate the position of the ball
            int posX = dM10/dArea;
            int posY  =dM01/dArea;
            
            if(iLastX >= 0 && iLastY >= 0 && posX >= 0 && posY >= 0)
            {
                //Draw a red line from th previous point to the current point
                line(imageLines, Point(posX,posY), Point(iLastX,iLastY), Scalar(0,0,255),2);
            }
            
            //then swap the new position to the first position
            
            iLastX = posX;
            iLastY = posY;
        }
        
        
        imshow("Thresholded Image", imageThresholded); //show the thresholded image
        
        imageOriginal = imageOriginal + imageLines;
        imshow("Original", imageOriginal); //show the original image
        
        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

}

