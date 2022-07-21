#include "flipRGB.h"


#ifdef MANUALPROCESSFR 

void flipRGB::flipping_pic(Mat* input_mat)
{
	int i, j;
	out_mat = input_mat->clone();

	for (i = 0; i < input_mat->rows; i++)
		for (j = 0; j < input_mat->cols; j++)
		{
			Vec3b& color = input_mat->at<Vec3b>(Point(j, i));
			Vec3b& color2 = out_mat.at<Vec3b>(Point(j, i));
			swap(color2[0], color2[2]);
		}
} 
#else

void flipRGB::flipping_pic(Mat* input_mat)
{
	split(*input_mat, channels);

	swap(channels[0], channels[2]);

	merge(channels, 3, out_mat);

	return;
}

#endif


void flipRGB::process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue) {
	bool running = true;
	while (running) {
		auto task = in_queue.GetTask();
		if (std::holds_alternative<Stop>(task)) {
			running = false;
		}
		else { 
			flipping_pic(std::get<Mat*>(task));

			out_queue.PushTask(std::move(&out_mat));
		}
	}
}

Mat* flipRGB::getMat()
{
	return &out_mat;
}