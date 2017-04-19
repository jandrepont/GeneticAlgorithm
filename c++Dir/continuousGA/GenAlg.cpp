#include "GenAlg.h"

GenAlg::GenAlg()
{
	std::vector<Population> population(50, Population(200, 160, 10));
}

GenAlg::GenAlg(int numOfPops)
{
	std::vector<Population> population(numOfPops, Population(200, 160, 10));
}


int rouletteWheel(vector<Population> population)
{
	int previousPop = population.get_popNum();
	previousPop = previousPop - 1;
	int maxFitness = 0;
	int selection = 0;
	
	for(int i = 0; i < population.get_numOfChrom; i++)
	{
		maxFitness += population[previousPop].get_fitness();
	}

	float random = rand % maxFitness;
	int i = 0;
	while(random > 0)
	{
		int current = population[previousPop].get_fitness();
		random = random - current;
		i++;
	}

	return i;
}

void cross1(vector<Population> population, int crossRate)
{
	int numOfChildren = population.get_cross() * population.get_numOfChrom;
	int start = eliteRate * popLength;
	int previousPop = population.get_popNum() - 1;

	for(int child = 0; child < numOfChildren; child++)
	{
		int geneStart = rand() % population.get_sizeOfGenes();
		int negGeneStart = geneStart;
		int randPar1 = rouletteWheel(population, previousPop);
		int randPar2 = rouletteWheel(population, previousPop);
		if(randPar1 == randPar2)
		{
			randPar2++;
		}
		for(; geneStart < population.get_sizeOfGenes(); geneStart++)
		{
			
			chrom.set_gene(population[previousPop].chromosome[randPar1].get_gene(geneStart));
			chrom.set_gene(population[previousPop].chromosome[randPar2].get_gene(negGeneStart));

			chrom.set_gene(population[previousPop].chromosome[randPar1].get_gene(negGeneStart));
			chrom.set_gene(population[previousPop].chromosome[randPar2].get_gene(geneStart));
			
			negGeneStart--;
		}
}

int main(){
	
	srand(time(NULL));

	std::vector<Population> population(50, Population(200, 160, 10));
	
	
	
	for(int i = 0; i < 50; i++)
	{
		
		Population pop(200, 160, 10);
		population.set_popNum(i);
		population.set_cross(.8);
		population.set_elite(.05);
		population.push_back(pop);

	}

	for(int i = 0; i < 50; i++)
	{
		cout << population[i].get_fitness(0) << "\n"  ;
	}

}
