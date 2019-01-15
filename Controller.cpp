#include <string>
#include <sstream>
#include "Controller.hpp"
#include <stdexcept>

Controller::Controller()
{
	loadSituation("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

void Controller::loadSituation(const std::string& FENString)
{
	std::istringstream FENStream(FENString);
	std::string position;
	std::string active;
	std::string rochadeS;
	std::string enpassantS;
	std::string halfmoveS;
	std::string moveS;
	FENStream >> position >> active 
		>> rochadeS >> enpassantS >> halfmoveS >> moveS;
	board.loadPosition(position);
	if(active[0] == 'w')
	{
		activePlayer = 0;
	}
	else
	{
		activePlayer = 1;
	}

	rochadeK = (rochadeS.find('K') == std::string::npos) ? false : true;
	rochadeQ = (rochadeS.find('Q') == std::string::npos) ? false : true;
	rochadek = (rochadeS.find('k') == std::string::npos) ? false : true;
	rochadeq = (rochadeS.find('q') == std::string::npos) ? false : true;

	if('a' <= enpassantS[0]  && enpassantS[0]<= 'h')
	{
		enpassant.emplace(enpassantS);
	}
	else
	{
		enpassant.reset();
	}

	try {
		halfmoves = std::stoi(halfmoveS);
	}
	catch(std::invalid_argument&)
	{
		halfmoves = 0;
	}
	try{
		round = std::stoi(moveS);
	}
	catch(std::invalid_argument&)
	{
		round = 0;
	}
}

void Controller::switchPlayer()
{
	if(activePlayer == 1)
	{
		round++;
	}
	activePlayer = (activePlayer+1)%2;
}

void Controller::move(Coordinate from, Coordinate to)
{
	if(board[from])
	{
		board[to].emplace(*board[from]);
		board[from].reset();
	}
	switchPlayer();
}
