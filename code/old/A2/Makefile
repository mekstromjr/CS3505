# Michael Ekstrom 
# CS3505 
# A2: Spiral
#PATHS ARE WRONG - THIS MAKEFILE DOES NOT WORK!! Use Lab3 Makefile as an example
CC = g++
CFLAGS = -Wall
INCLUDE = ../libharu/include/
LIB = ../libharu/src/


spiralPDF: spiralPDF.o HaruPDF.o Spiral.o 
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $@.cpp  -L$(LIB) HaruPDF.h HaruPDF.cpp Spiral.h Spiral.cpp -lhpdfs

spiralPDF.o: spiralPDF.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -c spiralPDF.cpp

Spiral.o: Spiral.cpp Spiral.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c Spiral.cpp Spiral.h
 
HaruPDF.o: HaruPDF.cpp HaruPDF.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c HaruPDF.cpp HaruPDF.h

clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f spiralPDF