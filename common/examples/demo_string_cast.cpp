#include <iostream>
#include <chrono>
#include <string>
#include <tuw_shmfw/shmfw.hpp>

int main()
{
    
    std::cout << "Compiler version: " << __VERSION__ << std::endl;
    std::cout << "C++ Standard version: " << __cplusplus << std::endl;

    // Get the current time_point from system_clock
    auto timePoint = std::chrono::system_clock::now();

    std::string timeString = ShmFw::to_simple_string(timePoint);

    std::cout << "Time as string using to_simple_string: " <<  timeString << std::endl;

    std::chrono::system_clock::time_point timePointFromString = ShmFw::from_simple_string(timeString);

    std::cout << "Time from string using from_simple_string: " << ShmFw::to_simple_string(timePointFromString) << std::endl;


    return 0;
}