/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  math_util.h: Declarations of simple mathematical types and functions.

\******************************************************************************/

#ifndef MATH_UTIL_H
#define MATH_UTIL_H

// Return a random integer within the given (inclusive) range.
int rand_int(int min, int max);

// A basic 2D Cartesian coordinate.
struct Coord {
  int x;
  int y;
};

#endif  // MATH_UTIL_H
