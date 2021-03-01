#include <iostream>
#include "nQueens.h"

using std::cout;

QueenProblem::QueenProblem(int _numOfQueen)
	:numOfQueens(_numOfQueen)
{
	chessTable.resize(numOfQueens);
	for (auto& chessRow : chessTable)
		chessRow.resize(numOfQueens);
}

void QueenProblem::solve()
{
	if (setQueen(0))
	{
		printQueens();
	}

	else
	{
		cout << "There is no Solution \n";
	}
}

bool QueenProblem::setQueen(int _colIndex)
{
	if (_colIndex >= numOfQueens) {
		return true;
	}

	for (int rowIndex = 0; rowIndex < numOfQueens; rowIndex++)
	{
		if (isPlaceValid(rowIndex, _colIndex))
		{
			chessTable[rowIndex][_colIndex] = 1;

			if (setQueen(_colIndex + 1))
			{
				return true;
			}

			chessTable[rowIndex][_colIndex] = 0;
		}
	}

	return false;
}

bool QueenProblem::isPlaceValid(int _rowIndex, int _colIndex) const
{
	/* Queen In Same Row */
	for (int i = 0; i < _colIndex; i++)
		if (chessTable[_rowIndex][i] == 1)
			return false;

	/* Queen in same diagonal (top left to bottom right) */
	for (int i = _rowIndex, j = _colIndex; i >= 0 && j >= 0; i--, j--)
		if (chessTable[i][j] == 1)
			return false;

	/* Queen in the same diagonal (top right to bottom left) */
	for (int i = _rowIndex, j = _colIndex; i < numOfQueens && j >= 0; i++, j--)
		if (chessTable[i][j] == 1)
			return false;


	/* Else is valid */
	return true;
}

void QueenProblem::printQueens() const
{
	for (int i = 0; i < chessTable.size(); i++)
	{
		for (int j = 0; j < chessTable.size(); j++)
		{
			if (chessTable[i][j] == 1)
			{
				cout << " * ";
			}

			else
			{
				cout << " - ";
			}
		}
		cout << "\n";
	}
}