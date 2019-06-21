main: NodoArbol.o Militar.o main.o
	g++ NodoArbol.o Militar.o main.o -o run

NodoArbol.o: NodoArbol.cpp
	g++ -c NodoArbol.cpp

Militar.o: Militar.cpp
	g++ -c Militar.cpp

main.o: main.cpp	
	g++ -c main.cpp