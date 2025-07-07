cmake_minimum_required (VERSION 3.20) 
project (ClanEngine)

set (CMAKE_CXX_STANDARD 20)

include(FetchContent)
# glfw
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_WAYLAND OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

include_directories("${PROJECT_SOURCE_DIR}/Framework/Manager")
include_directories("${PROJECT_SOURCE_DIR}/Framework/Interface")
include_directories("${PROJECT_SOURCE_DIR}/RHI")
include_directories("${PROJECT_SOURCE_DIR}/Platform")

add_subdirectory(Framework)
add_subdirectory(Platform)
add_subdirectory(RHI)