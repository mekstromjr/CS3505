# Michael Ekstrom 
# CS3505 
CC = g++
CFLAGS = -Wall
LIB = $(CARDIR)lib/
INCLUDE = $(CARDIR)include/
SRC = $(PWD)src/
CARDIR = $(PWD)Carlib/
PWD = ./

car: $(SRC)main.o
	$(CC) $(CFLAGS) -o $@ $(SRC)main.o -L$(LIB) -lCar 

Car.o: $(SRC)Car.cpp $(INCLUDE)Car.h
	$(CC) $(CFLAGS) -c $(SRC)Car.cpp -I$(INCLUDE)
	mv Car.o $(SRC)

main.o: $(SRC)main.cpp $(INCLUDE)Car.h
	$(CC) $(CFLAGS) -c $(SRC)main.cpp -I$(INCLUDE)
	mv main.o $(SRC)
	
test: car log.txt
	./car > log.txt

libCar.a: $(INCLUDE)Car.h $(SRC)Car.o 
	ar -rcf libCar.a $(SRC)Car.o
	mv libCar.a $(LIB)

log.txt:
	touch log.txt

move:
	touch mvTest.txt
	mv mvTest.txt $(SRC)

clean:
	rm -f $(SRC)*.o
	rm -f car
	rm -f log.txt
	rm -f $(SRC)mvTest.txt