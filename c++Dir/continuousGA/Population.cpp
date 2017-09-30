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
	sort(0,200);

}
/*
 * Getter and setter for similarity
 */
void Population::set_global_similarity(double _similarity){
    this->similarity = _similarity;
}
double Population::get_global_similarity(){
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
	if(index >= 0 && index < sizeOfChrom)
	{
		this->chromosome[chromNum].set_gene(index, value);
	}
}
int Population::get_gene(int chromNum, int index)
{
	if(index >= 0 && index < sizeOfChrom)
	{
		return chromosome[chromNum].get_gene(index);
	}
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
 * Quicksort
 */
void Population::sort(int p, int q)
{
	int r;
	if(p<q)
	{
		r = partition(p,q);
		sort(p,r);
		sort(r+1, q);
	}
}

int Population::partition(int p, int q)
{
	double x = chromosome[p].get_fitness();
	int i = p;
	int j;

	for(j = p+1; j<q; j++)
	{
		if(chromosome[j].get_fitness() >= x)
		{
			i = i + 1;
			std::swap(chromosome[i], chromosome[j]);
		}
	}

	std::swap(chromosome[i], chromosome[p]);
	return i;
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
 * Finds the similarity between chromosomes
 */
void Population::findGlobalSim()
{
    double percDiff, totalPercDiff, popSim;

	for(int i = 0; i < numOfChrom-1; i++)
	{
		for(int j = i + 1; j < numOfChrom; j++)
		{
			percDiff = chromosome[i].get_fitness() - chromosome[j].get_fitness();
            percDiff = percDiff / chromosome[i].get_fitness();
            totalPercDiff += percDiff;
		}
        totalPercDiff = (totalPercDiff / (numOfChrom-i));
        popSim += totalPercDiff;
	}
    popSim = popSim / numOfChrom;
	similarity = popSim;
}

// void Population::findLocalSim()
// {
//     double percDiff, totalPercDiff;
//     for(int i = 0; i < numOfChrom-1; i++)
// 	{
// 		for(int j = i + 1; j < numOfChrom; j++)
// 		{
// 			percDiff = chromosome[i]. - chromosome[j].get_fitness();
//             percDiff = percDiff / chromosome[i].get_fitness();
//             totalPercDiff += percDiff;
// 		}
//         totalPercDiff = (totalPercDiff / (numOfChrom-i));
//         popSim += totalPercDiff;
// 	}
//     popSim = popSim / numOfChrom;
// 	similarity = popSim;
//
//
// }
