//population stores variables and characteristics of each population within each generation
#include "Chromosome.h"
using namespace std;

#ifndef POPULATION_H
#define POPULATION_H

class Population{
    private:
    
        Chromosome chromosome;
        double fitness;
        double similarity;
        double decValue;
        double unboundVar;
        double boundVar;

    public:

        //Default Constructor
        Population();
        //setter and getter methods for chromosomes/genes
        void set_chromosome(int index, int _bitValue);
        int get_chromosome(int index);
		
		//overloaded set_chromosome method for allowing to pass a vector
        void set_chromosome(const vector<int> &_chromosome);
        vector<int> get_chromosome();
		
		//Fitness getter and setter methods
        void set_fitness(double _fitness);
        double get_fitness();
		
		//Similarity Mutator and Accessor methods
		void set_similarity(double _similarity);
        double get_similarity();
		
		//DecValue Mutator and Accessor
		void set_decValue(double _decValue);
        double get_decValue();
		
		//UnboundVar Mutator and Accessor
		void set_unboundVar(double _unboundVar);
        double get_unboundVar();
		
		//BoundVar Mutator and Accessor
		void set_boundVar(double _boundVar);
        double get_boundVar();

}population;

#endif
