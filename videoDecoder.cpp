#include "videoDecoder.h"



void videoDecoder::decode(string st)
{
    //VideoCapture cap(st);
    cap_s = new VideoCapture(st);
    if (!cap_s->isOpened()) {
        cout << "Error opening video stream or file" << endl;
        return ;
    }
    /*
    while (1) {
            Mat frame;
            *cap_s >> frame;

            if (frame.empty())
                break;

            mat_vec.push_back(frame);

            //imshow("Frame", frame);

            //break;

            //// Press  ESC on keyboard to exit
            //char c = (char)waitKey(25);
            //if (c == 27)
            //    break;
    }
    cap_s->release();
    destroyAllWindows();*/

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