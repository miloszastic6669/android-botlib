#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>

namespace util
{
std::string get_time();


//dur in ms
void sleep_for(int dur);

}