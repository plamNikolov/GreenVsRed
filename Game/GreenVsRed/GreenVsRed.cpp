// GreenVsRed.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <cctype>
#include <iostream>
#include "Grid.h"

using namespace std;

bool toChangeColor(Color cellColor, uint32_t countGreen);

struct extract
{
	char c;
	extract(char c) : c(c) { }
};

istream& operator >> (istream& ins, extract e)
{
	// Skip leading whitespace IFF user is not asking to extract a whitespace character
	if (!isspace(e.c)) ins >> ws;

	// Attempt to get the specific character
	if (ins.peek() == e.c) ins.get();

	// Failure works as always
	else ins.setstate(ios::failbit);

	return ins;
}

/**
* @brief Checks the row for valid values (0 or 1)
* @param row - Row from the grid
* @return true  - if the values are valid
*         false - if the values are not valid
*/
bool isRowValid(string row)
{
	uint32_t len = row.length(); // Get row length

	for (uint32_t i = 0; i < len; i++) 
	{
		if (row[i] != '0' && row[i] != '1') // Checks if the row containst characters different from 1 or 0 
		{
			return false;
		}
	}

	return true;
}

/**
* @brief Calculates how many times a specific cell from the grid is green trough all generations
* @param grid - Grid object
* @param cellCoords - Contains the coordinates for specific cell
* @param generationsNumber - Number of generations
* @return How many times the specific cell is green
*/
uint32_t getGreenCellCounter(Grid& grid, Point cellCoords, uint32_t generationsNumber)
{
	uint32_t rows = grid.getRows();	// Get grid rows
	uint32_t cols = grid.getCols(); // Get grid columns
	Cell cell;
	uint32_t greenCount;
	uint32_t redCount;
	uint32_t greenCellCounter = 0;

	for (uint32_t i = 0; i < generationsNumber; i++) // Loop for generations
	{
		Grid currentGrid = grid;
		for (uint32_t row = 0; row < rows; row++) // Loop for grid rows
		{
			for (uint32_t col = 0; col < cols; col++) // Loop for grid columns
			{
				greenCount = 0;
				redCount = 0;
				cell = currentGrid.getArea()[row][col];
				if (col == 0) // x = 0
				{
					if (currentGrid.getArea()[row][col + 1].getColor() == GREEN)  greenCount += 1;
					if (row == 0) // y = 0
					{
						// x = 0, y = 0
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
					else if (row == (rows - 1)) // y = grid height - 1
					{
						// x = 0,  y = grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
					else
					{
						// x = 0, 0 < y < grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col + 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
				}
				else if (col == (cols - 1)) // x =  grid width - 1
				{
					if (currentGrid.getArea()[row][col - 1].getColor() == GREEN) greenCount += 1;
					if (row == 0) // y = 0
					{
						// x = grid width - 1, y = 0
						if (currentGrid.getArea()[row + 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
					}
					else if (row == (rows - 1)) // y = grid height - 1
					{
						// x = grid width - 1, y = grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col - 1].getColor() == GREEN) greenCount += 1;
					}
					else
					{
						// x = grid width - 1, 0 < y < grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col - 1].getColor() == GREEN) greenCount += 1;
					}
				}
				else
				{
					if (currentGrid.getArea()[row][col - 1].getColor() == GREEN) greenCount += 1;
					if (currentGrid.getArea()[row][col + 1].getColor() == GREEN) greenCount += 1;
					if (row == 0) // y = 0
					{
						// 0 < x < grid width - 1, y = 0
						if (currentGrid.getArea()[row + 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
					else if (row == (rows - 1)) // y = grid height - 1
					{
						// 0 < x < grid width - 1, y = grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
					else
					{
						// 0 < x < grid width - 1, 0 < y < grid height - 1
						if (currentGrid.getArea()[row - 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row - 1][col + 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col - 1].getColor() == GREEN) greenCount += 1;
						if (currentGrid.getArea()[row + 1][col + 1].getColor() == GREEN) greenCount += 1;
					}
				}

				if (toChangeColor(cell.getColor(), greenCount)) // Checks if the color of the current cell has to be changed
				{
					grid.getArea()[row][col].setColor((cell.getColor() == RED) ? GREEN : RED); // Changing the color of the cell
				}
			}
		}

		if (grid.getArea()[cellCoords.m_y][cellCoords.m_x].getColor() == GREEN) greenCellCounter++; // If the color of the specific cell is green increment the counter
	}

	return greenCellCounter;
}

/**
* @brief Checks if the color of the current cell has to be changed depending on how many green cells are surrounding it
* @param cellColor  - Color of the current cell
* @param countGreen - The number of the green cells surrounding the current cell
* @return true  - If the color has to be changed
*         false - If the color has not to be changed
*/
bool toChangeColor(Color cellColor, uint32_t countGreen) 
{
	// Implements the four rules
	if (cellColor == RED)
	{
		switch (countGreen)
		{
		case 3:
		case 6:
			return true;
		case 0:
		case 1:
		case 2:
		case 4:
		case 5:
		case 7:
		case 8:
			return false;
		}

	}
	else
	{
		switch (countGreen)
		{
		case 0:
		case 1:
		case 4:
		case 5:
		case 7:
		case 8:
			return true;
		case 2:
		case 3:
		case 6:
			return false;
		}
	}
	return false;
}

int main()
{
	uint32_t x, y, x1, y1, N;
	uint8_t numberOfAttempts = 0;
	uint32_t rowsCount = 0;
	string row;
   
	do
	{
		cout << "Enter the size of the grid [width,height]" << endl;
		cin >> x >> extract(',') >> y;

		if (x <= y && y < 1000) break; // Checks if the x <= y and y < 1000 and exit from the loop. In other way invites the user to try again
		if (numberOfAttempts == 10) exit(0); // If the user inserts wrong data more than 10 times exit from the program.
		cout << "Wrong x or y value!" << endl;
		numberOfAttempts++;
	} while (true);

	Grid grid(x, y); // Create grid

	do
	{
		cin >> row;
		uint32_t len = row.length(); // Get grid row length

		if (len != x) // Checks if the length of the row is equal to the value which user has entered  
		{
			cout << "Row length is incorrect" << endl;
			cout << "Again" << endl;
			continue;
		}

		if (!isRowValid(row)) // Checks if the row contains valid values
		{
			cout << "Row values are incorrect" << endl;
			cout << "Again" << endl;
			continue;
		}

		grid.add(row); // Insert the row into the grid
		rowsCount++;
		if (rowsCount == y) break; // Checks if the number of the row is equal to the value which user has entered and go forward
	} while (true);

	cin >> x1 >> extract(',') >> y1 >> extract(',') >> N;

	if (x1 >= x || y1 >= y) cout << "x1 or y1 is out of range" << endl; // Checks if x1 and y1 coordinates are inside the grid area

	Point greenCellCoordinates;
	greenCellCoordinates.m_x = x1;
	greenCellCoordinates.m_y = y1;

	uint32_t result = getGreenCellCounter(grid, greenCellCoordinates, N);
	cout << "result:" << result << endl;

	return 0;
}
