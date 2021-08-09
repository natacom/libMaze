#include <iostream>
#include <sstream>
#include <iomanip>

#include "libMaze.h"

void drawMaze(int row, int column);

int main(void)
{
	drawMaze(10, 10);
	return 0;
}

void drawMaze(int rowNum, int columnNum)
{
	Generate(rowNum, columnNum);

	static const std::string k_cell = "  ";
	static const std::string k_hBorder = "--";
	static const std::string k_hPath = "  ";
	static const std::string k_vBorder = "|";
	static const std::string k_vPath = " ";
	static const std::string k_crossing = "o";
	std::stringstream mazeStr;

	// Draw top border first
	mazeStr << k_crossing;
	for (int c = 0; c < columnNum; ++c)
	{
		mazeStr << k_hBorder << k_crossing;
	}
	mazeStr << "\n";

	// Draw remaining
	for (int r = 0; r < rowNum; ++r)
	{
		// Draw vertical borders
		mazeStr << k_vBorder;
		for (int c = 0; c < columnNum; ++c)
		{
			mazeStr << k_cell << (ExistRightWall(r, c) ? k_vBorder : k_vPath);
		}
		mazeStr << "\n";

		// Draw horizontal borders
		mazeStr << k_crossing;
		for (int c = 0; c < columnNum; ++c)
		{
			mazeStr << (ExistBottomWall(r, c) ? k_hBorder : k_hPath)
					<< k_crossing;
		}
		mazeStr << "\n";
	}

	// Output lastly
	std::cout << mazeStr.str();
}
