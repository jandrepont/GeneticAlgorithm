//population stores variables and characteristics of each population within each generation
#include "Chromosome.h"


#ifndef POPULATION_H
#define POPULATION_H

class Population {
    private:

		std::vector<Chromosome> chromosome;
        double globalAverage;
		int numOfChrom;
		int sizeOfChrom;
		int popNum;
		float elite;
		float cross;

	public:

        //Default Constructor
        Population();

		//Constructor for setting the size and numOfVars for each Chrom in Pop
		Population(int numOfChrom, int sizeOfChrom);



        //localSim getter and setter
        void set_locSim(int chromIndex, int geneIndex, double similarity);
        double get_locSim(int chromIndex, int index);

        //totalSim getter
        double get_totSim(int index);


		//Getter for fitness
		double get_fitness(int index);

		//sort method, currently using quickSort
		void sort(int p, int q);
		int partition(int p, int q);

		//Getter and setter for numOfChrom
		void set_numOfChrom(int _num);
		int get_numOfChrom();

		//Getter and setter for sizeOfGenes
		void set_sizeOfChrom(int _size);
		int get_sizeOfChrom();

		//Getter and setter for population number?
		void set_popNum(int _num);
		int get_popNum();

		//Getter and setter for elite rate
		void set_elite(float rate);
		float get_elite();

		//Getter and setter for the cross rate
		void set_cross(float rate);
		float get_cross();

		//Gett and setter for chromosome
		void set_gene(int chromNum , int index, double value);
		int get_gene(int chromNum, int index);

		//Getter and setter for chromosome using vectors
		void set_chrom(int chromNum, Chromosome chrom);
		Chromosome get_chrom(int chromNum);

        //getter for globalAverage, gives the similarity of the entire population
        //may or may not be useful, provides a very broad definition of similarity
        double get_globalAverage();

		//Mutate method
		void mutate(int mutateRate);

        /*
         * similarity methods, tests for similarity across the pop
         */
        void findTotalSim(double epsilon);
        void findLocalSim(double epsilon);


};

#endif
