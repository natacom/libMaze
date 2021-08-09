#pragma once

#ifdef TESTLIBRARY_EXPORTS					// Automatically defined by Visual Studio.
#define TESTLIBRARY __declspec(dllexport)	// This is used when this file is built as a dll.
#else
#define TESTLIBRARY __declspec(dllimport)	// This is used when other file includes this header.
#endif

extern "C" TESTLIBRARY void Generate(int row, int column);
extern "C" TESTLIBRARY bool ExistTopWall(int row, int column);
extern "C" TESTLIBRARY bool ExistRightWall(int row, int column);
extern "C" TESTLIBRARY bool ExistBottomWall(int row, int column);
extern "C" TESTLIBRARY bool ExistLeftWall(int row, int column);
