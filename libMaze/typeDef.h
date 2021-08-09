#pragma once
#include <exception>

enum class Direction { None, Top, Right, Bottom, Left};

class InvalidDirectionException: public std::exception
{
public:
	InvalidDirectionException(): std::exception("Invalid direction.") { }
};
