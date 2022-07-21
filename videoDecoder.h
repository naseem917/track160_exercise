#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>


using namespace cv;
using namespace std;

class videoDecoder
{
	public:
		videoDecoder()
		{
			flag_decode_done = 0;
		}
		void decode(string st);
		Mat* getpic();
		Mat curr_pic;
	private:
		vector<Mat> mat_vec;
		bool flag_decode_done;
		VideoCapture* cap_s;
		//queue<Mat> mat_queue;
};

