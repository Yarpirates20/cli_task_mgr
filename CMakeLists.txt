cmake_minimum_required(VERSION 3.10)
project(CLITaskManager
        VERSION 1.0
        LANGUAGES CXX)

# Global C++ Standard 
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler Flags
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Werror -pedantic)
endif()

# External Dependencies
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBPQXX REQUIRED libpqxx)

# Define executable
add_executable(${PROJECT_NAME} src/main.cpp src/Database_Manager.cpp src/Task_Manager.cpp)

# Add headers
target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${LIBPQXX_INCLUDE_DIRS})

# Link PostgreSQL libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBPQXX_LIBRARIES})