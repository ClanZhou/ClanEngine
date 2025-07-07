add_library(Common
    Main.cpp
)

target_link_libraries(Common
    PUBLIC
        glfw
)
