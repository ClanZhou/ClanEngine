cmake_minimum_required (VERSION 3.20) 
project (ClanEngine)

set (CMAKE_CXX_STANDARD 20)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Manager")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")
include_directories("${PROJECT_SOURCE_DIR}/RHI")
include_directories("${PROJECT_SOURCE_DIR}/Platform")

add_subdirectory(Framework)
add_subdirectory(Platform)
add_subdirectory(RHI)