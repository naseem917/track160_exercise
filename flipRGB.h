#pragma once
#include "videoDecoder.h"
#include <thread>
#include "task_queue.h"
#include <variant>

#define MANUALPROCESSFR
#undef MANUALPROCESSFR // comment this whole line to enable manual processing

class flipRGB
{
public:
	void flipping_pic(Mat* input_mat);
	void process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue);
	Mat* getMat();

private:
	Mat channels[3];
	Mat temp_mat,  out_mat;
};

