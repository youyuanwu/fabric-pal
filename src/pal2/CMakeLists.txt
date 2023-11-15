set (CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCES
pal.c
pal.h
)


add_library(fabric_pal SHARED ${SOURCES})
target_include_directories(fabric_pal 
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)