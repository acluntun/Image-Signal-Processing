#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>
#include<iostream>
#include<cmath>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main( )
{
    Mat src1;
    string pics[] = {"KanaLeft1.jpg", "KanaLeft2.jpg", "KanaRight.jpg"};
    
    for(int i = 0; i < 3; i++) {
        src1 = imread(pics[i], CV_LOAD_IMAGE_COLOR);
        //namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
        //imshow( "Original image", src1 );
        
        Mat gray, edge, draw;
        cvtColor(src1, gray, CV_BGR2GRAY);
        
        Canny( gray, edge, 50, 150, 3);
        
        std::string s = std::to_string(i+1);
        
        edge.convertTo(draw, CV_8U);
        namedWindow("image", CV_WINDOW_AUTOSIZE);
        imwrite(s+".jpg", draw);
        //imshow("image", draw);
    }
    /*
    src1 = imread("KanaLeft2.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
    imshow( "Original image", src1 );
    
    Mat gray, edge, draw;
    cvtColor(src1, gray, CV_BGR2GRAY);
    
    Canny( gray, edge, 50, 150, 3);
    
    edge.convertTo(draw, CV_8U);
    namedWindow("image", CV_WINDOW_AUTOSIZE);
    //imwrite("KanaLeftCanny.jpg", draw);
    imshow("image", draw);
    */
    /*
    Mat src2;
    src2 = imread("KanaLeft2.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow( "Original image2", CV_WINDOW_AUTOSIZE );
    imshow( "Original image2", src2 );
    
    Mat gray2, edge2, draw2;
    cvtColor(src2, gray2, CV_BGR2GRAY);
    
    Canny( gray2, edge2, 50, 150, 3);
    
    edge.convertTo(draw2, CV_8U);
    namedWindow("image2", CV_WINDOW_AUTOSIZE);
    imwrite("KanaLeft2Canny.jpg", draw2);
    imshow("image2", draw2);*/
    /*
    Mat src3;
    src1 = imread("KanaRight.jpg", CV_LOAD_IMAGE_COLOR);
    namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
    imshow( "Original image", src3 );
    
    Mat gray3, edge3, draw3;
    cvtColor(src3, gray3, CV_BGR2GRAY);
    
    Canny( gray3, edge3, 50, 150, 3);
    
    edge.convertTo(draw3, CV_8U);
    namedWindow("image", CV_WINDOW_AUTOSIZE);
    imwrite("KanaRightCanny.jpg", draw3);
    imshow("image", draw3);
    */
    waitKey(0);
    return 0;
}
