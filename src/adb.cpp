#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include "adb.h"



//bit rate in Mbps
int adb::scrcpy(int flags)
{
  std::string cmd = "scrcpy";
  
  if(flags & PRINT_FPS)
    cmd += " --print-fps";
  
  if(flags & NO_AUDIO)

    cmd += " --no-audio";
  
  if(flags & NO_VIDEO)
    cmd += " --no-video";

  if(flags & NO_WINDOW)
    cmd += " --no-window";
  
  if(flags & RECORD)
  {
    cmd += " -r recording";
    cmd += util::get_time();
    cmd += ".mp4";
  }
  return system(cmd.c_str());
}

int adb::scrcpy_v4l(const std::string& video_device_path, bool show_window)
{
  std::string cmd = "scrcpy";
  if(!show_window)
    cmd += " --no-window " 
  " -b 16M --v4l2-sink=" + video_device_path + " &";
  return system(cmd.c_str());
}

int adb::save_screen(std::string filename)
{
  std::string cmd = "adb exec-out screencap -p > " + filename;
  return system(cmd.c_str());
}

int adb::click(int x, int y)
{
  std::string cmd = "adb shell input tap " + std::to_string(x) + " " + std::to_string(y);
  return system(cmd.c_str());
}

int adb::swipe(int x1, int y1, int x2, int y2, int duration)
{
  std::string cmd = "adb shell input touchscreen swipe " + std::to_string(x1) + " " + 
                                                           std::to_string(y1) + " " +
                                                           std::to_string(x2) + " " +
                                                           std::to_string(y2) + " " +
                                                           std::to_string(duration);
  return system(cmd.c_str());
}



