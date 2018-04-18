all: p5

CC=g++
VERSION=-std=c++11

p5: DNI.o main.o
	$(CC) $(VERSION) DNI.o main.o -o p5

main.o: funciones.h main.cpp
	$(CC) $(VERSION) -c main.cpp

DNI.o: DNI.cpp DNI.h
	$(CC) $(VERSION) -c DNI.cpp

clean:
	rm *.o

soclean:
	rm *.o p4
