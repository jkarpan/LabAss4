#	Written by Jordan Karpan - 5041823

main: dictionary.o main.o
	g++ dictionary.o main.o -o main
	
dictionary.o: dictionary.cpp includes.h
	g++ -c dictionary.cpp
	
main.o: main.cpp includes.h
	g++ -c main.cpp
	
clean:
	rm *.o main