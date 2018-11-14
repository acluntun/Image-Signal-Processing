#include<iostream>
#include<cmath>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int maximum (int,int,int);
int minimum(int,int,int);

int main()
{
    cv::Mat image = cv::imread("kana.jpg");
    Mat dstR, dst2, dst3, dst4, dst5,dstL;
    
    inRange(image, Scalar(0,0,0), Scalar(125, 150,180), dst2);
    inRange(image, Scalar(0,0,0), Scalar(140, 200, 170), dst3);
    
    dstR = cv::Scalar::all(255) - dst2;
    dstL = cv::Scalar::all(255) - dst3;
    
    
    Rect crop1 = Rect(277,675,266,736);
    Mat croppedImage = dstL(crop1);
    
    Rect crop2 = Rect(598,230,319,1127);
    Mat croppedImage2 = dstL(crop2);
    
    Rect crop3 = Rect(1646,627,408,845);
    Mat croppedImage3 = dstR(crop3);
    
    //Mat im;
    //Mat1f im(image.size());
    //croppedImage.copyTo(im.rowRange(277,543).colRange(675,1411));
    /*Rect imgL = Rect(0,0,585,1127);
     Size s1 = croppedImage.size();
     Size s2 = croppedImage2.size();
     Mat im(s2.height, s1.width+s2.width, image.type());
     Mat left(im, Rect(0,0,s1.width,s1.height));
     croppedImage.copyTo(left);
     Mat right(im, Rect(s1.width,0,s2.width,s2.height));
     croppedImage2.copyTo(right);*/
    
    
    //dstL.push_back(croppedImage2);
    //dstL.push_back(croppedImage3);
    //Size s = image.size();
    //Mat img = Mat::zeros(image.size(), image.type());
    //Size sR = croppedImage3.size();
    //Mat right(img, Rect(0, 0, sR.width, sR.height));
    //croppedImage3.copyTo(right);
    
    //auto matC = croppedImage + croppedImage2;
    
    //namedWindow("im", CV_WINDOW_FREERATIO);
    //imshow("im", im);
    
    
    namedWindow("dstR", CV_WINDOW_FREERATIO);
    imshow("dstR", dstR);
    
    namedWindow("dstL", CV_WINDOW_FREERATIO);
    imshow("dstL", dstL);
    
    namedWindow("dst2", CV_WINDOW_FREERATIO);
    imshow("dst2", dst2);
    
    namedWindow("dst3", CV_WINDOW_FREERATIO);
    imshow("dst3", dst3);
    
    
    namedWindow("cropped", CV_WINDOW_FREERATIO);
    imwrite("KanaLeft1.jpg", croppedImage);
    imshow("cropped", croppedImage);
    
    namedWindow("cropped2", CV_WINDOW_FREERATIO);
    imwrite("KanaLeft2.jpg", croppedImage2);
    imshow("cropped2", croppedImage2);
    
    namedWindow("cropped3", CV_WINDOW_FREERATIO);
    imwrite("KanaRight.jpg", croppedImage3);
    imshow("cropped3", croppedImage3);
    
    waitKey(0);
    
    return 0;
}

