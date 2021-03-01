#include "GraphColoring.h"

GraphColoring::GraphColoring(std::vector<std::vector<int>>& graph, int _numOfColor)
	: graphMatrix(graph), numOfColor(_numOfColor)
{
	colors.resize(graphMatrix.size());
}

void GraphColoring::operator()()
{
	if (solve(0))
		showResult();

	else
		std::cout << "No solution for given parameters...\n";
}

bool GraphColoring::solve(std::size_t nodeIndex)
{
	if (nodeIndex == graphMatrix.size())
		return true;

	for (int colorIndex = 1; colorIndex <= numOfColor; colorIndex++)
	{
		if (isColorValid(nodeIndex, colorIndex))
		{
			colors[nodeIndex] = colorIndex;

			if (solve(nodeIndex + 1))
				return true;
		}
	}

	return false;
}

bool GraphColoring::isColorValid(std::size_t nodeIndex, std::size_t colorIndex)
{
	for (size_t i = 0; i < graphMatrix.size(); i++)
	{
		if (graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i])
			return false;
	}

	return true;
}

void GraphColoring::showResult()
{
	for (size_t i = 0; i < graphMatrix.size(); i++)
		std::cout << "Node " << (i + 1) << "has color index " << colors[i] << "\n";
	std::cout << std::endl;
}