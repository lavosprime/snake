/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  view.cc: Functions for drawing the game.

\******************************************************************************/

#include "./view.h"

#include <atomic>

namespace {

std::atomic_uintmax_t frame_count;

}

void View::init(void) {
  initscr();
  raw();
  noecho();
  curs_set(0);
  frame_count = 0;
}

void View::end(void) {
  endwin();
}

void View::newFrame(void) {
  refresh();
  ++frame_count;
}

uintmax_t View::frameCount(void) {
  return frame_count.load();
}

void View::erase(int x, int y) {
  draw(x, y, ' ');
}

void View::draw(int x, int y, chtype ch) {
  mvaddch(y, x, ch);
}
