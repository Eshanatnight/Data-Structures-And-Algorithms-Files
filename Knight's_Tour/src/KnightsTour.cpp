#include "KnightsTour.h"
#include <iostream>
#include <iomanip>

const std::array<int, 8> KnightsTour::xMoves = { 2, 1, -1, -2, -2, -1, 1, 2 };
const std::array<int, 8> KnightsTour::yMoves = { 1, 2,  2, 1, -1, -2, -2, -1 };

KnightsTour::KnightsTour()
{
	solutionMatrix.resize(BOARD_SIZE);

	for (auto& subMatrix : solutionMatrix)
		subMatrix.resize(BOARD_SIZE);

	initializeBoard();
}

void KnightsTour::solveKnightsTourProblem()
{
	solutionMatrix[0][0] = 0;

	if (!solveProblem(1, 0, 0))
	{
		std::cout << "No Solution found.....";
		return;
	}

	showSolution();
}

bool KnightsTour::solveProblem(int stepCount, int x, int y)
{
	if (stepCount == BOARD_SIZE * BOARD_SIZE)
		return true;

	for (size_t i = 0; i < xMoves.size(); ++i)
	{
		int nextX = x + xMoves[i];
		int nextY = y + yMoves[i];

		if (isValidMove(nextX, nextY))
		{
			solutionMatrix[nextX][nextY] = stepCount;

			if (solveProblem(stepCount + 1, nextX, nextY))
				return true;

			solutionMatrix[nextX][nextY] = INT32_MIN;
		}
	}

	return false;
}

bool KnightsTour::isValidMove(int x, int y)
{
	if (x < 0 || x >= BOARD_SIZE)
		return false;

	if (y < 0 || y >= BOARD_SIZE)
		return false;

	if (solutionMatrix[x][y] != INT32_MIN)
		return false;

	return true;
}

void KnightsTour::showSolution()
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		std::cout << std::left;

		for (int j = 0; j < BOARD_SIZE; ++j)
		{
			std::cout << std::setw(2) << solutionMatrix[i][j] << std::setw(2) << ' ';
		}

		std::cout << std::endl;
	}
}

void KnightsTour::initializeBoard()
{
	for (size_t i = 0; i < BOARD_SIZE; ++i)
		for (size_t j = 0; j < BOARD_SIZE; ++j)
			solutionMatrix[i][j] = INT32_MIN;
}
