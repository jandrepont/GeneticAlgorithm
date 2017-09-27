#include "Population.h"
#include <random> 






void preserveElites(std::vector<Population> &population, int previousPop)
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

int rouletteWheel(std::vector<Population> population, int prevPop)
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


void comboCross1(std::vector<Population> &population, int popNum)
{
	
	
	
	//Type of random number distribution
	std::uniform_real_distribution<double> dist(0,1);  //(min, max)
				   
	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng;
				  
	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}());
	
	
	int crossPoint = (rand() % 8) + 1; //population[0].get_sizeOfChrom();

	//int negGeneStart = geneStart - 1;
	
	int start = (population[0].get_elite() * population[0].get_numOfChrom());
	double val1, val2 , par1, par2,  weight;
	int previousPop = 0;
	int randPar1, randPar2;
	int numOfChildren = population[0].get_cross() * population[0].get_numOfChrom();
			
	for(int child = 0; child < numOfChildren; child+=2 )
	{
		
		randPar1 = rouletteWheel(population, previousPop);
		randPar2 = rouletteWheel(population, previousPop);
		
		while(randPar1 == randPar2)
		{
			randPar2 = rouletteWheel(population, previousPop);

		}	
			
		weight = dist(rng);
		
		for(int geneCount = 0; geneCount < 10; geneCount++)
		{
			if(geneCount < crossPoint)
			{
			    //need to first get genes
                par1 = population[previousPop].get_gene(randPar1, geneCount);
                par2 = population[previousPop].get_gene(randPar2, geneCount);

                //place them in new children
                population[popNum].set_gene(start, geneCount, par1); //child1
                population[popNum].set_gene(start+1, geneCount, par2); //child2
            }
			
			if(geneCount > crossPoint)
			{
			    //need to first get genes
                par1 = population[previousPop].get_gene(randPar1, geneCount);
                par2 = population[previousPop].get_gene(randPar2, geneCount);

                //place them in new children, notice that these are swapped compared to the above block
                population[popNum].set_gene(start, geneCount, par2); //child1
                population[popNum].set_gene(start+1, geneCount, par1); //child2
			}
            
            if(geneCount == crossPoint){
                                
                //gets us the gene of the crossPoint from Mom
                par1 = population[previousPop].get_gene(randPar1, crossPoint);
                //gets us the gene of the crossPoint from father	
                par2 = population[previousPop].get_gene(randPar2, crossPoint);
                val1 = (weight*par1) + ((1 - weight)*par2);
                val2 = ((1-weight)*par1) + (weight*par2);
                
                population[popNum].set_gene(start, crossPoint, val1);  //child1
                population[popNum].set_gene(start+1, crossPoint, val2);  //child2	
            } 
			
		}
		start+=2;
	}
}

int main(){
	
	srand(time(NULL));

	//vector<Population> *population = new vector<Population>;
	//std::vector<Population> population(50, Population(200, 160, 10));
	std::vector<Population> population;
	population.reserve(1000);
	population.push_back(Population(200,10));
	population[0].set_elite(0.05);
	population[0].set_cross(0.8);
	//population[0].findSim();
	
	
	//std::cout << "population[0] = " <<  population[0].get_fitness(0) << "\n";
	//std::cout << "Similarity[0] = " << population[0].get_similarity() << "\n";	
	
	
	int populationNumber = 1;
	int previousPopulation = 0;
	
	int dummy = 0;

	for(int i = 0; i < 1000; i++)
	{
		
		population.push_back(Population(200, 10));
		population[0].set_elite(0.05);
		population[0].set_cross(0.8);
		preserveElites(population, 0); //0
		comboCross1(population, 1);
		population[1].mutate(10);
		population[1].sort(0,200);
		//population[1].findSim();		
		
		/*
		for(int j = 0; j < 200; j++){

			std::cout << "population " << i << " = " <<  population[1].get_fitness(j) << "\n";
		}
		*/
		std::cout << "population " << i << " = " << population[0].get_fitness(0) << "\n";	
		
		
		population.erase(population.begin());
		
	
	}
	




}
