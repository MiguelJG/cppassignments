all: p6

CC=g++
VERSION=-std=c++11

p6: DNI.o main.o
	$(CC) $(VERSION) DNI.o main.o -o p6

main.o: ABB.h NodoBB.h main.cpp
	$(CC) $(VERSION) -c main.cpp

DNI.o: DNI.cpp DNI.h
	$(CC) $(VERSION) -c DNI.cpp

clean:
	rm *.o

soclean:
	rm *.o p6
