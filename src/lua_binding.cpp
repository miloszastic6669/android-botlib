#include "lua_binding.h"

Lua::Lua()
{
  
  lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::string);
  // pos and color structs
  sol::usertype<Pos> pos_type = lua.new_usertype<Pos>("Pos", 
      sol::constructors<Pos(int,int), Pos()>(),
      "x",sol::property(&Pos::get_x, &Pos::set_x),
      "y",sol::property(&Pos::get_y, &Pos::set_y),
      sol::meta_function::to_string, &Pos::get);

  sol::usertype<Color> color_type = lua.new_usertype<Color>("Color",
      sol::constructors<Color(int,int,int), Color()>(),
      "r", sol::property(&Color::get_r, &Color::set_r),
      "g", sol::property(&Color::get_g, &Color::set_g),
      "b", sol::property(&Color::get_b, &Color::set_b),
      sol::meta_function::to_string, &Color::get);

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
  lua["get_pixel_color"] = [](uintptr_t image_ptr, sol::table pos_table)
  {
    Pos pos;
    pos.x = pos_table["x"].get<int>();
    pos.y = pos_table["y"].get<int>();
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    Color col;
    sol::table col_table;
    try
    {
      col = c::get_pixel_color(image, pos);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return col_table;
    }
    col_table["r"] = col.r;
    col_table["g"] = col.g;
    col_table["b"] = col.b;
    return col_table;
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

  lua["is_pixel_color_similar"] = [](uintptr_t image_ptr, Pos pos, Color col, double similarity)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::is_pixel_color_similar(image, pos, col, similarity);
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return false;
    }
  };

  lua["is_pixel_color_similar_rgb"] = [](uintptr_t image_ptr, Pos pos, short r, short g, short b, double similarity)
  {
    const cv::Mat& image = *(reinterpret_cast<cv::Mat*>(image_ptr));
    try
    {
      return c::is_pixel_color_similar(image, pos, r, g, b, similarity);
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
  if(!script.valid())
  {
    sol::error err = script;
    std::string error_msg = "Failed loading in the script " + filename + ", with the following error: " + err.what() +"\n";
    throw std::runtime_error(error_msg);
    return false;
  }
  try
  {
    sol::protected_function_result result = script();
    if(!result.valid())
    {
      sol::error err = result;
      std::cerr << "Runtime error during Lua execution: " << err.what() << std::endl;
      return false;
    }
    
  }
  catch(const sol::error& e)
  {
    std::cerr << "C++ Exception caught during Lua execution: " << e.what() << '\n';
    return false;
  }
  
  return true;

}

