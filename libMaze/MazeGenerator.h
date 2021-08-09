#pragma once

#include <stdint.h>
#include <vector>

#include "Cell.h"
#include "typeDef.h"

class MazeGenerator
{
public:
	MazeGenerator() : MazeGenerator(0, 0) { };
	MazeGenerator(int row, int column);

	int getColumn() { return m_columnNum; }
	int getRow() { return m_rowNum; }

	void getWalls(int row, int column, bool& top, bool& right, bool& bottom, bool& left);
	bool existWall(int row, int column, Direction direction);

private:
	int getIndex(int row, int column);
	void generate();

	void debugPrint();

	int m_columnNum;
	int m_rowNum;
	std::vector<std::shared_ptr<Cell>> m_cells;
};

