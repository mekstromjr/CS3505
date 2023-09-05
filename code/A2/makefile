# Michael Ekstrom 
# CS3505 
CC = g++
CFLAGS = -Wall

testSine: Sine.cpp testSine.cpp Sine.h
	$(CC) $(CFLAGS) -o $@ $@.cpp Sine.cpp


test: test.cpp
	$(CC) $(CFLAGS) -o $@ $@.cpp 


clean:
	rm -f testSine
	rm SineData.txt
	rm test
	touch SineData.txt