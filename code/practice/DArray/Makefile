CC = g++
CFLAGS =  -g -Wall -fsanitize=undefined -fsanitize=address


test: testDArray
	./testDArray > log.txt

testDArray: testDArray.o DArray.o 
	$(CC) $(CFLAGS) -o testDArray testDArray.o DArray.o

testDArray.o: testDArray.cpp DArray.h
	$(CC) $(CFLAGS) -c testDArray.cpp

DArray.o: DArray.cpp DArray.h
	$(CC) $(CFLAGS) -c DArray.cpp