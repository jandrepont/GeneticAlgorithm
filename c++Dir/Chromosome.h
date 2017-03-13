//Chromsome data structure used in populations
#include <vector>
#include <cmath> 
#include <iostream>
using namespace std;

#ifndef CHROM_H
#define CHROM_H

class Chromosome{
    private:

        vector<int> gene;
    
    public:
        
        Chromosome();
        
		/*
		 * Mutator and Accessor for gene index
		 *
		 */
        void set_gene(int index, int _bitVal){
           this->gene[index] = _bitVal;
        }
		int get_gene(int index){
			return gene[index];
		}

		/*
		 * Mutator and Accessor for chromosome
		 */
        void set_chrom(const vector<int> &_chromosome){
            this->gene = _chromosome;
        }
		vector<int> get_chrom(){
			return gene;
		}
}chromosome;

#endif 
