*This project has been created as part of the 42 curriculum by emercier, nmunari.*

# Cub3D

## Description

**Cub3D** is a 42 project that involves building a first-person 3D graphics engine using raycasting. Inspired by the techniques behind Wolfenstein 3D, it renders a navigable 3D environment from a 2D map in real time.

The engine parses a `.cub` configuration file that defines the map layout, wall textures, and floor/ceiling colors. It then renders the scene using a DDA-based raycasting algorithm, projecting textured walls with perspective-correct scaling and distance-based shading.

### Implemented Features
* **4-directional wall textures** (North, South, West, East) in XPM format
* **Solid floor and ceiling** with configurable RGB colors
* **Distance-based shading** with exponential fog and vignette effect
* **Player movement**: W/A/S/D to move, arrow keys and mouse to rotate
* **Collision detection**: smooth wall sliding
* **Two render modes**: 3D first-person view (key `1`) and 2D minimap with FOV cone visualization (key `2`)
* **Comprehensive map validation**: wall closure, player placement, color and texture checks

## Instructions

### Compilation
The project is compiled using a `Makefile` that handles all dependencies (including `libft` and `minilibx`) and prevents unnecessary relinking. Source files are compiled with `cc` using the flags `-Wall -Wextra -Werror`.

The `Makefile` includes the following standard rules:
* `all`: Compiles the executable.
* `clean`: Removes object files.
* `fclean`: Removes object files and the executable.
* `re`: Recompiles the project from scratch.

To compile and launch:

    make
    ./cub3d <path_to_map.cub>

### Usage
The program requires exactly one argument: the path to a `.cub` map file.

    ./cub3d maps/good/subject_map.cub

**Controls:**
* `W` / `S`: Move forward / backward
* `A` / `D`: Strafe left / right
* `Arrow Left` / `Arrow Right`: Rotate view
* `Mouse`: Look around (horizontal rotation)
* `1`: Switch to 3D game view
* `2`: Switch to 2D minimap view
* `ESC`: Exit

### Map format
A `.cub` file defines textures, colors, and the map grid:

    NO textures/wolfenstein/grey_stone.xpm
    SO textures/wolfenstein/purple_stone.xpm
    WE textures/wolfenstein/red_brick.xpm
    EA textures/wolfenstein/wood.xpm

    F 220,100,0
    C 225,30,0

    111111
    100001
    1000N1
    111111

* `0`: empty space — `1`: wall — `N/S/E/W`: player spawn and starting direction

## Resources

### References
* [Raycasting Tutorial — Lode Vandevenne](https://lodev.org/cgtutor/raycasting.html)
* [DDA Algorithm Explained](https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm))
* [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
* [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d)

### AI Usage
This project was developed with the assistance of AI to enhance learning and code quality. AI was used for:
* **Concept Explanation:** Acting as a virtual tutor to clarify raycasting math, DDA algorithm details, and texture mapping logic.
* **Documentation:** Writing the English content of this README based on the structure and directives provided in French.
