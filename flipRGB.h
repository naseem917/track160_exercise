#pragma once
#include "videoDecoder.h"
#include <thread>
#include "task_queue.h"
#include <variant>

#define MANUALPROCESSFR
#undef MANUALPROCESSFR

class flipRGB
{
public:
	flipRGB()
	{
/*		channels[0] = new Mat;
		channels[1] = new Mat;
		channels[2] = new Mat;*/
		//temp_mat = new Mat;
	}
	void flipping_pic(Mat* input_mat);
	void process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue);
	Mat* getMat();

private:
	Mat channels[3];
	Mat temp_mat,  out_mat;
};

