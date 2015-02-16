/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  snake.h: Declaration of a class representing the player's snake.

\******************************************************************************/

#ifndef SNAKE_H_
#define SNAKE_H_

#include <cstdint>
#include <deque>

#include "./math_util.h"

class Snake{
 public:
  Snake();
  bool Overlaps(const Coord& c) const;
 private:
  struct Segment {
    const Coord pos;
    const uintmax_t birth_frame;
  };
  std::deque<Segment> body_;
};

#endif  // SNAKE_H_
