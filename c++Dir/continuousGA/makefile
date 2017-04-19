default = executable

executable: main.cpp Population.o function.o Chromosome.o
	g++ main.cpp Population.o function.o Chromosome.o -o pls.exe

Population.o: Population.cpp
	g++ -c Population.cpp

Population.cpp: Population.h
	g++ Population.h 

mainChrom.cpp: mainChrom.cpp Chromosome.o function.o 
	g++ mainChrom.cpp Chromosome.o function.o -o pls.exe

Chromosome.o: Chromosome.cpp
	g++ -c Chromosome.cpp -std=c++11

Chromosome.cpp: Chromosome.h
	g++ Chromosome.h

function.o: function.cpp
	g++ -c function.cpp

function.cpp: function.h
	g++ function.h
