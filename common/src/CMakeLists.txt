configure_file(config.h.in "${CMAKE_CURRENT_BINARY_DIR}/config.h" @ONLY)

add_library(tuw_shmfw 
  shmfw.cpp
  handler.cpp
  header.cpp
  variable.cpp
  handler_object.cpp
  string_cast.cpp
)

find_package (Boost REQUIRED COMPONENTS date_time thread program_options )
TARGET_LINK_LIBRARIES( tuw_shmfw LINK_PUBLIC ${Boost_LIBRARIES} )

install(TARGETS tuw_shmfw
  # IMPORTANT: Add the tuw_shmfw library to the "export-set"
  EXPORT TUWShmFwTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/tuw_shmfw"
    COMPONENT dev)
