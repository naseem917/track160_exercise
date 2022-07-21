#pragma once
#include "videoDecoder.h"
#include <thread>
#include "task_queue.h"
#include <variant>

#define MANUALPROCESSGM
#undef MANUALPROCESSGM // comment this whole line to enable manual processing

class grayMir
{
public:


	void convertMir(Mat* input_mat);
	void process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue);
	Mat* getMat();

private:
	void convertToGrayAndFlip(Mat* input_mat, Mat* dst, double perR, double perG, double perB);

	Mat dst_mat, temp;
};


