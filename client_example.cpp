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


    vector<Mat> Original_pics_vec;
    vector<Mat> GBR_pics_vec;
    vector<Mat> grayandmir_pics_vec;
    MainClass* m = new MainClass();
    m->display_pics(); // a choice to show pics within m->start
    m->start(Original_pics_vec, GBR_pics_vec, grayandmir_pics_vec, "C:/Nas/video_samp/Pigeons_in_Love.mp4");


    for (int i = 0; i < Original_pics_vec.size(); i++) // another choice of showing the pics by outputting them to the client
    {
        imshow("Original_pic", Original_pics_vec[i]);
        imshow("GBR_pic", GBR_pics_vec[i]);
        imshow("grayandmir_pic", grayandmir_pics_vec[i]);
        char c = (char)waitKey(25);
    }
    destroyAllWindows();




    return 0;
}