#include "opencv_util.h"
#include <vector>
#include <cstdio>
#include <thread>
#include <string>
#include <unistd.h>
#include <cmath>

Pos c::find(const cv::Mat &image, const cv::Mat &pattern, double similarity)
{
  return Pos();
}

bool c::find(const cv::Mat &image, const cv::Mat &pattern, Pos pos, double similarity)
{
  return false;
}

Color c::get_pixel(const cv::Mat &image, Pos pos)
{
  if(pos.y < 0 || pos.y >= image.rows || pos.x < 0 || pos.x >= image.cols)
  {
    throw std::out_of_range("Position is out of bounds");
  }
  CV_Assert(image.depth()==CV_8U);
  cv::Vec3b bgr = image.at<cv::Vec3b>(pos.y,pos.x);
  Color c;
  c.b = bgr[0];  
  c.g = bgr[1];
  c.r = bgr[2];
  return c;
}

bool c::pixel_color_same(const cv::Mat& image, const Pos& pos, uchar r, uchar g, uchar b)
{
  return pixel_color_same(image, pos, Color{r,g,b});
}

bool c::pixel_color_same(const cv::Mat& image, const Pos& pos, Color col)
{
  return col == get_pixel(image, pos);
}

bool c::pixel_color_similar(const cv::Mat& image, const Pos& pos, uchar r, uchar g, uchar b, double similarity)
{
  return pixel_color_similar(image, pos, Color(r,g,b), similarity);
}

bool c::pixel_color_similar(const cv::Mat& image, const Pos& pos, const Color& col, double similarity)
{
  if(similarity > 1 || similarity <= 0) return false;
  int tolerance = static_cast<int>(UCHAR_MAX-(UCHAR_MAX * similarity) + 1);//the smaller similarity, the bigger the tolerance
  Color pixel = get_pixel(image, pos);
  return std::abs(pixel.r - col.r) <= tolerance &&
         std::abs(pixel.g - col.g) <= tolerance &&
         std::abs(pixel.b - col.b) <= tolerance;

}

cv::Mat c::resize_mat(cv::Mat &src, double scale)
{
  return cv::Mat();
}

void c::draw_rectangle(cv::Mat &img, Pos pos, Size size, int thickness, Color col, int alpha)
{
}
