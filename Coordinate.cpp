#include "Coordinate.hpp"

Coordinate::Coordinate(char column, int row): column(column), row(row)
{}

Coordinate::Coordinate(const std::string coord) : column(coord[0]), row(coord[1]-'1')
{
}

Coordinate::Coordinate(const char coord[3]) : column(coord[0]), row(coord[1]-'1')
{
}
