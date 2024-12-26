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
  short r,g,b;
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
    this->r = r;
    this->g = g;
    this->b = b;
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
  //image searching/matching
  Pos find_pattern(const cv::Mat& image, const cv::Mat& pattern, double min_similarity = 1.0);
  bool is_pattern_at(const cv::Mat& image, const cv::Mat& pattern, Pos pos, double similarity = 1.0);
  
  //pixel access
  Color get_pixel_color(const cv::Mat& image, Pos pos);
  bool is_pixel_color_equal(const cv::Mat& image, const Pos& pos, short r, short g, short b);
  bool is_pixel_color_same(const cv::Mat& image, const Pos& pos, Color col);
  bool is_pixel_color_same(const cv::Mat& image, const Pos& pos, short r, short g, short b, double similarity);
  bool is_pixel_color_same(const cv::Mat& image, const Pos& pos, const Color& col, double similarity);

  //image manipulation
  void resize_image(cv::Mat& src, double scale);
  void draw_rectangle(cv::Mat& img, Pos pos, Size size, int thickness, Color col, int alpha = 255);
}