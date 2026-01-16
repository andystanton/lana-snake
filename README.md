# Lana Snake

An implementation of the retro game Snake in C++. I wrote this as a way of learning C++. It uses the [GLFW library](http://www.glfw.org) for windowing and OpenGL for rendering.

![](http://andystanton.github.io/lana-snake/images/content/1.0/lana-snake.png)

## Requirements

 * A C++11 compiler
 * [CMake >= 3.16](http://www.cmake.org/cmake/resources/software.html)
 * OpenGL

GLFW is fetched automatically during the build.

## Quick Start

Clone the project:

```sh
git clone https://github.com/andystanton/lana-snake.git && cd lana-snake
```

Build and run:

```sh
make run
```

## Build Commands

| Command | Description |
|---------|-------------|
| `make` | Configure and build |
| `make run` | Build and run the game |
| `make clean` | Remove build directory |

## Generating Project Files for IDEs

Generate project files for your IDE using CMake:

```sh
cmake -B build -G "Xcode"              # Xcode
cmake -B build -G "Visual Studio 17"   # Visual Studio 2022
cmake -B build -G "Ninja"              # Ninja
```

See the [CMake documentation](https://cmake.org/cmake/help/latest/manual/cmake-generators.7.html) for a full list of generators.

## Controls

 * Arrow Keys : Move
 * Space : Start / Pause
 * Escape : Quit
