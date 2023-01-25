CC = g++
CFLAGS = -Wall
CARDIR = ./Carlib


all: main

main: main.o Car.o Car.h
	$(CC) $(CFLAGS) -o main main.o Car.o

main.o: main.cpp Car.h
	$(CC) $(CFLAGS) -c main.cpp

libCar.a: Car.o
	ar -rcf libCar.a Car.o
	
Car.o: Car.cpp Car.h
	$(CC) $(CFLAGS) -c Car.cpp


clean:
	rm -f *.o
	rm -f main
