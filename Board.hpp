#pragma once
#include "Figures.hpp"
#include "Coordinate.hpp"
#include <string>
#include <optional>

class Board
{
	public:
	std::optional<Figure> figures[8][8];
	Board();
	void loadPosition(const std::string&);
	void loadPositionIntoRow(const std::string&, int);
	std::optional<Figure>& operator[](const Coordinate c);
};
