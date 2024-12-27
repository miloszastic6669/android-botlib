#pragma once
#include <sol/sol.hpp>
#include <lua.hpp>
#include <string>
#include <util.h>
#include "adb.h"
#include "opencv_util.h"
#include <cstdint>

class Lua
{
public:
  Lua();
  //load and execute
  bool load_script(const std::string& filename);

private:
  sol::state lua;
  sol::load_result script;
  c::Mats mats;
  




};



