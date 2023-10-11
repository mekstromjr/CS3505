CC = g++
CFLAGS = -Wall
INCLUDE = $(PROJECT)
PROJECT = ./


run: main
	./main

main: main.o ThreeTuple.o
	$(CC) $(CFlAGS) -o main main.o ThreeTuple.o

main.o: main.cpp ThreeTuple.h
	$(CC) $(CFLAGS) -c main.cpp

ThreeTuple.o: ThreeTuple.cpp ThreeTuple.h
	$(CC) $(CFLAGS) -c ThreeTuple.cpp