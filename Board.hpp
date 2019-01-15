#include "Figures.hpp"
#include "Coordinate.hpp"
#include <string>
class Board
{
	public:
	Figure* figures[8][8];
	Board();
	void loadPosition(const std::string&);
	void loadPositionIntoRow(const std::string&, int);
	Figure* operator[](const Coordinate c);
};
