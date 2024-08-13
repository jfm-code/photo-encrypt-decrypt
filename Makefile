CC = g++ 
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -lboost_unit_test_framework -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system

DEPS = FibLFSR.hpp PhotoMagic.hpp
OBJECT = FibLFSR.o PhotoMagic.o
PROGRAM = PhotoMagic

.PHONY: all clean lint

all: $(PROGRAM) test PhotoMagic.a

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

PhotoMagic.a: FibLFSR.o PhotoMagic.o
	ar rcs PhotoMagic.a FibLFSR.o PhotoMagic.o

$(PROGRAM): main.o $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

test: test.o $(OBJECT)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o $(PROGRAM) PhotoMagic.a test

lint:
	cpplint *.cpp *.hpp
