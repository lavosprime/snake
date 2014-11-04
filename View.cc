/*******************************************************************************

  Copyright (c) 2014 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  View.cc: Functions for drawing the game.

*******************************************************************************/

#include <cstdlib>
#include <ncurses.h>

void initView(void) {
  initscr();
  raw();
  noecho();
  curs_set(0);
}

void endView(void) {
  endwin();
}

void erase(x, y) {
  draw(x, y, ' ');
}

void draw(x, y, ch) {
  mvaddch(y, x, ch);
}
