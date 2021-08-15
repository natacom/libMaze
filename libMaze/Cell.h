#pragma once

#include <memory>
#include "typeDef.h"

class Cell : public std::enable_shared_from_this<Cell>
{
public:
	Cell() = delete;
	Cell(int id,
		std::shared_ptr<Cell> const& topCell,
		std::shared_ptr<Cell> const& rightCell,
		std::shared_ptr<Cell> const& bottomCell,
		std::shared_ptr<Cell> const& leftCell);

	int getId() const noexcept { return m_id; }
	bool connect(std::shared_ptr<Cell> const& cell, Direction direction);
	tWallExistence getWalls() const;

private:
	void setId(int newId, Direction from);

	int m_id;
	std::shared_ptr<Cell> m_topCell;
	std::shared_ptr<Cell> m_rightCell;
	std::shared_ptr<Cell> m_bottomCell;
	std::shared_ptr<Cell> m_leftCell;
};
