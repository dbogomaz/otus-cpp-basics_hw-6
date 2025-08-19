cmake_minimum_required(VERSION 3.10.0)

project(myContainers VERSION 0.1.0 LANGUAGES C CXX)

set(SOURCE 
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)