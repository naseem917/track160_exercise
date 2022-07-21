#pragma once
#include "videoDecoder.h"
#include <thread>
#include "task_queue.h"
#include <variant>

#define MANUALPROCESSGM
#undef MANUALPROCESSGM // comment this whole line to 

class grayMir
{
public:
/*	grayMir()
	{
		channels[0] = new Mat;
		channels[1] = new Mat;
		channels[2] = new Mat;
		temp = new Mat;
		dst = new Mat;
	}*/

	void convertMir(Mat* input_mat);
	void process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue);
	Mat* getMat();

private:
	void convertToGrayAndFlip(Mat* input_mat, Mat* dst, double perR, double perG, double perB);
/*#ifdef MANUALPROCESSGM
	Mat* channels[3];
#endif */

	Mat dst_mat, temp;
};


