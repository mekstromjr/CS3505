CC = g++
#-Wall Basic checking
#-fsanitize=undefined Looks for undefined stack behavior (ie. index out of bounds on heap, etc.)
#-fsanitize=address Looks for undefined heap behavior (ie. memory leaks, etc.)
CFLAGS = -g -Wall -fsanitize=undefined -fsanitize=address

test: lab4
	./lab4 > log.txt

lab4: lab4.o
	$(CC) $(CFLAGS) -o lab4 lab4.o

lab4.o: lab4.cpp
	$(CC) $(CFLAGS) -c lab4.cpp

clean:
	rm -f *.o
	rm -f lab4