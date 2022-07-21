#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "videoDecoder.h"
#include "flipRGB.h"
#include "grayMir.h"
#include "MainClass.h"
using namespace cv;
using namespace std;

int main()
{

    //Mat img = cv::imread("C:/Nas/imgae_samp/pic1.jpg");
    //namedWindow("First OpenCV Application", WINDOW_AUTOSIZE);
    //imshow("First OpenCV Application", img);
    //moveWindow("First OpenCV Application", 476, 475);
    //waitKey(0);
    //destroyAllWindows();

    //videoDecoder* v1 = new videoDecoder();
    //v1->decode("C:/Nas/video_samp/nature_vid.mp4");
    vector<Mat> Original_pics_vec;
    vector<Mat> GBR_pics_vec;
    vector<Mat> grayandmir_pics_vec;
    MainClass* m = new MainClass();
    m->display_pics(); // a choice to show pics within m->start
    m->start(Original_pics_vec, GBR_pics_vec, grayandmir_pics_vec, "C:/Nas/video_samp/Pigeons_in_Love.mp4");
    //m->stop();

    for (int i = 0; i < Original_pics_vec.size(); i++)
    {
        imshow("Original_pic", Original_pics_vec[i]);
        imshow("GBR_pic", GBR_pics_vec[i]);
        imshow("grayandmir_pic", grayandmir_pics_vec[i]);
        char c = (char)waitKey(25);
    }
    //Mat* Mat_ptr = v1->getpic();
    //flipRGB* v2 = new flipRGB();
    //v2->flipping_pic(&img);
    //grayMir* v3 = new grayMir();
    //v3->convertMir(&img);



    return 0;
}