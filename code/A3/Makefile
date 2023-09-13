# Michael Ekstrom 
# CS3505 
# A3: Facades and Makefiles
CC = g++
CFLAGS = -Wall
LIBHARU = ./libharu


sinePDF: sinePDF.o HaruPDF.o Sine.o
	$(CC) $(CFLAGS) -o sinePDF sinePDF.o HaruPDF.o Sine.o -L$(LIBHARU)/src -lhpdfs

sineTest: sinePDF
	./sinePDF "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

sinePDF.o: sinePDF.cpp Sine.h HaruPDF.h
	$(CC) $(CFLAGS) -c sinePDF.cpp -I$(LIBHARU)/include 

HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -c HaruPDF.cpp -I$(LIBHARU)/include

Sine.o: Sine.cpp Sine.h
	$(CC) $(CFLAGS) -c Sine.cpp

clean:
	rm -f *.o
	rm -f test
	rm -f sinePDF