FILE(GLOB_RECURSE files src/*.c)
add_library(sofa  STATIC ${files})
target_include_directories(sofa PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)