
find_package(Curses)

add_executable(shmfw_editor main_editor.cpp)
target_link_libraries(shmfw_editor tuw_shmfw ${CURSES_LIBRARY})


install(TARGETS shmfw_editor
  # IMPORTANT: Add the executables to the "export-set"
  EXPORT TUWShmFwTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin)
  
