#include "Grid.h"

Grid::Grid()
{
	m_rows = 0;
	m_cols = 0;
	m_CurrentCell = 0;
	m_RowCount = 0;
	m_Area_pp = nullptr;
}

Grid::Grid(uint32_t rows, uint32_t cols)
{
	m_rows = rows;
	m_cols = cols;
	m_CurrentCell = 0;
	m_RowCount = 0;

	// Dynamically allocate memory for the grid
	m_Area_pp = new Cell*[m_rows]; 
	for (uint32_t i = 0; i < m_rows; i++) {
		m_Area_pp[i] = new Cell[m_cols];
	}
}

Grid::Grid(const Grid& g)
{
	m_rows = g.m_rows;
	m_cols = g.m_cols;
	m_CurrentCell = g.m_CurrentCell;
	m_RowCount = g.m_RowCount;

	// Dynamically allocate memory for the grid
	m_Area_pp = new Cell * [m_rows];
	for (uint32_t i = 0; i < m_rows; i++) {
		m_Area_pp[i] = new Cell[m_cols];
	}

	// Copying 
	for (uint32_t i = 0; i < m_rows; i++) 
	{
		for (uint32_t j = 0; j < m_cols; j++)
		{
			m_Area_pp[i][j] = g.m_Area_pp[i][j];
		}
	}
}

Grid::~Grid()
{
	// free memory for the grid
	for (uint32_t i = 0; i < m_rows; i++) {
		delete[] m_Area_pp[i];
	}
	delete[] m_Area_pp;
}

Cell** Grid::getArea()
{
	return m_Area_pp;
}

Errors Grid::add(string str)
{
	Cell cell;
	Point coordinates;
	Color color;

	if (str.length() != m_cols) return FAIL; // Checks if the length of the row is equal to the value which user has entered 
	if (m_RowCount >= m_rows) return FAIL; // Checks if the number of the row is equal to the value which user has entered 

	for (uint32_t i = 0; i < m_cols; i++) 
	{
		coordinates.m_x = i;
		coordinates.m_y = (uint32_t)(m_CurrentCell / m_cols); // If the current cell is bigger than the number of the colums of grid go to next row 
		color = (str[i] == '0') ? RED : GREEN; // If the value of the cell from the row is 0 it's color is red, otherwise it's green
		cell.setCoordinates(coordinates); // Set cell coordinates
		cell.setColor(color); // Set cell color
		m_Area_pp[m_RowCount][i] = cell; // Insert cell in the grid
		m_CurrentCell++;
	}
	m_RowCount++;
	return OK;
}

Color Grid::getCellColor(Point Coordinate)
{
	return m_Area_pp[Coordinate.m_y * (m_rows - 1)][Coordinate.m_x * (m_cols - 1)].getColor();
}

uint32_t Grid::getSize()
{
	return m_rows * m_cols;
}

uint32_t Grid::getRows()
{
	return m_rows;
}

uint32_t Grid::getCols()
{
	return m_cols;
}


