# Copyright (c) 2014-2015 by Cooper Johnson <lavosprime@gmail.com>
# This program is free software provided under the terms of the MIT License.
#
# Makefile: Builds the program in release, debug (default), or validate mode.

CXXFLAGS = -std=c++14 -Wall -Wextra -Werror -pedantic -pedantic-errors \
	-Wcast-align -Wcast-qual -Wconversion -Wctor-dtor-privacy -Weffc++ \
	-Wfloat-equal -Wformat=2 -Wlogical-op -Wmissing-declarations \
	-Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls \
	-Wsign-conversion -Wsign-promo -Wshadow -Wstrict-null-sentinel \
	-Wstrict-overflow=5 -Wswitch-default -Wundef -Wuseless-cast \
	-Wzero-as-null-pointer-constant \
	-Wno-error=effc++ -Wno-error=unused-parameter
LDFLAGS = -lncurses
RELEASEFLAGS = -O3 -s -DNDEBUG
DEBUGFLAGS = -g -Og
VALIDATEFLAGS = -g -Og -Wsuggest-final-types -Wsuggest-final-methods \
	-Wunused-macros -fsanitize=address,undefined -fno-omit-frame-pointer

PROG = snake
OBJS = main.o math_util.o snake.o view.o
HEADERS = math_util.h snake.h view.h
CPPLINT = http://google-styleguide.googlecode.com/svn/trunk/cpplint/cpplint.py

.PHONY: default release debug validate lint lint-headers clean
default: debug

# Optimize the program for release.
release: CXXFLAGS += $(RELEASEFLAGS)
release: RUNCPPLINT =
release: $(PROG)

# Compile the program normally for debugging.
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: RUNCPPLINT = -python cpplint.py $<
debug: $(PROG) | cpplint.py

# Compile the program with extra warnings and validation.
validate: CXXFLAGS += $(VALIDATEFLAGS)
validate: RUNCPPLINT = python cpplint.py $<
validate: lint-headers $(PROG) | cpplint.py

# The main program binary is linked together from libraries and object files.
$(PROG): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# C++ source files are compiled to object files normally and are linted before
# compliation in some builds.
%.o: %.cc $(HEADERS)
	$(RUNCPPLINT)
	$(CXX) $(CXXFLAGS) -c $<

# Lint all C++ files.
lint: | cpplint.py
	python cpplint.py *.h *.cc

# Lint all headers.
lint-headers: $(HEADERS) | cpplint.py
	python cpplint.py $^

# If there isn't a local copy of cpplint.py, download it.
cpplint.py:
	wget --no-verbose --no-clobber $(CPPLINT)

# Remove all non-source files.
clean:
	-rm -f *.o $(PROG)
