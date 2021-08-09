#include "pch.h"
#include "MazeGenerator.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <random>

namespace {
	constexpr bool debugLog = false;
}

MazeGenerator::MazeGenerator(int row, int column)
	: m_columnNum(column)
	, m_rowNum(row)
{
	generate();
}

void MazeGenerator::getWalls(int row, int column, bool& top, bool& right, bool& bottom, bool& left)
{
	return m_cells[getIndex(row, column)]->getWalls(top, right, bottom, left);
}

bool MazeGenerator::existWall(int row, int column, Direction direction)
{
	bool top, right, bottom, left;
	getWalls(row, column, top, right, bottom, left);

	switch (direction)
	{
	case Direction::Top:    return top;
	case Direction::Right:  return right;
	case Direction::Bottom: return bottom;
	case Direction::Left:   return left;
	default: throw InvalidDirectionException();
	}
}

int MazeGenerator::getIndex(int row, int column)
{
	return row * m_columnNum + column;
}

void MazeGenerator::generate()
{
	if (m_columnNum == 0 || m_rowNum == 0)
		return;

	m_cells.reserve(m_columnNum * m_rowNum);

	// Initialise cells
	int id = 0;
	for (int r = 0; r < m_rowNum; ++r)
	{
		for (int c = 0; c < m_columnNum; ++c)
		{
			m_cells.emplace_back(std::make_shared<Cell>(id++, nullptr, nullptr, nullptr, nullptr));
		}
	}

	// Generate maze
	// => connect each cell randomly untill all id becomes 0.
	std::random_device seed_gen;
	std::mt19937 rand(seed_gen());
	while (true)
	{
		int minId = INT_MAX;
		int maxId = 0;
		for (int r = 0; r < m_rowNum; ++r)
		{
			for (int c = 0; c < m_columnNum; ++c)
			{
				// Top
				if (r > 0 && rand() % 2 == 0)
				{
					m_cells[getIndex(r, c)]->connect(m_cells[getIndex(r - 1, c)], Direction::Top);
				}
				// Left
				if (c > 0 && rand() % 2 == 0)
				{
					m_cells[getIndex(r, c)]->connect(m_cells[getIndex(r, c - 1)], Direction::Left);
				}

				minId = min(minId, m_cells[getIndex(r, c)]->getId());
				maxId = max(maxId, m_cells[getIndex(r, c)]->getId());

				if (debugLog)
				{
					std::cout << r << ", " << c << std::endl;
					debugPrint();
				}
			}
		}

		if (minId == maxId)
			break;
	}
}

void MazeGenerator::debugPrint()
{
	static const std::string k_hBorder = "--";
	static const std::string k_hPath = "  ";
	static const std::string k_vBorder = "|";
	static const std::string k_vPath = " ";
	static const std::string k_crossing = "+";
	std::stringstream mazeStr;

	// Draw top border first
	mazeStr << k_crossing;
	for (int c = 0; c < m_columnNum; ++c)
	{
		mazeStr << k_hBorder << k_crossing;
	}
	mazeStr << "\n";

	// Draw remaining
	for (int r = 0; r < m_rowNum; ++r)
	{
		// Draw vertical borders
		mazeStr << k_vBorder;
		for (int c = 0; c < m_columnNum; ++c)
		{
			bool dummy, right;
			m_cells[getIndex(r, c)]->getWalls(dummy, right, dummy, dummy);

			mazeStr << std::setw(2) << std::to_string(m_cells[getIndex(r, c)]->getId())
					<< (right ? k_vBorder : k_vPath);
		}
		mazeStr << "\n";

		// Draw horizontal borders
		mazeStr << k_crossing;
		for (int c = 0; c < m_columnNum; ++c)
		{
			bool dummy, bottom;
			m_cells[getIndex(r, c)]->getWalls(dummy, dummy, bottom, dummy);

			mazeStr << (bottom ? k_hBorder : k_hPath)
					<< k_crossing;
		}
		mazeStr << "\n";
	}

	// Output lastly
	std::cout << mazeStr.str();
}