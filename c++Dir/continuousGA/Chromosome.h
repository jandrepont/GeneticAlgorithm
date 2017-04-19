//Chromsome data structure used in populations
#include "function.h"
#include <cmath> 
#include <time.h>




#ifndef CHROM_H
#define CHROM_H

class Chromosome{
    
    public:
		// default constructor
		Chromosome();
        Chromosome(int size);
		//destructor
		//~Chromosome();
		
		//Comparison function for comparing fitness and sorting chromosomes
		bool operator<(const Chromosome rhs);
		
		//Getters and Setters
		void set_gene(int index, double value);
		double get_gene(int index);
		int get_size();
		
		//Getters and Setters for entirety of vector<int> gene
		void set_chrom(std::vector<double> _gene);
		std::vector<double> get_chrom();
		
		//getter and setter for fitness
		//uses function.h to get values
		void set_fitness();
		double get_fitness();
		
		//set fitness
		void set_fit(int fit);
		
		//Mutate method that is called by population
		void mutate_gene(int index);
	
	private:

		std::vector<double> gene;
		int size;
		double fitness;

};

#endif 
