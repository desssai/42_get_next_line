# get-next-line

## Overview 

Yet another beginner project at ecole 42 course.\
The aim of the project is to get accustomed to how file descrpters work, learn what static variables are, train in C lamguage.\
The `get_next_line` function consecutively reads a line from a file descriptor and returns it until it comes across EOF.

## Usage

1. Clone the repository in your project working directory.
2. Include `get_next_line.h` or `get_next_line_bonus.h` in your header.
3. Compile your C code using GCC. Don't forget to use get_next_line source files when compiling.

## Mandatory part

The function uses a static buffer that stores N bytes of characters from a file descriptor.\
Each call to the function moves the buffer towards the end of thge file's contents.
When a newline character is found in buffer - the function returns a string of characters
between the previous and the current newlines.

## Bonus part

The bonus part `get_next_line` is able to read from a different file descriptor per call without losing 
the reading thread of each file descriptor or returning a line from another fd.
This is managed by creating an array of pointers to buffers that is size of `OPEN_MAX`
(a constant of maximum possible amount of file descriptors open at the same time that differs from one system to another).
