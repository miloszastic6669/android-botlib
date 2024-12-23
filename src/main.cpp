#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "adb.h"
#include "opencv_util.h"
#include "bot.h"

void debug();
using namespace std::chrono;
int main()
{
  int choice;
  std::cout << "1. Start scrcpy\n";
  std::cout << "2. Start bot\n";
  std::cout << "3. Debug\n";
  std::cin >> choice;

  switch (choice)
  {
  case 1:
    adb::scrcpy(0);
    return 0;
  case 2:
    break; 
  case 3:
    debug();
  default:
    break;
  }
  
}

void debug()
{

  adb::scrcpy_v4l("/dev/video4");
  cv::VideoCapture cap("/dev/video4");

  while(true)
  {
    int x,y;
    std::cout << "x=\n";
    std::cin >> x;
    std::cout << "y = \n";
    std::cin >> y;
    cv::Mat img;
    cap >> img;
    Color col = c::get_pixel(img, {x,y});
    std::cout << "Color: r " <<col.r << ", g = " <<col.g <<", b =" << col.b << "\n  ";
  }
}
