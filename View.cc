/*******************************************************************************

  Copyright (c) 2014 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  View.cc: Functions for drawing the game.

*******************************************************************************/

#include <cstdlib>
#include <ncurses.h>

#include "View.h"

static int frameCount = 0;

void View::init(void) {
  initscr();
  raw();
  noecho();
  curs_set(0);
}

void View::end(void) {
  endwin();
}

void View::newFrame(void) {
  refresh();
  frameCount++;
}

int View::frameCount(void) {
  return frameCount;
}

void View::erase(int x, int y) {
  draw(x, y, ' ');
}

void View::draw(int x, int y, char ch) {
  mvaddch(y, x, ch);
}
