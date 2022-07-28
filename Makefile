CXX := g++
CXXFLAGS= -std=c++11

jogo_da_forca: forca.o libforca.o
	$(CXX) $(CXXFLAGS) forca.o libforca.o -o jogo_da_forca

forca.o: forca.cpp
	$(CXX) -c forca.cpp

libforca.o: libforca.cpp
	$(CXX) -c libforca.cpp

all: jogo_da_forca

run: jogo_da_forca
	./jogo_da_forca

clean:
	rm -f forca.o libforca.o jogo_da_forca 