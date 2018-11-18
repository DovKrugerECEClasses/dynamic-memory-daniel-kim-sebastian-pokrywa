CXX	:=	g++ -std=c++11 -g

String: color.o bitmap.o main.o
	$(CXX) bitmap.o color.o main.o -o Bitmap

color.o: color.cc color.h
	$(CXX) -c color.cc

bitmap.o: bitmap.cc bitmap.h
	$(CXX) -c bitmap.cc

main.o: bitmap.h color.h
	$(CXX) -c main.cc
