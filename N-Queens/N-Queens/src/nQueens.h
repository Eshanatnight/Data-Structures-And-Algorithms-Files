#pragma once
#include <vector>

class QueenProblem
{
private:
	std::vector<std::vector<int>> chessTable;
	int numOfQueens = 0;

public:
	QueenProblem(int _numOfQueens);
	void solve();

private:
	bool setQueen(int colIndex);
	bool isPlaceValid(int rowIndex, int colIndex) const;

	void printQueens() const;
};