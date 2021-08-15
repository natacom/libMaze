#pragma once
#include <exception>

enum class Direction { None, Top, Right, Bottom, Left};

class InvalidDirectionException: public std::exception
{
public:
	InvalidDirectionException(): std::exception("Invalid direction.") { }
};

struct tWallExistence {
	tWallExistence(bool top, bool right, bool bottom, bool left)
		: m_top(top)
		, m_right(right)
		, m_bottom(bottom)
		, m_left(left)
	{ }

	bool m_top;
	bool m_right;
	bool m_bottom;
	bool m_left;
};
