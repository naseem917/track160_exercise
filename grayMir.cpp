#include "grayMir.h"

#ifdef MANUALPROCESSGM

void grayMir::convertToGrayAndFlip(Mat* input_mat, Mat* dst, double perR, double perG, double perB)
{
	*dst = input_mat->clone();

	int i, j;

	for (i = 0; i < input_mat->rows; i++)
		for (j = 0; j < input_mat->cols; j++)
		{
			Vec3b& color = input_mat->at<Vec3b>(Point(j, i));
			Vec3b& color2 = dst->at<Vec3b>(Point(dst->cols - j - 1, i));
			color2[0] = color[0] * perB + color[1] * perG + color[2] * perR;
			color2[1] = 0;
			color2[2] = 0;
		}
}

void grayMir::convertMir(Mat* input_mat)
{
	convertToGrayAndFlip(input_mat, &dst_mat, 0.5, 0.1, 0.4);
}
#else

void grayMir::convertMir(Mat* input_mat)
{
	cvtColor(*input_mat, temp, COLOR_BGR2GRAY);
	flip(temp, dst_mat, 1);

	return;
}

#endif

void grayMir::process_queue(TaskQueue<std::variant<Mat*, Stop>>& in_queue, TaskQueue<Mat*>& out_queue) {
	bool running = true;
	while (running) {
		auto task = in_queue.GetTask();
		if (std::holds_alternative<Stop>(task)) {
			running = false;
		}
		else {
			convertMir(std::get<Mat*>(task));
			out_queue.PushTask(std::move(&dst_mat));
		}
	}
}


Mat* grayMir::getMat()
{
	return &dst_mat;
}