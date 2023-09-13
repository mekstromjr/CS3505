# Michael Ekstrom 
# CS3505 
# A3: A Trie and Rule-of-Three
CC = g++
CFLAGS = -Wall -fsanitize=undefined -fsanitize=address
INCLUDE = #../libharu/include/
LIB = #../libharu/src/


TrieTest: Trie.o
	$(CC) $(CFLAGS) -I$(INCLUDE) -o $@ $@.cpp  -L$(LIB) Trie.o

Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $@ $@.cpp  -L$(LIB) Trie.cpp Trie.h

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $@ $@.cpp  -L$(LIB) Node.cpp

clean:
	rm -f *.o
	rm -f *.h.gch