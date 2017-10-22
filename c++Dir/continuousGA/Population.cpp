#include "Population.h"
#include "algorithm"

/*
 * Default Constructor
 */

Population::Population()
{
	//std::vector<Chromosome> chromosome;

	this->globalAverage = 0;
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

	numOfChrom = _numOfChrom;

	sizeOfChrom = _sizeOfChrom;

	globalAverage = 0;

	popNum = 0;

	elite = .05;

	cross = .8;

	for(int i = 0; i < numOfChrom; i++)
	{
		Chromosome chrom(sizeOfChrom);
		chromosome.push_back(chrom);
	}
	sort(0,200);

}


/*
 * Getter and setter for locSim vector in chromosome
 */
void Population::set_locSim(int chromIndex, int geneIndex, double similarity)
{
    chromosome[chromIndex].set_locSim(geneIndex, similarity);
}
double Population::get_locSim(int chromIndex, int geneIndex)
{
    chromosome[chromIndex].get_locSim(geneIndex);
}

/*
 * Getter for totalSim of a chromosomme
 */
double Population::get_totSim(int index)
{
    return chromosome[index].get_totSim();
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
	numOfChrom = _num;
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
	sizeOfChrom = _size;
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
	popNum = _num;
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
	elite = rate;
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
	cross = rate;
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
		chromosome[chromNum].set_gene(index, value);
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
	chromosome[chromNum] = chrom;
	//need to recompute the chrom values
	chromosome[chromNum].set_fitness();

}
Chromosome Population::get_chrom(int chromNum)
{
	return chromosome[chromNum];
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
 * Returns the global average of similarity accross the entire population
 * Is a broad indication of similarity and may be too broad
 */
 double Population::get_globalAverage()
 {
     return globalAverage;
 }

/*
 * Mutate, for a specified of chromosomes, switches a random bit value in the gene of
 * random chromosomes
 */

void Population::mutate(int mutateRate)
{
	//int n = 0;
	//std::cout << "mutateRate = " << mutateRate;
	for(int i = 0; i < mutateRate; i++)
	{
		//std::cout << " n is equal to " << n;
		int randChrom = rand() % numOfChrom;
		while(randChrom < 10)
		{
			randChrom += rand() % 10;
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
void Population::findTotalSim(double epsilon)
{
    double relativeDiff, similarity, x;
    //compare chromosome[i] and chromosome[j]
    //numOfChrom -1 b/c no need to compare chromosome[i] with chromosome[j] when i == j
	for(int i = 0; i < numOfChrom-1; i++)
	{
		for(int j = i + 1; j < numOfChrom; j++)
		{
            //chrom.get_input gets the total input of the chromosome
            //get the absolute difference
            x = chromosome[i].get_input();
			relativeDiff = abs(x - chromosome[j].get_input());
            //get the relative difference
            relativeDiff = (relativeDiff / abs(x));
            //similarity condition
            if(relativeDiff <= epsilon)
            {
                similarity++;
            }
		}
        //get similarity percentage
        similarity = (similarity / (numOfChrom-i));

        //add to global average of all sim values
        globalAverage += similarity;

        //set val for chrom[i]
        chromosome[i].set_totSim(similarity);
        similarity = 0;
	}
    globalAverage = globalAverage / numOfChrom;

}

void Population::findLocalSim(double epsilon)
{
    double relativeDiff = 0;
    double similarity = 0;


    // //chrom[i][0]
    for(int i = 0; i < numOfChrom-1; i++)
	{
        //chrom[i][k]
        for(int j = 0; j < sizeOfChrom; j++)
        {

    		for(int k = i + 1; k < numOfChrom; k++)
    		{

                //Difference = chrom[i][k]
    			relativeDiff = chromosome[i].get_gene(j) - chromosome[k].get_gene(j);
                // relative difference / chrom[i][j]
                relativeDiff = (abs(relativeDiff) / abs(chromosome[i].get_gene(j)));
                //if percDiff meets similarity criteria, add to similarity total
                if(relativeDiff <= epsilon)
                {
                    similarity++;
                }
		    }
            // get perc of similarity conditions
            similarity = (similarity / (numOfChrom-i));

            chromosome[i].set_locSim(j, similarity);
            similarity = 0;
       }
    }
}
