# libMaze

This library allows you to make a maze.  

## Interfaces

- **void Generate(int row, int column)**  
Initialise the maze.  
You should conduct this function before calling other functions.  
- **bool ExistTopWall(int row, int column)**  
Get whether the target cell has wall on the top edge.
- **bool ExistRightWall(int row, int column)**  
Get whether the target cell has wall on the right edge.
- **bool ExistBottomWall(int row, int column)**  
Get whether the target cell has wall on the bottom edge.
- **bool ExistLeftWall(int row, int column)**  
Get whether the target cell has wall on the left edge.

## Example
The testMaze project in this repository uses libMaze.  

The result of generating a maze with parameters (row = 10 and column = 10) is this.  

![Application image](doc/testMazeResult.png)