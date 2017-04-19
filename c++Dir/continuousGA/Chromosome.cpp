#include "Chromosome.h"
#include <random> 
#include <ctime> 

/*
 * Default Constructor
 */
Chromosome::Chromosome()
{
		
	this->size = 10;
	
	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1024.00);  //(min, max)
		    
	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;
			 
	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());
 

	//this->gene.assign(10, dist(rng));//(10, double());
	
	
	for(int i = 0; i < size; i++){
		//generate 10 random numbers
		this->gene.push_back(dist(rng));
	}
	 
	set_fitness();

}

/*
 * Constructor that sets size of array of genes
 */
Chromosome::Chromosome(int _size)
{

	this->size = _size;
	
	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1024.00);  //(min, max)
		    
	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;
			 
	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());
				
	for(int i = 0; i < size; i++){
		gene.push_back(dist(rng));
	}

	set_fitness();
}

/*
Chromosome::~Chromosome() 
{
	fitness = 0;
}
*/


/*
 *bool comparison for sorting
 */ 
bool Chromosome::operator<(const Chromosome rhs)
{
	return fitness < rhs.fitness;
}

/*
 *Getter and setter for genes
 */
void Chromosome::set_gene(int index, double value)
{
	this->gene[index] = value;
	set_fitness();
}

double Chromosome::get_gene(int index)
{
	return gene[index];
}
/*
 * Getter for size
 */
int Chromosome::get_size()
{
	return size;
}

/*
 * Getter and setter for whole array of genes 
 */
void Chromosome::set_chrom(std::vector<double> _gene)
{
	this->gene = _gene;	
}

std::vector<double> Chromosome::get_chrom()
{
	return gene;
}

/*
 * Getter and setter for fitness values, calls function from function.h
 */
void Chromosome::set_fitness()
{	
	function funct;
	fitness = funct.function1Fitness(gene, size);
}
double Chromosome::get_fitness()
{
	return fitness;
}

//set fitness
void Chromosome::set_fit(int fit){
	this->fitness = fit;
}

/*
 * mutate method that is called by Population, changes the bit value of a random gene
 * after doing this the variables are calculated again as is the fitness value
 */
void Chromosome::mutate_gene(int index)
{
	
	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1024.00);  //(min, max)
		    
	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;
			 
	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());
	
	
	gene[index] = dist(rng);
	set_fitness();
}



















