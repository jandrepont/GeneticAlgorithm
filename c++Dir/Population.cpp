#include "Population.h"
#include "algorithm" 

/*
 * Default Constructor
 */

Population::Population()
{
	//std::vector<Chromosome> chromosome;
	vector<Chromosome> chromosome(200, Chromosome());
	this->similarity = 0;
	//this->numOfChrom = 0;
	//this->sizeOfGenes = 0;
	//this->numOfVars = 0;
} 
/*
 * Constructor for setting the size and numOfVars for each chromosome in Pop
 */

Population::Population(int _numOfChrom, int _sizeOfGenes, int _numOfVars)
{
	
	this->numOfChrom = _numOfChrom;

	this->sizeOfGenes = _sizeOfGenes;
		
	this->numOfVars = _numOfVars;

	this->similarity = 0;

	this->popNum = 0;

	this->elite = 0;
	 
	this->cross = 0;
	
	
	std::vector<Chromosome> chromosome;
	for(int i = 0; i < numOfChrom; i++)
	{
		Chromosome chrom(sizeOfGenes,numOfVars);
		this->chromosome.push_back(chrom);
	}
	sort();
	
}
/*
 * Getter and setter for similarity
 */
void Population::set_similarity(double _similarity){
    this->similarity = _similarity;
}
double Population::get_similarity(){
	return similarity;
}

/*
 * Getter and setter for chroms?
 */ 
double Population::get_fitness(int index)
{
	return this->chromosome[index].get_fitness();
}

/*
 * Getter and setter for numOfChrom
 */
void Population::set_numOfChrom(int _num)
{
	this->numOfChrom = _num;
}
int Population::get_numOfChrom()
{
	return numOfChrom;
}

/*
 * Getter and setter for sizeOfGenes
 */
void Population::set_sizeOfGenes(int _size)
{
	this->sizeOfGenes = _size;
}
int Population::get_sizeOfGenes()
{
	return sizeOfGenes;
}

/*
 * Getter and setter for numOfVars
 */
void Population::set_numOfVars(int _vars)
{
	this->numOfVars = _vars;
}
int Population::get_numOfVars()
{
	return numOfVars;
}

/*
 * Getter and setter for popNumber
 */
void Population::set_popNum(int _num)
{
	this->popNum = _num;
}
int Population::get_popNum()
{
	return popNum;
}

/*
 * Getter and setter for elite rate
 */
void Population::set_elite(float rate)
{
	this->elite = rate;
}
float Population::get_elite()
{
	return elite;
}

/*
 * Getter and setter for cross rate
 */ 
void Population::set_cross(float rate)
{
	this->cross = rate;
}
float Population::get_cross()
{
	return cross;
}


/*
 * Sorting method using bubble sort (for now, need to use better sorting algorith)
 */
void Population::sort()
{
	for(int i = 0; i < chromosome.size();i++)
	{
		for (int j = i + 1; j < chromosome.size(); j++)
		{
			if(chromosome[i] < chromosome[j])
			std::swap(chromosome[i], chromosome[j]);
		}
	}
}

/*
 * Mutate, for a specified of chromosomes, switches a random bit value in the gene of 
 * random chromosomes
 */

void Population::mutate(int mutateRate)
{
	//int n = 0;
	//std::cout << "mutateRate = " << mutateRate; 
	for(int i = 0; i < 10; i++)
	{ 
		//std::cout << " n is equal to " << n;
		int randChrom = rand() % numOfChrom;
		int randGene = rand() % sizeOfGenes;
		//std::cout << "randChrom = " << randChrom << "\n";
		chromosome[randChrom].mutate_gene(randGene);
		//n++;
	}
}










