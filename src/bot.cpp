#include "bot.h"

Bot::Bot()
{
  adb::scrcpy_v4l(video_device_path);
  retrieve_frame(); 
}

void Bot::retrieve_frame()
{
  cap >> frame;
}