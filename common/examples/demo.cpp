/**
 * @author Markus Bader <markus.bader@tuwien.ac.at>
 **/

#include <iostream>
#include <tuw_shmfw/shmfw.hpp>
#include <chrono>

int main(int argc, char *argv[]){
        
    ShmFw::Parameter params;
    std::cout << "Compiler version: " << __VERSION__ << std::endl;

    #ifdef __cplusplus
        std::cout << "C++ Standard version: " << __cplusplus << std::endl;
    #else
        std::cout << "C++ Standard version: Not detected" << std::endl;
    #endif
    
    std::chrono::system_clock::time_point t;

    std::cout << "Demo tuw_shmfw says: " << std::endl;
    return 0;
}

