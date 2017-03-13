#include "Population.h"




/*
 * Default Constructor
 */
Population::Population(){} 


/*
 * Mutator and Accessor which modifies or returns single gene
 */
void Population::set_chromosome(int index, int _bitValue){
    this->chromosome.set_gene(index, _bitValue);
}
int Population::get_chromosome(int index){
	return this->chromosome.get_gene(index);
}

/*
 * Mutator and Accessor which modifies or returns whole chromosome
 */
void Population::set_chromosome(const vector<int> &_chromosome){
    this->chromosome.set_chrom(_chromosome);
}
vector<int> Population::get_chromosome(){
	return this->chromosome.get_chrom();
}

/*
 * Mutator and Accessor for fitness
 */
void Population::set_fitness(double _fitness){
    this->fitness = _fitness;
}
double Population::get_fitness(){
	return fitness;
}

/*
 * Mutator and Accessor for similarity
 */
void Population::set_similarity(double _similarity){
    this->similarity = _similarity;
}
double Population::get_similarity(){
	return similarity;
}

/*
 * Mutator and Accessor for decValue, which is dec value of binary chromosome 
 */
void Population::set_decValue(double _decValue){
    this->decValue = _decValue;
}
double Population::get_decValue(){
	return decValue;
}

/*
 * Mutator and Accessor for unboundVar
 */

void Population::set_unboundVar(double _unboundVar){
    this->unboundVar = _unboundVar;
}
double Population::get_unboundVar(){
	return unboundVar;
}

/*
 * Mutator and Accessor for boundVar
 */
void Population::set_boundVar(double _boundVar){
    this->boundVar = _boundVar;
}
double Population::get_boundVar(){
	return boundVar;
}
