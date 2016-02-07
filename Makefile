Lab3: main.o
	g++ -g -std=c++11 -Wall -o Lab3 main.o

main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

clean:
	rm *o Lab3
	clean done
