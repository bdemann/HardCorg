# Makefile for HardCorg

CXX=			g++ $(CCFLAGS)

OBJS=			display.o

LIBS=

#Optional: Personally add the flag “-std=c++11”
CCFLAGS= -g -std=c++11

#all:	echo-server echo-client
all:	clean game

game:$(OBJS)
	$(CXX) -o play $(OBJS)

clean:
	rm -f $(OBJS) $(OBJS:.o=.d) game
