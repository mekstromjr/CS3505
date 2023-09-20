# Michael Ekstrom
# u1170312
# A4: A Trie and Rule-of-Three 
CC = g++
CFLAGS = -g -Wall -fsanitize=undefined -fsanitize=address
INCLUDE = $(PROJECT)include/
PROJECT = ./

runSmall: TrieTest
	./TrieTest smallDictionary.txt query.txt

runLarge: TrieTest
	./TrieTest largeDictionary.txt query.txt

TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o

Trie.o: Trie.cpp $(INCLUDE)Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp -I$(INCLUDE)

TrieTest.o: TrieTest.cpp $(INCLUDE)Trie.h
	$(CC) $(CFLAGS) -c TrieTest.cpp -I$(INCLUDE)

test: test.cpp $(INCLUDE)Trie.h
	$(CC) $(CFLAGS) -o test test.cpp -I$(INCLUDE)
	./test

clean:
	rm -f *.o
	rm -f TrieTest


