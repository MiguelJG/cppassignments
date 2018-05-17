all: p7

CC=g++
VERSION=-std=c++11

p7: DNI.o main.o
	$(CC) $(VERSION) DNI.o main.o -o p7

main.o: AVL.h NodoAVL.h main.cpp
	$(CC) $(VERSION) -c main.cpp

DNI.o: DNI.cpp DNI.h
	$(CC) $(VERSION) -c DNI.cpp

clean:
	rm *.o

soclean:
	rm *.o p7
