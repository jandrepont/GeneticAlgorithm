#include "Population.h"






void preserveElites(vector<Population> &population, int previousPop)
{
	int numberOfElites = population[0].get_elite() * population[0].get_numOfChrom();
	int i = 0;
	
	for(int n = 0; n < numberOfElites; n++)
	{
		//cout << "\n pop[1] = " << population[1].get_fitness(n) << ", pop[0] = " << population[0].get_fitness(n) << "\n";

		population[previousPop + 1].set_chrom(n, population[previousPop].get_chrom(n)); 
		//cout << "\n After pop[1] = " << population[1].get_fitness(n) <<  ", pop[0] = " << population[0].get_fitness(n) << "\n";
		i++;
	}
}

int rouletteWheel(vector<Population> population, int prevPop)
{
	int maxFitness = 0;
	int selection = 0;
	
	for(int i = 0; i < population[0].get_numOfChrom(); i++) //since #ofChrom are same for all
	{
		maxFitness += population[prevPop].get_fitness(i);
	}

	float random = rand() % maxFitness;
	int i = 0;
	while(random > 0)
	{
		int current = population[prevPop].get_fitness(i);
		random = random - current;
		i++;
	}
	maxFitness = 0;
	if(i == 200){
		i--;
	}
	return i;
}

void cross1(vector<Population> &population, int popNum)
{
	int numOfChildren = 160;
		//population[0].get_cross() * population[0].get_numOfChrom();
		
	
	int start = 20; 
	//population[0].get_elite() * population[0].get_numOfChrom();
	int previousPop = popNum - 1;
	vector<Chromosome> chrom;
	chrom.push_back(Chromosome(160,10));
	chrom.push_back(Chromosome(160,10));

	 	
	for(int child = 0; child < numOfChildren; child+=2)
	{
		int geneStart = rand() % 160;
			//population[0].get_sizeOfGenes();
		int negGeneStart = geneStart - 1;
		int randPar1 = rouletteWheel(population, previousPop);
		int randPar2 = rouletteWheel(population, previousPop);
		if(randPar1 == randPar2)
		{
			randPar2 = rouletteWheel(population, previousPop);

		}	
		
		for(int geneCount = 0; geneCount < 160 /* population[0].get_sizeOfGenes()*/  ; geneCount++)
		{
			
			if(negGeneStart > 0) //so we dont go out of bounds of the array. 
			{
				
				chrom[0].set_gene(negGeneStart, population[previousPop].get_gene(randPar2, negGeneStart)); 
				chrom[1].set_gene(negGeneStart, population[previousPop].get_gene(randPar1, negGeneStart));
				negGeneStart--;
			}
			if(geneStart < 160 /*population[0].get_sizeOfGenes() */){

				chrom[0].set_gene(geneStart, population[previousPop].get_gene(randPar1, geneStart));
																	//notice hows geneStart and negGeneStart swap
				chrom[1].set_gene(geneStart, population[previousPop].get_gene(randPar2, geneStart));
				geneStart++;
			}
		}
		population[popNum].set_chrom(start, chrom[0]);
		population[popNum].set_chrom((start + 1), chrom[1]);
		start += 2; 
		
	}
}


int main(){
	
	srand(time(NULL));

	//vector<Population> *population = new vector<Population>;
	//std::vector<Population> population(50, Population(200, 160, 10));
	std::vector<Population> population;
	population.reserve(1000);
	population.push_back(Population(200,160,10));
	population[0].set_elite(0.05);
	population[0].set_cross(0.8);


	int populationNumber = 1;
	int previousPopulation = 0;
	
	int dummy = 0;

	for(int i = 0; i < 1000; i++)
	{
		
		if(dummy > 0)
		{
			population.erase(population.begin());
		}

		population.push_back(Population(200, 160, 10));

		cout << "population " << i << " = " <<  population[previousPopulation].get_fitness(0) << "\n";
		
		preserveElites(population, previousPopulation);
		
		cross1(population, populationNumber);
		
		population[populationNumber].mutate(10);
		
		population[populationNumber].sort();
		
		dummy++;
	}
	




}
