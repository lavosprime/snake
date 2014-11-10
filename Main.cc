/*******************************************************************************

  Copyright (c) 2014 by Cooper Johnson <lavosprime@gmail.com>
  This program is free software provided under the terms of the MIT License.

  Main.cc: Setup, teardown, and main game loop.

*******************************************************************************/

#include <cstdlib>

#include "View.h"

int main(void) {
  View::init();
  View::end();
  return 0;
}
