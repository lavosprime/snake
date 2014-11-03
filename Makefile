CXXFLAGS = -g -o0 -Wall -Werror -Wpedantic -std=c++11
LDFLAGS = -lncurses

OBJS = Main.cc

HEADERS =

all: snake

snake: $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o snake $(OBJS) $(LDFLAGS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f *.o snake
