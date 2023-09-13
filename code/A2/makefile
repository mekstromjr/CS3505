# Michael Ekstrom 
# CS3505 
CC = g++
CFLAGS = 

testSine: testSine.cpp Sine.cpp Sine.h
	$(CC) $(CFLAGS) -o $@ $@.cpp Sine.cpp


test: testSine
	./testSine > SineData.txt


clean:
	rm -f testSine
	rm -f SineData.txt
	rm -f test
	touch SineData.txt