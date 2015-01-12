# OpenCV
Currently going through tutorials to use opencv with c++, in the near future will publish a project for a robotics competition
All the files are implemented come this website examples: 
http://opencv-srf.blogspot.com/2010/09/object-detection-using-color-seperation.html

The opencv functions I implemented are :
- Inverting/eroding images
- Video Capture Contrast 
- Histogram Equilization 
- Object Color Tracking 

I made a class for each of the listed functions, if you would like to erode and image follow these steps: 
- #include "ErodingFilter.h" in main.cpp header
- call ErodingFilter(); in main.cpp
- change the the cvLoadImage("/Users/kehlinswain/Pictures/FaceShot.png") funciton inside of ErodingFilter.cpp
  - to your specific file name 
  - e.g Mat myImage = cvLoadImage("/Users/MyName/Desktop/Favorite.jpg")
- Run the program

![screen shot 2015-01-12 at 2 00 11 pm](https://cloud.githubusercontent.com/assets/9138420/5709935/95e917a8-9a63-11e4-9f35-968fe184c554.png)

![screen shot 2015-01-12 at 2 00 23 pm](https://cloud.githubusercontent.com/assets/9138420/5709951/b9b22d6e-9a63-11e4-832a-0a354830ede7.png)


 If you would like to use the VideoContrast Function follow these steps: 
- #include "VideoCaptureContrastChange.h" in main.cpp header
- call VideoCaptureContrastChange(); in main.cpp
- Run the program

![screen shot 2015-01-09 at 10 16 30 am](https://cloud.githubusercontent.com/assets/9138420/5709989/272ed0f4-9a64-11e4-8a4f-99c1b3a9cdbe.png)

![screen shot 2015-01-09 at 10 16 49 am](https://cloud.githubusercontent.com/assets/9138420/5709992/2aa48a1c-9a64-11e4-9e20-bf2482423d3d.png)

 If you would like to use the Histogram Equilization  Function follow these steps: 
- #include "HistogramEquilizationColorImage.h" in main.cpp header
- call HistogramEquilizationColorImage(); in main.cpp
- change to your image location image1 = imread("/Users/kehlinswain/Pictures/FaceShot.png", CV_LOAD_IMAGE_COLOR); inside of the HistogramEquilizationColorImage.cpp file
  - e.g Mat myImage = imread("/Users/MyName/Desktop/Favorite.jpg")
- Run the program

![screen shot 2015-01-12 at 2 12 30 pm](https://cloud.githubusercontent.com/assets/9138420/5710121/1b14f2ac-9a65-11e4-99ff-d0568f33a336.png)
![screen shot 2015-01-12 at 2 12 22 pm](https://cloud.githubusercontent.com/assets/9138420/5710118/184f4ce8-9a65-11e4-8aa3-f4719c2ccd4d.png)

 If you would like to use the Histogram Equilization  Function follow these steps: 
- #include "RedObjectTracking.h" in main.cpp header
- call RedObjectTracking(); in main.cpp
- Currently I have the program set to filter out the black colors, but if you know the HSV values of your color feel free to change it.
- Change the inRange() to the upper and lower bound of your color you want to filter inside of the RedObjectTracking.cpp
 - e.g // for black
        inRange(imgHSV, Scalar(0, 0, 0, 0), Scalar(180, 255, 30, 0), imgThreshold);
- If you use color picker with gimp you can get the exact value of your colors
  - The conversion of GIMP to OpenCv HSV value are:
    - HUE: OpenCV = GIMP/2
    - SATURAION: OpenCV = GIMP/.392
    - VALUE: OpenCV = GIMP/.392
    - LUMA just leave it as zero
- I made a youtube Video to show my results:
    https://www.youtube.com/watch?v=AJ3ozBzUThk
    
![screen shot 2015-01-12 at 12 42 09 pm](https://cloud.githubusercontent.com/assets/9138420/5710357/fcf69404-9a66-11e4-9656-ec2f2ecc9f9c.png)

- The red line tracks whatever color that is thresholded



- Run the program
