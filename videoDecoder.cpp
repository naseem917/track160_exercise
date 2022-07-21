#include "videoDecoder.h"



void videoDecoder::decode(string st)
{

    cap_s = new VideoCapture(st);
    if (!cap_s->isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return ;
    }
}


Mat* videoDecoder::getpic()
{
    *cap_s >> curr_pic;
    if (curr_pic.empty())
    {
        cap_s->release();
        return NULL;
    }
    return &curr_pic;
}