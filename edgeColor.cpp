#include<iostream>
#include<cmath>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int main()
{
    
    for(int i = 0; i < 3; i++) {
        std::string s = std::to_string(i+1);
        
        cv::Mat input = cv::imread(s+".jpg");
        
        cv::Mat gray;
        cv::Mat dst(input.size(), input.type());
        cv::cvtColor(input,gray,CV_BGR2GRAY);
        
        
        cv::Mat mask, mask2;
        // compute inverse thresholding (dark areas become "active" pixel in the mask) with OTSU thresholding:
        double grayThres = cv::threshold(gray, mask, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);
        
        
        
        // color all masked pixel red:
        dst.setTo(cv::Scalar(255,255,255), mask);
        
        
        // compute median filter to remove the whitish black parts and darker white parts
        cv::imwrite(s+"edge.jpg", dst);
        //cv::imshow("input", input);
        //cv::imshow("dst", dst);
    }
    /*cv::Mat input = cv::imread("KanaLeftCanny.jpg");
    
    cv::Mat gray;
    cv::Mat dst(input.size(), input.type());
    cv::cvtColor(input,gray,CV_BGR2GRAY);
    
    
    cv::Mat mask, mask2;
    // compute inverse thresholding (dark areas become "active" pixel in the mask) with OTSU thresholding:
    double grayThres = cv::threshold(gray, mask, 0, 255, CV_THRESH_BINARY_INV | CV_THRESH_OTSU);

    
    
    // color all masked pixel red:
    dst.setTo(cv::Scalar(255,255,255), mask);
    
    
    // compute median filter to remove the whitish black parts and darker white parts
    
    cv::imshow("input", input);
    cv::imshow("dst", dst);*/
    cv::waitKey(0);
    return 0;
}
