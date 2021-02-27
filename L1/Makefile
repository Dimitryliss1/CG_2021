run: binary
	./binary

binary: main.o libmatrix.a libline.a
	g++ -o binary main.o -lSDL_bgi -lSDL2 -L. -lmatrix -lline
	rm -f *.o *.a
	clear

main.o: main.cpp
	g++ -c main.cpp

libmatrix.a: matrix.o
	ar cr libmatrix.a matrix.o

matrix.o: matrix.cpp
	g++ -c matrix.cpp

libline.a: line.o
	ar cr libline.a line.o

line.o: line.cpp
	g++ -c line.cpp

clean:
	rm -f *.o *.a binary
