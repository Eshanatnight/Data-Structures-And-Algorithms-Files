#include "GraphColoring.h"

int main() {
	std::vector<std::vector<int>> graphMatrix =
	{
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 0},
		{1, 1, 1, 0, 1},
		{0, 0, 0, 1, 0}
	};

	constexpr int numOfColors = 3;

	GraphColoring graphColoring(graphMatrix, numOfColors);
	graphColoring();
}