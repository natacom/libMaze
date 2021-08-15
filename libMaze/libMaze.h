#pragma once

#ifdef LIBMAZE_EXPORTS					// Automatically defined by Visual Studio.
#define LIBMAZE __declspec(dllexport)	// This is used when this file is built as a dll.
#else
#define LIBMAZE __declspec(dllimport)	// This is used when other file includes this header.
#endif

extern "C" LIBMAZE void Generate(int rowNum, int columnNum);
extern "C" LIBMAZE bool ExistTopWall(int row, int column);
extern "C" LIBMAZE bool ExistRightWall(int row, int column);
extern "C" LIBMAZE bool ExistBottomWall(int row, int column);
extern "C" LIBMAZE bool ExistLeftWall(int row, int column);
