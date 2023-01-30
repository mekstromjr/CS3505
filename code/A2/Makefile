# Michael Ekstrom 
# CS3505 
# A2: Spiral
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
	$(CC) $(CFLAGS) -I$(INCLUDE) -c HaruPDF.cpp HaruPDF.h hpdf.h

clean:
	rm -f *.o
	rm -f *.h.gch
	rm -f spiralPDF
	rm -f spiralPDF.pdf