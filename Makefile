.default: all

all: CFOP

clean:
	rm -f CFOP *.o

CFOP: CFOP.o Cube.o
	g++ -Wall -Werror -std=c++17 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++17 -g -O -c $^