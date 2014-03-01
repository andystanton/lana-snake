cmake_minimum_required(VERSION 2.8)
project(lana-snake)

set(lana-snake_VERSION_MAJOR 1)
set(lana-snake_VERSION_MINOR 0)

set (
    HEADERS
    src/common/Logger.h
    src/drawing/Alphabet.h
    src/drawing/Gameplay.h
    src/drawing/Palette.h
    src/drawing/Primitive.h
    src/drawing/Screens.h
    src/drawing/Text.h
    src/model/entity/Collidable.h
    src/model/entity/Coordinated.h
    src/model/entity/Drawable.h
    src/model/entity/Entity.h
    src/model/entity/Pickup.h
    src/model/entity/Segment.h
    src/model/entity/Snake.h
    src/model/entity/World.h
    src/model/foundation/Character.h
    src/model/foundation/Colour.h
    src/model/foundation/Vec2d.h
)

set (
    SOURCES
    src/main.cpp
    src/model/foundation/Vec2d.cpp
    src/common/Logger.cpp
    src/drawing/Gameplay.cpp
    src/drawing/Primitive.cpp
    src/drawing/Screens.cpp
    src/drawing/Text.cpp
    src/drawing/Alphabet.cpp
    src/drawing/Palette.cpp
    src/model/entity/Entity.cpp
    src/model/entity/Pickup.cpp
    src/model/entity/Segment.cpp
    src/model/entity/Snake.cpp
    src/model/entity/World.cpp
    src/model/foundation/Character.cpp
    src/model/foundation/Colour.cpp
)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=gnu++11")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++11")
    if (${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
        set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    endif ()
elseif (MSVC)
    # On by default
endif ()

# lana-snake
include_directories(src)

add_executable (
    lana-snake 
    ${SOURCES}
    ${HEADERS}
)

# enable testing - not currently in use but required for 'make test' that travis-ci runs.
enable_testing()

# glfw
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
target_link_libraries(lana-snake glfw ${GLFW_LIBRARIES})
target_link_libraries(lana-snake glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
