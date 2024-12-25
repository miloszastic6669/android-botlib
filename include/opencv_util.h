#pragma once
#include <opencv2/opencv.hpp>
#include "util.h"
#include "adb.h"

struct Pos
{
  int x,y;
  bool operator==(const Pos& other) const 
  {
    return other.x == x && other.y == y;
  }
  bool operator!=(const Pos& other) const 
  {
    return other.x != x || other.y != y;
  }

  friend std::ostream& operator<<(std::ostream& os, const Pos& p)
  {
    os << "("<< p.x << ","<< p.y <<")";
    return os;
  }

  Pos(int x, int y)
  {
    this->x = x;
    this->y = y;
  }

  Pos()
  {
    this->x = this->y = 0;
  }
};
using Size = Pos;

struct Color
{
  uchar short r,g,b;
  bool operator==(const Color& other) const 
  {
    return r == other.r && g == other.g && b == other.b;
  }
  bool operator!=(const Color& other) const
  {
    return r != other.r || g != other.g || b != other.b;
  }
  friend std::ostream& operator<<(std::ostream& os, const Color& c)
  {
    os << "("<< c.r << ","<< c.g << "," << c.b << ")";
    return os;
  }
  Color(int r, int g, int b)
  {
    this->r = uchar(r);
    this->g = uchar(g);
    this->b = uchar(b);
  }
  Color()
  {
    r = 0; 
    g = 0;
    b = 0;
  }

  std::string get()
  {
    std::string ret = "(" + std::to_string(r) + "," + std::to_string(g) + "," +std::to_string(b) + ")";
    return ret;
  }

};

namespace c
{
  Pos find(const cv::Mat& image, const cv::Mat& pattern, double similarity = 1.0);
  bool find(const cv::Mat& image, const cv::Mat& pattern, Pos pos, double similarity = 1.0);
  Color get_pixel(const cv::Mat& image, Pos pos);
  bool pixel_color_same(const cv::Mat& image, const Pos& pos, uchar r, uchar g, uchar b);
  bool pixel_color_same(const cv::Mat& image, const Pos& pos, Color col);
  bool pixel_color_similar(const cv::Mat& image, const Pos& pos, uchar r, uchar g, uchar b, double similarity);
  bool pixel_color_similar(const cv::Mat& image, const Pos& pos, const Color& col, double similarity);
  cv::Mat resize_mat(cv::Mat& src, double scale);
  void draw_rectangle(cv::Mat& img, Pos pos, Size size, int thickness, Color col, int alpha);




}