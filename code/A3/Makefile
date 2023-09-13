# Michael Ekstrom 
# CS3505 
CC = g++
CFLAGS = -Wall
HARULIB = $(HARUDIR)lib/
HARUINCLUDE = $(HARUDIR)include/
HARUSRC = $(HARUDIR)src/
INCLUDE = $(PWD)include/
SRC = $(PWD)src/
HARUDIR = $(PWD)libharu/
PWD = ./


sinePDF: $(SRC)sinePDF.o $(SRC)HaruPDF.o $(SRC)Sine.o
	$(CC) $(CFLAGS) -o sinePDF $(SRC)sinePDF.o $(SRC)HaruPDF.o $(SRC)Sine.o -L$(HARUSRC) -lhpdfs

sinePDF.o: $(SRC)sinePDF.cpp $(INCLUDE)Sine.h $(INCLUDE)HaruPDF.h
	$(CC) $(CFLAGS) -c $(SRC)sinePDF.cpp -I$(HARUINCLUDE) -I$(INCLUDE)
	mv $@ $(SRC)

HaruPDF.o: $(SRC)HaruPDF.cpp $(INCLUDE)HaruPDF.h
	$(CC) $(CFLAGS) -c $(SRC)HaruPDF.cpp -I$(HARUINCLUDE) -I$(INCLUDE) 
	mv $@ $(SRC)

Sine.o: $(SRC)Sine.cpp $(INCLUDE)Sine.h
	$(CC) $(CFLAGS) -c $(SRC)Sine.cpp -I$(INCLUDE)
	mv $@ $(SRC)


example: $(SRC)pdfExample.o $(HARUSRC)libhpdfs.a
	$(CC) $(CFLAGS) -o example $(SRC)pdfExample.o -L$(HARUSRC) -lhpdfs
	./example

pdfExample.o: $(SRC)pdfExample.cpp $(HARUINCLUDE)hpdf.h
	$(CC) $(CFLAGS) -c $(SRC)pdfExample.cpp -I$(HARUINCLUDE)
	mv pdfExample.o $(SRC)

test: $(SRC)test.cpp
	$(CC) $(CFLAGS) -o $@ $(SRC)$@.cpp
	./test "hello" > testLog.txt

sineTest: $(PWD)sinePDF
	./sinePDF "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."

clean:
	rm -f $(SRC)*.o
	rm -f test
	rm -f sinePDF