


all: PolyFood


PolyFood: main.o Restaurant.o Table.o Menu.o Plat.o
	gcc -o PolyFood main.o Restaurant.o Table.o Menu.o Plat.o -lstdc++


main.o: main.cpp Restaurant.h
	gcc -o main.o -c main.cpp 

Restaurant.o: Restaurant.cpp Table.h Restaurant.h
	gcc -o Restaurant.o -c Restaurant.cpp

Table.o: Table.cpp Menu.h Table.h
	gcc -o Table.o -c Table.cpp

Menu.o: Menu.cpp Plat.h Menu.h
	gcc -o Menu.o -c Menu.cpp

Plat.o: Plat.cpp Plat.h
	gcc -o Plat.o -c Plat.cpp

clean:
	rm -rf PolyFood Table.o Plat.o Menu.o Restaurant.o main.o

install:
	make 
	./PolyFood