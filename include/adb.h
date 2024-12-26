#pragma once
#include <iostream>
#include <cstdlib>
#include "util.h"

#define VDP "/dev/video4"

namespace adb
{
enum ScrcpyFlags
{
  PRINT_FPS = 1 << 0,
  NO_VIDEO = 1 << 1,
  NO_AUDIO = 1 << 2,
  NO_WINDOW = 1 << 3,
  RECORD = 1 << 4,
};
int scrcpy(int flags);
int scrcpy_v4l(const std::string& video_device_path = VDP, bool show_window = false);

int save_screen(std::string);

int click(int x, int y);
int swipe(int x1, int y1, int x2, int y2, int duration);

}