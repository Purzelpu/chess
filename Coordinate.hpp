#include <string>
class Coordinate
{
	public:
	const char column;
	const int row;
	Coordinate(char, int);
	Coordinate(const std::string);
	Coordinate(const char[3]);
};
