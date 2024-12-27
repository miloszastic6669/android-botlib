#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "adb.h"
#include "opencv_util.h"
#include "bot.h"
#include "test.h"
#include "lua_binding.h"



void debug();

int main()
{
  while (true)
  {
    int choice;
    std::cout << "1. Start scrcpy\n";
    std::cout << "3. Debug\n";
    std::cin >> choice;


    switch (choice)
    {
    case 1:
      adb::scrcpy(0);
      return 0;
    case 3:
      debug();
    default:
      break;
    } 
  }
}

void debug()
{
  adb::scrcpy_v4l();
  util::sleep_for(1000);
  Lua lua;
  while (true)
  {
    int choice;
    std::cout << "1 to start script, 0 to stop\n";
    std::cin >> choice;
    if(choice == 0) return;
    try
    {
      lua.load_script("lua/hello.lua");  
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << '\n';
    }
  }
  
}
