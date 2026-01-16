cmake_minimum_required(VERSION 3.16)
project(lana-snake VERSION 1.0.0 LANGUAGES CXX)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Fetch GLFW
include(FetchContent)
FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.4
)

# GLFW options - disable examples/tests/docs we don't need
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

# Source files
set(SOURCES
    src/main.cpp
    src/common/Logger.cpp
    src/drawing/Alphabet.cpp
    src/drawing/Gameplay.cpp
    src/drawing/Palette.cpp
    src/drawing/Primitive.cpp
    src/drawing/Screens.cpp
    src/drawing/Text.cpp
    src/model/entity/Entity.cpp
    src/model/entity/Pickup.cpp
    src/model/entity/Segment.cpp
    src/model/entity/Snake.cpp
    src/model/entity/World.cpp
    src/model/foundation/Character.cpp
    src/model/foundation/Colour.cpp
    src/model/foundation/Vec2d.cpp
)

# Create executable
add_executable(lana-snake ${SOURCES})

# Include directories
target_include_directories(lana-snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Link libraries
target_link_libraries(lana-snake PRIVATE
    glfw
    OpenGL::GL
    OpenGL::GLU
)

# macOS-specific settings
if(APPLE)
    set_target_properties(lana-snake PROPERTIES
        MACOSX_BUNDLE TRUE
        MACOSX_BUNDLE_BUNDLE_NAME "Lana Snake"
        MACOSX_BUNDLE_GUI_IDENTIFIER "com.lana-snake.game"
        MACOSX_BUNDLE_BUNDLE_VERSION "${PROJECT_VERSION}"
        MACOSX_BUNDLE_SHORT_VERSION_STRING "${PROJECT_VERSION}"
    )
endif()

# Enable testing (for CI compatibility)
enable_testing()
