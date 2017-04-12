//population stores variables and characteristics of each population within each generation
#include "Chromosome.h"


#ifndef POPULATION_H
#define POPULATION_H

class Population {
    private:
    
		std::vector<Chromosome> chromosome;
        double similarity;
		int numOfChrom;
		int sizeOfGenes;
		int numOfVars;
		int popNum;
		float elite;
		float cross;
    public:

        //Default Constructor
        Population();

		//Constructor for setting the size and numOfVars for each Chrom in Pop
		Population(int numOfChrom, int sizeOfGenes, int numOfVars);
		
		//Similarity Mutator and Accessor methods
		void set_similarity(double _similarity);
        void findSim();
		double get_similarity();
				
		//Getter for fitness
		double get_fitness(int index);
		
		//sort method, currently using bubble sort
		void sort();
		
		//Getter and setter for numOfChrom
		void set_numOfChrom(int _num);
		int get_numOfChrom();

		//Getter and setter for sizeOfGenes
		void set_sizeOfGenes(int _size);
		int get_sizeOfGenes();

		//Getter and setter for numOfVars
		void set_numOfVars(int _vars);
		int get_numOfVars();
		
		//Getter and setter for population number?
		void set_popNum(int _num);
		int get_popNum();

		//Getter and setter for elite rate
		void set_elite(float rate);
		float get_elite();
		
		//Getter and setter for the cross rate
		void set_cross(float rate);
		float get_cross();

		//Gett and setter for chromosome using bit values
		void set_gene(int chromNum , int index, int bitVal);
		int get_gene(int chromNum, int index);

		//Getter and setter for chromosome using vectors
		void set_chrom(int chromNum, Chromosome chrom);
		Chromosome get_chrom(int chromNum);
		
		
		//Mutate method
		void mutate(int mutateRate);

		//Getter and setter for finding similarity amongst chromosomes
		
		//crossover method needs multiple populations





};

#endif
