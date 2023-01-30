CC = g++
CFLAGS = -Wall
INCLUDE = ../libharu/include/
LIB = ../libharu/src/


spiralPDF: spiralPDF.cpp HaruPDF.h HaruPDF.cpp Spiral.h Spiral.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $@.cpp  -L$(LIB) HaruPDF.h HaruPDF.cpp Spiral.h Spiral.cpp -lhpdfs

pdfExample:
	$(CC) $(CFLAGS) -I$(INCLUDE) -o pdfExample pdfExample.cpp -L$(LIB) -lhpdfs



clean:
	rm -f *.o
	rm -f pdfExample
	rm -f pdfExample.pdf
	rm -f spiralPDF
	rm -f spiralPDF.pdf