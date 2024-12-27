#include "lua_binding.h"

Lua::Lua()
{
  lua.open_libraries(sol::lib::base, sol::lib::math);


  // pos and color structs
  sol::usertype<Pos> pos_type = lua.new_usertype<Pos>("Pos", 
      sol::constructors<Pos(int,int), Pos()>());
  pos_type["get"] = &Pos::get;

  sol::usertype<Color> color_type = lua.new_usertype<Color>("Color",
      sol::constructors<Color(int,int,int), Color()>());
  color_type["get"] = &Color::get;
  //init C Function bindings
  
  //c::Mats
  lua["get_screen_mat_ptr"] = [this]()
  {
    //treat cv::Mat* as uintptr_t:
    return reinterpret_cast<uintptr_t>(mats.get_screen_mat_ptr());
  };

  lua["add_mat_from_file"] = &c::Mats::add_mat_from_file;
  lua["update_screen_mat"] = &c::Mats::update_screen_mat;
  
  //image searching
  lua["find_pattern"] = [](uintptr_t image_ptr, uintptr_t pattern_ptr, double similarity = 1.0)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    const cv::Mat& pattern = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::find_pattern(image, pattern, similarity);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return Pos(-1,-1);
    }
    
  };

  lua["is_pattern_at"] = [](uintptr_t image_ptr, uintptr_t pattern_ptr, Pos pos, double similarity = 1.0)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    const cv::Mat& pattern = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::is_pattern_at(image, pattern, pos, similarity);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return false;
    }
    
  };
  //pixel access
  lua["get_pixel_color"] = [](uintptr_t image_ptr, Pos pos)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::get_pixel_color(image, pos);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return Color(-1,-1,-1);
    }
  };

  lua["is_pixel_color_equal"] = [](uintptr_t image_ptr, Pos pos, Color col)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::is_pixel_color_equal(image, pos, col);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return false;
    }
    
  };

  lua["is_pixel_color_equal_rgb"] = [](uintptr_t image_ptr, Pos pos, short r, short g, short b)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::is_pixel_color_equal(image, pos, r,g,b);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return false;
    }
    
  };




}


bool Lua::load_script(const std::string &filename)
{ 
  script = lua.load_file(filename);
  if(!script)
  {
    sol::error err = script;
    std::string error_msg = "Failed loading in the script " + filename + ", with the following error: " + err.what() +"\n";
    throw std::runtime_error(error_msg);
    return false;
  }
  script();
  return true;

}

