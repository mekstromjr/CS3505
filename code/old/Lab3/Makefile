CC = g++
CFLAGS = -Wall
CARDIR = /workspaces/CS3505/code/Lab3/Carlib


all: main

main car: main.o libCar.a
	$(CC) $(CFLAGS) -o $@ main.o Car.o

car2: main.o $(CARDIR)/lib/libCar.a
	$(CC) $(CFLAGS) -L$(CARDIR)/lib -o $@ main.o libCar.a

main.o: main.cpp $(CARDIR)/include/Car.h
	$(CC) $(CFLAGS) -I$(CARDIR)/include -c main.cpp

Car.o: Car.cpp $(CARDIR)/include/Car.h
	$(CC) $(CFLAGS) -I$(CARDIR) -c Car.cpp Car.h

# libCar.a: Car.o
# 	ar -rcf libCar.a Car.o


clean:
	rm -f *.o
	rm -f main
