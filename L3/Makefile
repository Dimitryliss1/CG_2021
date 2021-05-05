run: triangle
	./triangle

triangle: main.o libmatrix.a libline.a libtriangle.a
	g++ -o triangle main.o -lSDL_bgi -lSDL2 -L. -lmatrix -lline -ltriangle
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

libtriangle.a: triangle.o
	ar cr libtriangle.a triangle.o

triangle.o: triangle.cpp
	g++ -c triangle.cpp

clean:
	rm -f *.o *.a triangle
