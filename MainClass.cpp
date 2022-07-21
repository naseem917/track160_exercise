#include "MainClass.h"
#include <thread>
#include <String>


void foo()
{

}


void MainClass::start(vector<Mat>& Original_pics_vec, vector<Mat>& GBR_pics_vec, vector<Mat>& grayandmir_pics_vec,string st)
{
	// Start the worker threads.
	m_thread_flipping_pic = std::thread([&] { m_flip_rgb_operation.process_queue(m_flipping_queue, m_output_queue); });
	m_thread_gray_mirror = std::thread([&] { m_gray_mirror_operation.process_queue(m_gray_mirror_queue, m_output_queue); });

	// This is just wrong! You are encoding ahead of time and then sending data to the thread. 
	// This should be interleaved.
	v1.decode(st);
	Mat* Mat_ptr = v1.getpic();

	while (Mat_ptr)
	{
		Original_pics_vec.push_back(( * Mat_ptr).clone());
		//if(displaypics)
			//imshow("Original_Pic", *Mat_ptr);
		m_flipping_queue.PushTask(Mat_ptr);
		m_gray_mirror_queue.PushTask(Mat_ptr);

		// Wait for two tasks to return. Is this that the instructions mean?
		m_output_queue.GetTask();
		m_output_queue.GetTask();

		if (displaypics)
		{
			imshow("Original_Pic", *Mat_ptr);
			imshow("flip_rgb", (*m_flip_rgb_operation.getMat()));
			imshow("gray_mirror", (*m_gray_mirror_operation.getMat()));
			char c = (char)waitKey(25);
		}

		GBR_pics_vec.push_back((* m_flip_rgb_operation.getMat()).clone());
		grayandmir_pics_vec.push_back((* m_gray_mirror_operation.getMat()).clone());

		Mat_ptr = v1.getpic();
	}
	// Stop worker threads.
	m_flipping_queue.PushTask(Stop{});
	m_gray_mirror_queue.PushTask(Stop{});

	m_thread_flipping_pic.join();
	m_thread_gray_mirror.join();

}


void MainClass::stop()
{
	m_thread_flipping_pic.join();
	m_thread_gray_mirror.join();

}

void MainClass::display_pics()
{
	displaypics = 1;
}

