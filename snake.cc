/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  snake.cc: A class representing the player's snake.

\******************************************************************************/

#include "./snake.h"

#include <algorithm>
#include <iterator>

//*
using std::any_of;
// */
Snake::Snake()
  : body_{}
{
}

bool Snake::Overlaps(const Coord& c) const {
  return any_of(body_.cbegin(), body_.cend(), [&c](const Segment& s) {
      return s.pos == c;
  });
}
