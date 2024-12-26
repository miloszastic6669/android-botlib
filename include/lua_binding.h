#include <lua.hpp>
#include <string>
#include "adb.h"
#include "opencv_util.h"


class Lua
{
public:
  Lua();
  ~Lua();
  
  bool initialize();
  bool load_script(const std::string& filename);
  void executeScript();
  void register_func(const std::string& name, lua_CFunction func);  

 private:
  lua_State* L;
  


};



