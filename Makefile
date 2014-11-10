CXXFLAGS = -g -O0 -Wall -Werror -Wpedantic -std=c++11
LDFLAGS = -lncurses
PROJ = snake

OBJS = Main.o View.o

HEADERS = View.h

all: $(PROJ)

$(PROJ): $(OBJS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o: %.cc $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $<

clean:
	-rm -f *.o snake
