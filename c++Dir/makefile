default = executable

executable: main.cpp Population.o function.o Chromosome.o
	g++ main.cpp Population.o function.o Chromosome.o -o pls.exe

Population.o: Population.cpp
	g++ -c Population.cpp

Population.cpp: Population.h
	g++ Population.h 

Chromosome.o: Chromosome.cpp
	g++ -c Chromosome.cpp

Chromosome.cpp: Chromosome.h
	g++ Chromosome.h

function.o: function.cpp
	g++ -c function.cpp

function.cpp: function.h
	g++ function.h
