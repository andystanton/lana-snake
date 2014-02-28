cmake_minimum_required(VERSION 2.8)
project(lana-snake)

set(lana-snake_VERSION_MAJOR 1)
set(lana-snake_VERSION_MINOR 0)

IF (CMAKE_COMPILER_IS_GNUCXX)
  SET (CMAKE_CXX_FLAGS "-std=gnu++11")
ELSEIF (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++11")
  IF(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
  ENDIF ()
ELSEIF (MSVC)
  # On by default
ENDIF ()

# lana-snake
include_directories(src)

add_executable(
            lana-snake 
            src/main.cpp
            src/model/foundation/Vec2d.cpp
            src/common/Logger.cpp
            src/drawing/Gameplay.cpp
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
)

# enable testing - not currently in use but required for 'make test' that travis-ci runs.
enable_testing()

# glfw
add_subdirectory(lib/glfw)
include_directories(lib/glfw/include)
target_link_libraries(lana-snake glfw ${GLFW_LIBRARIES})
target_link_libraries(lana-snake glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})

