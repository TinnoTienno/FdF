# FDF – 3D Wireframe Renderer

[![42 School](https://img.shields.io/badge/42-School-000000?style=flat&logo=42&logoColor=white)](https://42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Graphics](https://img.shields.io/badge/Graphics-MiniLibX-green)](https://github.com/42Paris/minilibx-linux)

A 3D wireframe visualization tool that transforms heightmap data into stunning isometric projections. Built as part of the 42 School curriculum to explore graphics programming, mathematical transformations, and efficient rendering techniques.

## Project Overview

FDF reads a file containing altitude coordinates and generates a real-time 3D wireframe representation. This project demonstrates:

- **File parsing and validation** - Robust input handling with error checking
- **3D mathematical transformations** - Isometric projection and matrix operations  
- **Graphics programming** - Real-time rendering with MiniLibX
- **Memory management** - Efficient data structures and cleanup

## Input File Format

The input file contains a grid of integers representing terrain altitudes:

```
1 0 0 1
0 1 2 0
0 0 0 0
```

**Format specifications:**
- Each line represents a row in the Y-axis
- Each number represents the height (Z) at position (X,Y)
- Values are space-separated
- Both positive and negative altitudes supported
- Invalid formats are automatically rejected

## Core Technologies

### Geometric Transformations
- **Isometric projection**: Converts 3D coordinates to 2D screen space
- **Linear transformations**: Translation, rotation, and scaling operations
- **Color interpolation**: Smooth RGB gradients based on altitude

### Rendering Pipeline
- **Vertex processing**: Efficient coordinate transformation
- **Line rasterization**: Bresenham's algorithm for wireframe drawing
- **Color mapping**: Dynamic altitude-based coloring

## Enhanced Features

### Visual Improvements
- **Smooth color gradients** - Dynamic altitude-based coloring with RGB interpolation
- **Optimized rendering** - Single-pass calculation with coordinate caching
- **Real-time interaction** - Responsive user controls

### Performance Optimizations
- **Zero reprocessing** - Each vertex calculated once and stored
- **Efficient memory usage** - Minimal allocations during rendering
- **Fast transformation** - Optimized matrix operations

## Future Enhancements

### Multithreading
- Parallel processing of map segments
- Thread-based coordinate calculation
- Improved performance for large datasets

### Graphics Upgrades
- **OpenGL migration** - Modern GPU-accelerated rendering
- **Additional projections** - Perspective, cavalier, and custom views
- **Enhanced interactions** - Mouse controls and dynamic scaling

## Installation & Usage

### Prerequisites
- GCC compiler
- Make
- X11 development libraries (Linux)
- MiniLibX library

### Building
```bash
# Clone the repository
git clone https://github.com/TinnoTienno/FdF.git
cd FdF

# Compile the project
make

# Clean build files (optional)
make clean
```

### Running
```bash
# Basic usage
./fdf maps/42.fdf

# Try different maps
./fdf maps/julia.fdf
./fdf maps/mars.fdf
```

### Controls
- **ESC** - Exit program
- **Mouse wheel** - Zoom in/out
- **Arrow keys** - Rotate view
- **WASD** - Pan view

## Project Structure

```
FdF/
├── src/           # Source files
├── inc/           # Header files  
├── libs/          # Libraries (libft, MiniLibX)
├── maps/          # Sample heightmap files
├── obj/           # Object files
└── Makefile       # Build configuration
```

## Learning Outcomes

This project reinforced understanding of:
- **3D mathematics** - Coordinate systems and transformations
- **Graphics programming** - Pixel manipulation and rendering pipelines
- **Algorithm optimization** - Efficient data processing
- **System programming** - Memory management and error handling

---

*Built with passion at 42 School*

