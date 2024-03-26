# CMakeList.txt : CMake project for Assignment1C++, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Assignment1C++ "Assignment1C++.cpp" "Assignment1C++.h" "Game.cpp"    "Game.h" "ItemManager.cpp" "ItemManager.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Assignment1C++ PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
