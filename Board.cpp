#include <ctype.h>
#include "Board.hpp"
#include <iostream>
#include <string>
#include <sstream>


Board::Board()
{
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
		{
			figures[i][j] = nullptr;
		}
}

void Board::loadPosition(const std::string& fenPos)
{
	int row = 0;
	std::string temp;
	std::istringstream input(fenPos);
	while(!input.eof() && row<8)
	{
		getline(input, temp, '/');
		loadPositionIntoRow(temp,row++);
	}

}

void Board::loadPositionIntoRow(const std::string& fen, int row)
{
	int pos = 0;
	for(char c : fen)
	{
		if(isdigit(c))
		{
			pos += (c - '0');
		}
		else
		{
			//std::cout << "Adding " << c << "@" << pos << std::endl;
			figures[pos++][row] = new Figure(c);
		}
	}
}
