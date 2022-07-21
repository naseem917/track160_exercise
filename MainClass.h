#pragma once
#include "videoDecoder.h"
#include "flipRGB.h"
#include "grayMir.h"
#include <chrono>
#include <thread>
#include <variant>
#include "task_queue.h"

// This should represent one image to work with
class Image {};

class MainClass
{
public:
/*	MainClass()
	{
	}*/
	void start(vector<Mat>& Original_pics_vec, vector<Mat>& GBR_pics_vec, vector<Mat>& grayandmir_pics_vec, string st);
	void stop();

	void display_pics();

	

private:
	videoDecoder v1;
	flipRGB m_flip_rgb_operation;
	grayMir m_gray_mirror_operation;

	std::thread m_thread_flipping_pic;
	TaskQueue<std::variant<Mat*, Stop>> m_flipping_queue;

	std::thread m_thread_gray_mirror;
	TaskQueue<std::variant<Mat*, Stop>> m_gray_mirror_queue;

	// Task write that they are done here.
	// TODO: What about the owenership of the returned Matrix? Probably just a pointer since you are not allowed to allocate new stuff
	TaskQueue<Mat*> m_output_queue;

	bool displaypics;
};
