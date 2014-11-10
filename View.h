/*******************************************************************************

  Copyright (c) 2014 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  View.h: Declarations of unctions for drawing the game.

*******************************************************************************/

#ifndef SNAKE_VIEW_H_
#define SNAKE_VIEW_H_

class View {
 public:
  static void init(void);
  static void end(void);
  static void newFrame(void);
  static int frameCount(void);
  static void erase(int x, int y);
  static void draw(int x, int y, char ch);
};

#endif // SNAKE_VIEW_H_
