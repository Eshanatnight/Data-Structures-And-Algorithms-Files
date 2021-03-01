#pragma once
#include <iostream>
#include <vector>

class GraphColoring
{
private:
	std::vector<std::vector<int>> graphMatrix;
	int numOfColor;
	std::vector<int> colors;

public:
	GraphColoring(std::vector<std::vector<int>>& graph, int _numOfColor);

	// Overload to Operator Perend ()
	// to solve the coloring problem
	void operator()();

private:
	bool solve(std::size_t nodeIndex);

	bool isColorValid(std::size_t nodeIndex, std::size_t colorIndex);

	void showResult();
};
