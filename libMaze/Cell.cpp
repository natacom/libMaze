#include "pch.h"
#include "Cell.h"

Cell::Cell(int id,
	std::shared_ptr<Cell> const& topCell,
	std::shared_ptr<Cell> const& rightCell,
	std::shared_ptr<Cell> const& bottomCell,
	std::shared_ptr<Cell> const& leftCell)
	: m_id(id)
	, m_topCell(topCell)
	, m_rightCell(rightCell)
	, m_bottomCell(bottomCell)
	, m_leftCell(leftCell)
{ }

bool Cell::connect(std::shared_ptr<Cell> const& cell, Direction direction)
{
	if (m_id == cell->m_id)
		return false;

	if (m_id > cell->m_id)
	{
		setId(cell->m_id, Direction::None);
	}
	else
	{
		cell->setId(m_id, Direction::None);
	}

	switch (direction)
	{
	case Direction::Top:
		m_topCell = cell;
		cell->m_bottomCell = shared_from_this();
		break;
	case Direction::Right:
		m_rightCell = cell;
		cell->m_leftCell = shared_from_this();
		break;
	case Direction::Bottom:
		m_bottomCell = cell;
		cell->m_topCell = shared_from_this();
		break;
	case Direction::Left:
		m_leftCell = cell;
		cell->m_rightCell = shared_from_this();
		break;
	default:
		throw InvalidDirectionException();
	}

	return true;
}

void Cell:: getWalls(bool& top, bool& right, bool& bottom, bool& left) const noexcept
{
	top    = (m_topCell    == nullptr);
	right  = (m_rightCell  == nullptr);
	bottom = (m_bottomCell == nullptr);
	left   = (m_leftCell   == nullptr);
}

void Cell::setId(int newId, Direction to)
{
	m_id = newId;

	if (to != Direction::Bottom && m_topCell != nullptr)
	{
		m_topCell->setId(newId, Direction::Top);
	}
	if (to != Direction::Left && m_rightCell != nullptr)
	{
		m_rightCell->setId(newId, Direction::Right);
	}
	if (to != Direction::Top && m_bottomCell != nullptr)
	{
		m_bottomCell->setId(newId, Direction::Bottom);
	}
	if (to != Direction::Right && m_leftCell != nullptr)
	{
		m_leftCell->setId(newId, Direction::Left);
	}
}