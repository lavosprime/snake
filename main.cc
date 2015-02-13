/******************************************************************************\

  Copyright (c) 2015 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  main.cc: Setup, teardown, and main game loop.

\******************************************************************************/

#include <cstdlib>

#include "./view.h"

int main(void) {
  View::init();
  View::end();
  return 0;
}
