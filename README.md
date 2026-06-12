# 2d-mini-project
# 2D Graphics Editor in C

## Overview

This project is a simple text-based 2D Graphics Editor developed in C. It uses a 2D character array as a canvas and allows users to draw basic geometric shapes such as lines, rectangles, triangles, and circles. Users can also delete parts of the drawing, clear the canvas, and display the current picture.

## Features

* Draw Line
* Draw Rectangle
* Draw Triangle
* Draw Circle
* Delete Area
* Display Canvas
* Clear Canvas
* Menu-Driven Interface

## Technologies Used

* C Programming Language
* Standard C Libraries

  * stdio.h
  * stdlib.h
  * math.h

## Program Structure

The program uses a 2D character array (`canvas`) to represent the drawing area.

### Functions Implemented

* `clearCanvas()` – Clears the drawing canvas.
* `displayCanvas()` – Displays the canvas on the screen.
* `drawLine()` – Draws a line between two points.
* `drawRectangle()` – Draws a rectangle.
* `drawTriangle()` – Draws a triangle.
* `drawCircle()` – Draws a circle.
* `deleteArea()` – Deletes a selected area from the canvas.

## How to Compile

For GCC Compiler:

```bash
gcc graphics_editor.c -o graphics_editor -lm
```

## How to Run

```bash
./graphics_editor
```

## Sample Menu

```text
===== 2D Graphics Editor =====
1. Draw Line
2. Draw Rectangle
3. Draw Triangle
4. Draw Circle
5. Delete Area
6. Display Canvas
7. Clear Canvas
0. Exit
```

## Learning Outcomes

* Understanding of 2D arrays in C.
* Implementation of geometric drawing algorithms.
* Use of functions for modular programming.
* Menu-driven program development.
* Basic graphics representation using characters.

## Future Improvements

* Modify existing objects.
* Save and load drawings from files.
* Add colors and different drawing symbols.
* Support object selection and movement

