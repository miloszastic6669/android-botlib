#pragma once
#include <opencv2/opencv.hpp>
#include "util.h"
#include "adb.h"


class Bot
{
private:
  const std::string video_device_path = "/dev/video4";
  cv::VideoCapture cap = cv::VideoCapture(video_device_path.c_str());
  cv::Mat frame = cv::Mat();

public:
  Bot();
  void retrieve_frame();
  



};