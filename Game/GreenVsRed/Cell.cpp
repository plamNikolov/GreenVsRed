#include "Cell.h"

Cell::Cell()
{
	m_Coordinates.m_x = 0;
	m_Coordinates.m_y = 0;
	m_CellColor = NO_COLOR;
}

Cell::Cell(Point Coordinates, Color color)
{
	setCoordinates(Coordinates);
	m_CellColor = color;
}

void Cell::setCoordinates(Point Coordinates)
{
	m_Coordinates.m_x = Coordinates.m_x;
	m_Coordinates.m_y = Coordinates.m_y;
}

Point Cell::getCoordinates()
{
	return m_Coordinates;
}

void Cell::setColor(Color color)
{
	m_CellColor = color;
}

/**

*/
Color Cell::getColor()
{
	return m_CellColor;
}