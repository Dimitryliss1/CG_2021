run: triangle
	./triangle

triangle: main.o libmatrix.a libline.a libpyramid.a libtriangle.a
	g++ -o triangle main.o -lSDL_bgi -lSDL2 -L. -lmatrix -lline -lpyramid -ltriangle
	rm -f *.o *.a
	clear

main.o: main.cpp
	g++ -c main.cpp

libpyramid.a: pyramid.o
	ar cr libpyramid.a pyramid.o

pyramid.o: pyramid.cpp
	g++ -c pyramid.cpp

libtriangle.a: triangle.o
	ar cr libtriangle.a triangle.o

triangle.o: triangle.cpp
	g++ -c triangle.cpp

libmatrix.a: matrix.o
	ar cr libmatrix.a matrix.o

matrix.o: matrix.cpp
	g++ -c matrix.cpp

libline.a: line.o
	ar cr libline.a line.o

line.o: line.cpp
	g++ -c line.cpp

clean:
	rm -f *.o *.a triangle
