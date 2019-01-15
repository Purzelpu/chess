#include <ncurses.h>
#include "Curses_Viewer.hpp"

void Curses_Viewer::init()
{
	initscr();
	boardView = newwin(9,9,5,5);
	curs_set(0);
	start_color();
	init_pair(1,COLOR_BLACK, COLOR_WHITE);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
}

void Curses_Viewer::end()
{
	delwin(boardView);
	endwin();
}

void Curses_Viewer::draw_board(Board& board)
{
	mvwaddstr(boardView,0,1,"abcdefgh");
	for(unsigned int x=0;x<8;++x)
	{
		mvwaddch(boardView,x+1,0,56-x);
		for(unsigned int y=0;y<8;++y)
		{
			wattron(boardView,COLOR_PAIR(((x+y)%2)+1));
			if(board.figures[x][y])
			{
				mvwaddch(boardView,y+1,x+1,board.figures[x][y]->symbol);
			}
			else
			{
				mvwaddch(boardView,y+1,x+1,' ');
			}
			wattroff(boardView,COLOR_PAIR(((x+y)%2)+1));
		}
	}
	refresh();
	wrefresh(boardView);
}
