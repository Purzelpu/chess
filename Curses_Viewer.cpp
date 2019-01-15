#include <curses.h>
#include "Curses_Viewer.hpp"

void Curses_Viewer::init()
{
	initscr();
	curs_set(0);
	start_color();
	init_pair(1,COLOR_BLACK, COLOR_WHITE);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
}

void Curses_Viewer::end()
{
	endwin();
}

void Curses_Viewer::draw_board(Board& board)
{
	mvaddstr(9,10,"abcdefgh");
	for(unsigned int x=0;x<8;++x)
	{
		mvaddch(x+10,9,56-x);
		for(unsigned int y=0;y<8;++y)
		{
			attron(COLOR_PAIR(((x+y)%2)+1));
			if(board.figures[x][y])
			{
				mvaddch(y+10,x+10,board.figures[x][y]->symbol);
			}
			else
			{
				mvaddch(y+10,x+10,' ');
			}
			refresh();
			attroff(COLOR_PAIR(((x+y)%2)+1));
		}
	}
}
