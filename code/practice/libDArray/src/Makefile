CC = g++
CFLAGS =  -g -Wall -fsanitize=undefined -fsanitize=address
INCLUDE = ../include/

test: testDArray
	./testDArray > log.txt

testDArray: testDArray.o libDArray.a
	$(CC) $(CFLAGS) -o testDArray testDArray.o -L./ -lDArray

testDArray.o: testDArray.cpp $(INCLUDE)DArray.h
	$(CC) $(CFLAGS) -c testDArray.cpp -I$(INCLUDE)

DArray.o: DArray.cpp $(INCLUDE)DArray.h
	$(CC) $(CFLAGS) -c DArray.cpp -I$(INCLUDE)

libDArray.a: $(INCLUDE)DArray.h DArray.o 
	ar -rcf libDArray.a DArray.o

clean:
	rm -f *.o
	rm -f testDArray