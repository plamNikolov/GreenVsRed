#pragma once
#include "Cell.h"
#include <string>

using namespace std;

/**  
* @brief Describes error codes
*/

typedef enum 
{
	OK,
	FAIL
}Errors;

/** @class Grid
* @brief Describes a grid which consist two dimensional array of cells 
*/

class Grid
{
private:
	uint32_t m_rows;
	uint32_t m_cols;
	Cell** m_Area_pp;
	uint32_t m_CurrentCell;
	uint32_t m_RowCount;
public:
	Grid();

	/**
	* @brief Constructor
	* @param rows - Rows of the grid
	* @param cols - Colums of the grid
	*/
	Grid(uint32_t rows, uint32_t cols);
	/**
	* @brief Copy Constructor
	*/
	Grid(const Grid& g);
	~Grid();

	/** 
	* @brief Get grid area
	* @return Grid area
	*/
	Cell** getArea();

	/**
	* @brief Add new row into the grid
	* @param str - String which consist a row from the grid
	* @return OK   - if method is executed without errors
	*		  FAIL - if method is executed with errorr
	*/ 
	Errors add(string str);

	/**
	* @brief Get color of some cell
	* @param Coordinate - Coordinates of the cell from the grid
	* @return Color of the cell
	*/
	Color getCellColor(Point Coordinate);

	/**
	* @brief Get grid size
	* @return Size of the grid
	*/
	uint32_t getSize();

	/**
	* @brief Get grid rows
	* @return Rows of the grid
	*/
	uint32_t getRows();
	
	/**
	* @brief Get grid columns
	* @return Columns of the grid
	*/
	uint32_t getCols();
};

