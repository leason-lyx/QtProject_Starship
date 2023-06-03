# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\star_ship_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\star_ship_autogen.dir\\ParseCache.txt"
  "star_ship_autogen"
  )
endif()
