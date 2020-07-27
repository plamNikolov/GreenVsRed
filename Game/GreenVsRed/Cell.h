#pragma once
#include "Point.h"

/**
* @brief Describes the color of a cell from the grid
*/

typedef enum 
{
	RED,                
	GREEN,
	NO_COLOR
}Color;

/** 
 * @class Cell
 * @brief Describes a cell with coordinates and color
*/

class Cell 
{
private:
	Point m_Coordinates;
	Color m_CellColor;
public:
	Cell();

	/**
	* @brief Constructor
	* @param Coordinates - Coordinates of the cell
	* @param color - Color of the cell
	*/
	Cell(Point Coordinates, Color color);
	/**
	* @brief Set new coordinates 
	* @param Coordinates - New coordinates
	*/
	void setCoordinates(Point Coordinates);

	/**
	* @brief Gets the coordinates
	* @return Coordinates
	*/
	Point getCoordinates();

	/**
	* @brief Set color
	* @param color - New color
	*/
	void setColor(Color color);

	/**
	* @brief Get color
	* @return color
	*/
	Color getColor();
};

