#include "Population.h"
#include "algorithm" 

/*
 * Default Constructor
 */

Population::Population()
{
	//std::vector<Chromosome> chromosome;
	
	this->similarity = 0;
	this->numOfChrom = 200;
	this->sizeOfChrom = 10;
	this->popNum = 0;
	this->elite = 0.0;
	this->cross = 0.0;


} 
/*
 * Constructor for setting the size and numOfVars for each chromosome in Pop
 */

Population::Population(int _numOfChrom, int _sizeOfChrom)
{
	
	this->numOfChrom = _numOfChrom;

	this->sizeOfChrom = _sizeOfChrom;

	this->similarity = 0;

	this->popNum = 0;

	this->elite = .05;
	 
	this->cross = .8;
	
	for(int i = 0; i < numOfChrom; i++)
	{
		Chromosome chrom(sizeOfChrom);
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
	return chromosome[index].get_fitness();
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
 * Getter and setter for sizeOfChrom
 */
void Population::set_sizeOfChrom(int _size)
{
	this->sizeOfChrom = _size;
}
int Population::get_sizeOfChrom()
{
	return sizeOfChrom;
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
 * Getter and setter for chromosome's bit values
 */
void Population::set_gene(int chromNum, int index, double value)
{
	this->chromosome[chromNum].set_gene(index, value);

}
int Population::get_gene(int chromNum, int index)
{
	return chromosome[chromNum].get_gene(index);
}

/*
 * Getter and setter for chromosome using vectors
 */
void Population::set_chrom(int chromNum, Chromosome chrom)
{
	//this->chromosome[chromNum].set_chrom(chrom.get_chrom());
	this->chromosome[chromNum] = chrom;
	//need to recompute the chrom values
	chromosome[chromNum].set_fitness();

}
Chromosome Population::get_chrom(int chromNum)
{
	return this->chromosome[chromNum];
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
		if(randChrom < 10)
		{
			randChrom += 10;
		}

		int randGene = rand() % sizeOfChrom;
		//std::cout << "randChrom = " << randChrom << "\n";
		chromosome[randChrom].mutate_gene(randGene);
		//n++;
	}
}

/*
 * Finds the similarity between chromosomes based on their bit values at index

void Population::findSim()
{

	double simBits = 0.0;
	double simPerc = 0.0;
	for(int i = 0; i < numOfChrom-1; i++)
	{
		for(int j = i + 1; j < numOfChrom; j++)
		{
			
			if(chromosome[i].get_fitness() == chromosome[j].get_fitness())
			{	
				simBits += sizeOfChrom;
			}
			
			if(chromosome[i].get_fitness() != chromosome[j].get_fitness())
			{	
				for(int k = 0; k < sizeOfChrom; k++)
				{
					if(chromosome[i].get_gene(k) == chromosome[j].get_gene(k))
					{
						simBits += 1;
					}
					
				}
			}
			
			if(simBits > 0)
			{
				simPerc += (simBits / 160);
				simBits = 0;	
			}
		}
		
		simPerc = (simPerc / (200-i));
	}
	
	set_similarity(simPerc);
}
*/





















