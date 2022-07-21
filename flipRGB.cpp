#include "flipRGB.h"


#ifdef MANUALPROCESSFR

void flipRGB::flipping_pic(Mat* input_mat)
{
	int i, j;
	out_mat = input_mat->clone();
	unsigned char temp_ch;

	for (i = 0; i < input_mat->rows; i++)
		for (j = 0; j < input_mat->cols; j++)
		{
			Vec3b& color = input_mat->at<Vec3b>(Point(j, i));
			Vec3b& color2 = out_mat.at<Vec3b>(Point(j, i));
			temp_ch = color2[0];
			color2[0] = color[2];
			color2[2] = temp_ch;
		}
/*	imshow("Frame1", *input_mat);
	imshow("Frame2", out_mat);
	char c = (char)waitKey(25);*/
} 
#else

void flipRGB::flipping_pic(Mat* input_mat)
{
	//Mat channelsa[3];
	//Mat *temp_mat,out_mat;
	split(*input_mat, channels);
	temp_mat = channels[0];
	channels[0] = channels[2];
	channels[2] = temp_mat;

	//imshow("Frame11", *input_mat);



	merge(channels, 3, out_mat);

	//imshow("Frame12", out_mat);
	//char c = (char)waitKey(25);

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
			//Mat* output = nullptr; 
			flipping_pic(std::get<Mat*>(task));

			out_queue.PushTask(std::move(&out_mat));
		}
	}
}

Mat* flipRGB::getMat()
{
	return &out_mat;
}