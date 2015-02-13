/******************************************************************************\

  Copyright (c) 2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  view.h: Declarations of unctions for drawing the game.

\******************************************************************************/

#ifndef VIEW_H_
#define VIEW_H_

extern "C" {
#include <ncurses.h>
}

#include <cstdint>

class View {
 public:
  static void init(void);
  static void end(void);
  static void newFrame(void);
  static uintmax_t frameCount(void);
  static void erase(int x, int y);
  static void draw(int x, int y, chtype ch);
};

#endif  // VIEW_H_
