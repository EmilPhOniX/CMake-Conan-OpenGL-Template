cmake_minimum_required(VERSION 3.15)
project(ProjectName)

# Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Force libc++ (important sur macOS/Clang)
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

# Conan toolchain
if(EXISTS ${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
    include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)
endif()

# Find dependencies from Conan
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Handle OpenGL (different on macOS vs others)
if(APPLE)
    find_library(OpenGL_LIB OpenGL)
else()
    find_package(OpenGL REQUIRED)
endif()

# Sources
set(SOURCES
    src/main.cpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries
if(APPLE)
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        glfw
        GLEW::GLEW
        ${OpenGL_LIB}
    )
else()
    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        glfw
        GLEW::GLEW
        OpenGL::GL
    )
endif()

# Includes
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
