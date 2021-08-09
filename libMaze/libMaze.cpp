#include "pch.h"	// This is mandatory to build
#include "libMaze.h"
#include "MazeGenerator.h"
#include "typeDef.h"

static MazeGenerator gen;

void Generate(int rowNum, int columnNum)
{
	gen = MazeGenerator(rowNum, columnNum);
}

bool ExistTopWall(int row, int column)
{
	return gen.existWall(row, column, Direction::Top);
}

bool ExistRightWall(int row, int column)
{
	return gen.existWall(row, column, Direction::Right);
}

bool ExistBottomWall(int row, int column)
{
	return gen.existWall(row, column, Direction::Bottom);
}

bool ExistLeftWall(int row, int column)
{
	return gen.existWall(row, column, Direction::Left);
}
