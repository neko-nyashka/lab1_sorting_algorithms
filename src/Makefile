FLAGS = -Wall -Werror -Wextra -std=c++11

all: sort 

sort: sort.o flight.o
	g++ $(FLAGS) -o sort sort.o flight.o


sort.o: sort.cpp
	g++ $(FLAGS) -c sort.cpp

flight.o: flight.cpp
	g++ $(FLAGS) -c flight.cpp

clean:
	rm -rf *.o sort 

rebuild: clean all