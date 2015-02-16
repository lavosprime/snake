/******************************************************************************\

  Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  math_util.cc: Simple mathematical types and functions.

\******************************************************************************/

#include "./math_util.h"

#include <random>

namespace {

// Provides access to a default thread-local Mersenne Twister engine, seeded
// from OS-level or hardware-level randomness if possible.
auto& rand_engine(void) {
  thread_local static auto engine = std::mt19937{std::random_device{}()};
  return engine;
}

}  // namespace

int rand_int(int min, int max) {
  return std::uniform_int_distribution<>{min, max}(rand_engine());
}

bool operator==(const Coord& a, const Coord& b) {
  return a.x == b.x && a.y == b.y;
}
