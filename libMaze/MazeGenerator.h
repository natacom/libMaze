#pragma once

#include <stdint.h>
#include <vector>

#include "Cell.h"
#include "typeDef.h"

class MazeGenerator
{
public:
	MazeGenerator() : MazeGenerator(0, 0) { };
	MazeGenerator(int rowNum, int columnNum);

	int getColumn() const noexcept { return m_columnNum; }
	int getRow() const noexcept { return m_rowNum; }

	void getWalls(int row, int column, bool& top, bool& right, bool& bottom, bool& left) const;
	bool existWall(int row, int column, Direction direction) const;

private:
	int getIndex(int row, int column) const noexcept;
	void generate();

	void debugPrint() const;

	int m_columnNum;
	int m_rowNum;
	std::vector<std::shared_ptr<Cell>> m_cells;
};

