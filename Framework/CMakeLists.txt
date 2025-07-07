add_subdirectory(Common)
add_subdirectory(Manager)

add_library(Framework INTERFACE)

target_link_libraries(Framework INTERFACE
    Common
    Manager
    Third
)

