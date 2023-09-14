CC = g++
CFLAGS = -Wall -g
DEBUGFLAGS = -fsanitize=undefined  -fsanitize=address

lab4: lab4.cpp
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -o $@ $@.cpp



clean:
	rm -f lab4
	rm -f *.o
	rm -f *.h.gch