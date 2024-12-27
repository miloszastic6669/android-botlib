#include "opencv_util.h"
#include <vector>
#include <cstdio>
#include <thread>
#include <string>
#include <unistd.h>
#include <cmath>

Pos c::find_pattern(const cv::Mat& image, const cv::Mat &pattern, double similarity)
{
    Pos result = {-1, -1}; // Initialize to invalid position

    if (image.empty() || pattern.empty() || similarity < 0.0 || similarity > 1.0) {
        throw std::runtime_error("image or pattern empty or invalid similarity!");
        return result; // Return invalid position if inputs are invalid.
    }
    if (pattern.cols > image.cols || pattern.rows > image.rows){
        throw std::runtime_error("pattern bigger than image!");
        return result; // Return invalid position if pattern is bigger than image
    }

    cv::Mat result_mat;
    cv::matchTemplate(image, pattern, result_mat, cv::TM_CCOEFF_NORMED);

    double maxVal;
    cv::Point maxLoc;
    cv::minMaxLoc(result_mat, nullptr, &maxVal, nullptr, &maxLoc);

    if (maxVal >= similarity) {
        result.x = maxLoc.x;
        result.y = maxLoc.y;
    }

    return result;
}

bool c::is_pattern_at(const cv::Mat& image, const cv::Mat &pattern, Pos pos, double similarity)
{
  
}

Color c::get_pixel_color(const cv::Mat& image, Pos pos)
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

bool c::is_pixel_color_equal(const cv::Mat& image, const Pos& pos, short r, short g, short b)
{
  return is_pixel_color_equal(image, pos, Color{r,g,b});
}

bool c::is_pixel_color_equal(const cv::Mat& image, const Pos& pos, Color col)
{
  return col == get_pixel_color(image, pos);
}

bool c::is_pixel_color_similar(const cv::Mat& image, const Pos& pos, short r, short g, short b, double similarity)
{
  return is_pixel_color_similar(image, pos, Color(r,g,b), similarity);
}

bool c::is_pixel_color_similar(const cv::Mat& image, const Pos& pos, const Color& col, double similarity)
{
  if(similarity > 1 || similarity <= 0) return false;
  int tolerance = static_cast<int>(UCHAR_MAX-(UCHAR_MAX * similarity) + 1);//the smaller similarity, the bigger the tolerance
  Color pixel = get_pixel_color(image, pos);
  return std::abs(pixel.r - col.r) <= tolerance &&
         std::abs(pixel.g - col.g) <= tolerance &&
         std::abs(pixel.b - col.b) <= tolerance;
}

void c::resize_image(cv::Mat& src, double scale)
{
  return;
}

void c::draw_rectangle(cv::Mat &img, Pos pos, Size size, int thickness, Color col, int alpha)
{
  cv::Mat overlay;
  img.copyTo(overlay);
  cv::Scalar color(col.r, col.g, col.b);
  cv::rectangle(overlay, cv::Rect(pos.x, pos.y, size.x, size.y), color, thickness);
  cv::addWeighted(overlay, alpha / 255.0, img, 1 - alpha / 255.0, 0, img);
}
//scrcpy_v4l() has to be called before instantiating a Mats obj
c::Mats::Mats(const std::string& video_device_path)
{
  cap = cv::VideoCapture(video_device_path.c_str());
  mats.emplace_back();
  update_screen_mat();
}

cv::Mat* c::Mats::get_screen_mat_ptr()
{
  return &mats[0];
}

cv::Mat* c::Mats::add_mat_from_file(const std::string &filename)
{
  mats.emplace_back(cv::imread(filename));
  return &mats[mats.size() - 1];
}

void c::Mats::update_screen_mat()
{
  cap >> mats[0];
}
