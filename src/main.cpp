#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include "adb.h"
#include "opencv_util.h"
#include "bot.h"
#include "test.h"


void debug();

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
  test::run_all();
}
