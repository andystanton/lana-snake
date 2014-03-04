# Lana Snake [![Build Status](https://travis-ci.org/andystanton/lana-snake.png?branch=master)](https://travis-ci.org/andystanton/lana-snake) [![Stories in Ready](https://badge.waffle.io/andystanton/lana-snake.png?label=ready&title=Ready)](https://waffle.io/andystanton/lana-snake)

An implementation of the retro game Snake in C++. I wrote this as a way of learning C++. It makes use of the [GLFW library](http://www.glfw.org) and [CMake](http://www.cmake.org/) to build the project.

![](http://andystanton.github.io/lana-snake/images/content/1.0/lana-snake.png)

## Requirements

 * A C++11 compiler
 * [CMake >= 2.8](http://www.cmake.org/cmake/resources/software.html)

## Quick Start

Clone the project:

```sh
git clone https://github.com/andystanton/lana-snake.git --recursive && cd lana-snake
```

Run the following commands to generate the makefile and build:

```sh
./configure
make
```

This will create the lana-snake executable in the project directory.

## Generating project files for your IDE

Run the following command to generate the project files for your IDE:

```sh
cmake . -G {ide_name}
```

For more information on CMake's project generators and a full list of supported platforms and IDEs, see the [documentation](http://www.cmake.org/Wiki/CMake_Generator_Specific_Information).

## Controls

 * Left Arrow : Rotate Left
 * Right Arrow : Rotate Right
 * Space : Pause
