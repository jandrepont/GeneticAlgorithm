default = executable

executable: main.o Generation.o Population.o Chromosome.o
	g++ main.o Generation.o Population.o Chromosome.o -o pls.exe
main.o: main.cpp 
	g++ -c main.cpp

Generation.o: Generation.cpp Generation.h Population.o
	g++ -c Generation.cpp

Population.o: Population.cpp Population.h Chromosome.h
	g++ -c Population.cpp

Chromosome.o: Chromosome.h
	g++ -c Chromosome.h -o Chromosome.o
