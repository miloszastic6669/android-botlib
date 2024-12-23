#include "util.h"

std::string util::get_time()
{ 
  std::time_t now = std::time(nullptr);
  std::tm* local_time = std::localtime(&now);
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << local_time->tm_hour << "-"
      << std::setw(2) << std::setfill('0') << local_time->tm_min << "-"
      << std::setw(2) << std::setfill('0') << local_time->tm_sec;

  return oss.str();
}


//dur in ms
void util::sleep_for(int dur)
{
  std::this_thread::sleep_for(std::chrono::milliseconds(dur));
}
