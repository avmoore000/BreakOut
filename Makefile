# Created 5-11-2020
# Author Andrew Moore
# Modified 5-11-2020

CC = g++
CFLAGS = -g -Wall -std=gnu++17
LIBS = -lGL -lGLU -lglut
DIR = $(shell mkdir build)
#CLEANDIR = $(shell rm -rf build)

# Make the BreakOut binary
default:
	$(DIR)\
	make BreakOut;

all:
	$(DIR)\
	make BreakOut;

clean:
	$(RM) *.o *.~ *.out src/*.o 

BreakOut: src/main.o
	$(CC) $(CFLAGS) -o build/BreakOut src/main.o $(LIBS)
	$(RM) src/*.o

main.o: src/main.cpp
	$(CC) $(CFLAGS) -c src/main.cpp $(LIBS)
