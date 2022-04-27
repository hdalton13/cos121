CXXFLAGS= -g -Wall -Og

a.out: Board.o conio.o Human.o main.o Priest.o
	g++ Human.o conio.o Board.o main.o Priest.o
Human.o: Human.cpp Board.o
	g++ -c Human.cpp
Priest.o: Priest.cpp Human.cpp
	g++ -c Priest.cpp
clean: 
	rm -f *.o a.out
