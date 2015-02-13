/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  snake.h: Declaration of a class representing the player's snake.

\******************************************************************************/

#ifndef SNAKE_H_
#define SNAKE_H_

#include "./math_util.h"

#include <cstdint>
#include <queue>

class Snake{
 public:
  Snake();
 private:
  struct Segment {
    Coord pos;
    uintmax_t birth_frame;
  };
  std::queue<Segment> body;
};

#endif  // SNAKE_H_
