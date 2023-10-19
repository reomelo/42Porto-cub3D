# Cub3D

![Screenshot from 2023-10-19 18-28-42](https://github.com/reomelo/42Porto-cub3D/assets/73884501/c2d5b56f-b79c-4aba-a12f-663244764e1a)

<p align="center">
  <img src="https://github.com/reomelo/42Porto-cub3D/blob/master/cub3d(1).gif" width="600" />
</p>

Welcome to the Cub3D project! Dive into the exciting world of raycasting and maze exploration with our interactive game. Learn about the DDA algorithm and how raycasting works in this creative 3D environment.

### 🤝 Authorship - Collaborative Work
> Project done in collaboration with <a href="https://github.com/ziliolu">Luiza Zilio</a>
  
## Project Overview
Cub3D is more than just a game; it's a learning experience. Step into the shoes of a maze explorer and immerse yourself in the world of raycasting. Use your skills to navigate through a 3D maze, all while gaining an understanding of the DDA algorithm.
The project was entirely written in C and [MiniLibX library](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html) was used for graphic rendering.

## Usage
Let's get started on your journey of raycasting and maze exploration. Here's how:

1. Clone the repository:
  ```bash
  git clone https://github.com/reomelo/42Porto-cub3D.git
  ```
2. Navigate to the project directory and compile it:
  ```bash
  cd 42Porto-cub3D && make
  ```
3. Choose a map from maps folder and give it a try
  ```bash
  ./cub3D maps/valid/subject_map.cub
  ```

## What is DDA?
DDA stands for Digital Differential Analyzer, a mathematical algorithm used for generating lines, as we do in raycasting. In our context, DDA is the magic behind the scenes, helping us draw rays to create a 3D view of the maze.

Imagine DDA as your artist's brush, painting the pixels that make up our 3D world. It's a step-by-step process, calculating the intersections between the rays and the walls. It's the essential tool for drawing lines and shapes with precise, pixel-level accuracy. 

## How Raycasting Works
Raycasting is a fascinating technique used in video games to create a 3D perspective. It simulates how light rays travel through a scene. In our game, the player emits rays in all directions, just like a flashlight illuminating the path ahead.

As these rays hit walls, we calculate their lengths and angles, which ultimately create the illusion of depth. This is how you see the 3D maze, even though it's just a 2D grid. The rays cast the world around you, showing you what's near and far.

___
######  At [42School](https://en.wikipedia.org/wiki/42_(school)), almost every project must be written in accordance to the [Norm](https://github.com/42School/norminette). As a result, parts of the code are not as clean, efficient or straight forward as they could be.
