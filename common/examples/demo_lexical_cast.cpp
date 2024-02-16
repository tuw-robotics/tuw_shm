#include <iostream>
#include <chrono>
#include <string>
#include <tuw_shmfw/shmfw.hpp>
#include <tuw_shmfw/lexical_cast.hpp>

int main()
{
    std::cout << "Compiler version: " << __VERSION__ << std::endl;
    std::cout << "C++ Standard version: " << __cplusplus << std::endl;

    // Get the current time_point from system_clock
    auto timePoint = std::chrono::system_clock::now();

    // Convert the time point to a string using our custom to_string function
    std::string timeString = boost::lexical_cast<std::string>(timePoint);

    // Output the converted string
    std::cout << "Time as string using lexical_cast: " << timeString << std::endl;
    // Output the converted string
    std::cout << "Time as string using to_simple_string: " << ShmFw::to_simple_string(timePoint) << std::endl;

    std::chrono::system_clock::time_point timePointFromString = ShmFw::from_simple_string(timeString);

    std::cout << "Time from string using from_simple_string: " << ShmFw::to_simple_string(timePointFromString) << std::endl;

    timePointFromString = boost::lexical_cast<std::chrono::system_clock::time_point>(timeString);

    std::cout << "Time from string using lexical_cast: " << ShmFw::to_simple_string(timePointFromString) << std::endl;


    return 0;
}