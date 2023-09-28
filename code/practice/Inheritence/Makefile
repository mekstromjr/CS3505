CC = g++
CFLAGS = -Wall


run: main
	./main

main: main.o Cat.o Animal.o
	$(CC) $(CFLAGS) -o main main.o Cat.o Animal.o

main.o: main.cpp Animal.h Cat.h
	$(CC) $(CFLAGS) -c main.cpp -I./

Animal.o: Animal.cpp Animal.h
	$(CC) $(CFLAGS) -c Animal.cpp -I./

Cat.o: Cat.cpp Cat.h Animal.h
	$(CC) $(CFLAGS) -c Cat.cpp -I./