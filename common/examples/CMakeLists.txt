
#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_executable(shmfw_demo demo.cpp)
target_link_libraries(shmfw_demo tuw_shmfw)

add_executable(demo_string_cast demo_string_cast.cpp)
target_link_libraries(demo_string_cast tuw_shmfw)

add_executable(shmfw_usage_var usage_var.cpp)
target_link_libraries(shmfw_usage_var tuw_shmfw)

add_executable(shmfw_usage_vector usage_vector.cpp)
target_link_libraries(shmfw_usage_vector tuw_shmfw)

install(TARGETS shmfw_demo demo_string_cast shmfw_usage_var shmfw_usage_vector
  # IMPORTANT: Add the executables to the "export-set"
  EXPORT TUWShmFwTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
  
