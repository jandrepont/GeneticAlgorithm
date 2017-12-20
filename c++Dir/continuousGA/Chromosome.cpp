#include "Chromosome.h"
#include <random>
#include <ctime>

/*
 * Default Constructor
 */
Chromosome::Chromosome()
{

	size = 10;


	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1023.00);  //(min, max)

	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;

	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());


	//this->gene.assign(10, dist(rng));//(10, double());

    //initialize both vectors
	for(int i = 0; i < size; i++){
		//generate 10 random numbers
		gene.push_back(dist(rng));
        localSim.push_back(0);
	}

	set_fitness();

}

/*
 * Constructor that sets size of array of genes
 */
Chromosome::Chromosome(int _size)
{

	size = _size;

	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1023.00);  //(min, max)

	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;

	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());

	for(int i = 0; i < size; i++){
		gene.push_back(dist(rng));
        localSim.push_back(0);
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
	gene[index] = value;
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
	gene = _gene;
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
	fitness = funct.functionZakharov(gene, size);

}
double Chromosome::get_fitness()
{
	return fitness;
}

//set fitness
void Chromosome::set_fit(int fit)
{
	fitness = fit;
}

/*
 * Getter and setter for local similarity vals,
 * directly correlate to the gene vector
 */
 void Chromosome::set_locSim(int index, double similarity)
 {
     localSim[index] = similarity;
 }

 double Chromosome::get_locSim(int index)
 {
     return localSim[index];
 }

 /*
  * Getter and setter for similarity of a chromosome's total input
  * compared across all other chromosome of a population
 */
 void Chromosome::set_totSim(double similarity)
 {
     totalSim = similarity;
 }
 double Chromosome::get_totSim()
 {
     return totalSim;
 }

 /*
  * get_input returns the total val of the genes for a chromosome
*/
double Chromosome::get_input()
{
    double sum;
    for(int i = 0; i < size; i++)
    {
        sum += gene[i];
    }
    return sum;
}

/*
 * mutate method that is called by Population, changes the bit value of a random gene
 * after doing this the variables are calculated again as is the fitness value
 */
void Chromosome::mutate_gene(int index)
{

	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1023.00);  //(min, max)

	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;

	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());


	gene[index] = dist(rng);
	set_fitness();
}
