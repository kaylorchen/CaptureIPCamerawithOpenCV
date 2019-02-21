#include <iostream>
#include "opencv2/opencv.hpp"

int main() {
    cv::VideoCapture vcap;
    cv::Mat image;
    const std::string videoStreamAddress = "rtsp://192.168.111.226:554/user=admin&password=&channel=1&stream=0.sdp?real_stream";
    if(!vcap.open(videoStreamAddress)) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;

    }
    int counter = 0;
    for (;;) {
        counter++;
        if (!vcap.read(image))
        {
            std::cout << "No Frame" << std::endl;
            cv::waitKey();
        }
        cv::imshow("Output Window", image);
        double  rate = vcap.get(CV_CAP_PROP_FPS);
        std::cout << "FPS = " << rate << std::endl;
        if(cv::waitKey(1) >= 0) break;
    }
        return 0;
}