/***************************************************************************
 *   Software License Agreement (BSD License)                              *
 *   Copyright (C) 2024 by Markus Bader <markus.bader@tuwien.ac.at>        *
 *                                                                         *
 *   Redistribution and use in source and binary forms, with or without    *
 *   modification, are permitted provided that the following conditions    *
 *   are met:                                                              *
 *                                                                         *
 *   1. Redistributions of source code must retain the above copyright     *
 *      notice, this list of conditions and the following disclaimer.      *
 *   2. Redistributions in binary form must reproduce the above copyright  *
 *      notice, this list of conditions and the following disclaimer in    *
 *      the documentation and/or other materials provided with the         *
 *      distribution.                                                      *
 *   3. Neither the name of the copyright holder nor the names of its      *
 *      contributors may be used to endorse or promote products derived    *
 *      from this software without specific prior written permission.      *
 *                                                                         *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
 *   FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
 *   COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *
 *   INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
 *   BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
 *   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
 *   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY *
 *   WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE           *
 *   POSSIBILITY OF SUCH DAMAGE.                                           *
 ***************************************************************************/

#ifndef SHARED_LEXICAL_CAST_HPP
#define SHARED_LEXICAL_CAST_HPP

#include <chrono>
#include <iostream>
#include <iomanip>
#include <string>
#include <boost/lexical_cast.hpp>

namespace boost
{
    template <typename TargetType, typename Clock, typename Duration>
    TargetType lexical_cast_not_working(const std::chrono::time_point<Clock, Duration> &timePoint)
    {
        // Convert time_point to a time_t representing the epoch time
        std::ostringstream ss;
        ss << std::put_time(&timePoint, "%Y-%m-%d %H:%M:%S.%f");
        return ss.str();
    }
    template <typename TargetType, typename Clock, typename Duration>
    TargetType lexical_cast(const std::chrono::time_point<Clock, Duration> &timePoint)
    {
        // Convert time_point to a time_t representing the epoch time
        std::time_t time = std::chrono::system_clock::to_time_t(timePoint);

        // Convert the time_t to a tm struct
        std::tm *timeInfo = std::localtime(&time);

        // Get the fractional part of seconds
        auto fractionalSeconds = timePoint.time_since_epoch() % std::chrono::seconds(1);

        // Convert time_t to a string in a simple format
        char buffer[80]; // Choose an appropriate buffer size
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", std::localtime(&time));
        return std::string(buffer);
    }
    template <typename TargetType>
    TargetType lexical_cast(const std::string &time_string)
    {
        std::tm tm = {};
        std::istringstream ss(time_string);

        // Parse the date and time from the string
        ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");

        if (ss.fail())
        {
            throw std::runtime_error("Failed to parse date and time from string");
        }

        // Convert tm struct to time_t
        std::time_t time = std::mktime(&tm);

        // Convert time_t to time_point
        return std::chrono::system_clock::from_time_t(time);
    }
}

#endif // SHARED_LEXICAL_CAST_HPP
