//Chromsome data structure used in populations
#include "function.h"
#include <cmath> 
#include <time.h>

using namespace std;



#ifndef CHROM_H
#define CHROM_H

class Chromosome{
    
    public:
		// default constructor
		Chromosome();
        Chromosome(int size, int numOfVars);
		//destructor
		//~Chromosome();
		
		//Comparison function for comparing fitness and sorting chromosomes
		bool operator<(const Chromosome rhs);
		
		//Getters and Setters
		void set_gene(int index, int value);
		int get_gene(int index);
		int get_size();
		//Getters and Setters for entirety of vector<int> gene
		void set_chrom(vector<int> chrom);
		vector<int> get_chrom();
		//getter and setter for decVal (setter only called
		//implicitly when genes are initialized
		void set_vars(bool mutate);
		int get_var(int index);
		//getter and setter for numOfVars
		void set_numOfVars(int _numOfVars);
		int get_numOfVars();
		//getter and setter for boundedVariable
		//uses function.h to set the variable
		void set_boundedVariable();
		double get_boundedVariable(int index);
		//getter and setter for fitness
		//uses function.h to get values
		void set_fitness();
		double get_fitness();
		//set fitness
		void set_fit(int fit);
		//Mutate method that is called by population
		void mutate_gene(int index);
	
	private:

        vector<int> gene;
		int size;
		int numOfVars;
		vector<int> variable;
		vector<double> boundedVariable;
		double fitness;

};

#endif 
