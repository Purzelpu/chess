#include "Board.hpp"

class Controller
{
	public:
		Board board;
		int activePlayer;
		bool rochadeK;
		bool rochadeQ;
		bool rochadek;
		bool rochadeq;
		std::optional<Coordinate> enpassant;
		int halfmoves;
		int round;

		Controller();

		void loadSituation(const std::string&);
		void switchPlayer();
		void move(Coordinate,Coordinate);
};
