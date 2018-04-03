all: p3

CC=g++
VERSION=-std=c++11

p3: matricula.o main.o
	$(CC) $(VERSION) matricula.o main.o -o p3
	
main.o: main.cpp
	$(CC) $(VERSION) -c main.cpp
	
matricula.o: matricula.cpp
	$(CC) $(VERSION) -c matricula.cpp
	
clean:
	rm *.o

soclean:
	rm *.o p3