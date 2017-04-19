#include "Population.h"






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

void cross1(std::vector<Population> &population, int popNum)
{
	int numOfChildren = population[0].get_cross() * population[0].get_numOfChrom();
		
	
	int start = population[0].get_elite() * population[0].get_numOfChrom(); 
	//population[0].get_elite() * population[0].get_numOfChrom();
	int previousPop = popNum - 1;
	//temp chrom acts as children
	std::vector<Chromosome> chrom;
	chrom.push_back(Chromosome(10));
	chrom.push_back(Chromosome(10));

	 	
	for(int child = 0; child < numOfChildren; child+=2)
	{
		int geneStart = rand() % population[0].get_sizeOfChrom();

		int negGeneStart = geneStart - 1;
		int randPar1 = rouletteWheel(population, previousPop);
		int randPar2 = rouletteWheel(population, previousPop);
		if(randPar1 == randPar2)
		{
			randPar2 = rouletteWheel(population, previousPop);

		}	
		
		for(int geneCount = 0; geneCount < population[0].get_sizeOfChrom()  ; geneCount++)
		{
			
			if(negGeneStart > 0) //so we dont go out of bounds of the array. 
			{
				
				chrom[0].set_gene(negGeneStart, population[previousPop].get_gene(randPar2, negGeneStart)); 
				chrom[1].set_gene(negGeneStart, population[previousPop].get_gene(randPar1, negGeneStart));
				negGeneStart--;
			}
			
			if(geneStart < population[0].get_sizeOfChrom()){

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




/*
void cross2(vector<Population> &population, int popNum){
    vector <Chromosome> temp;
	temp.push_back(Chromosome(160,10));
	temp.push_back(Chromosome(160,10));
    int prevPop = popNum - 1;
	int start  = population[0].get_elite() * population[0].get_numOfChrom();
	int end = population[0].get_cross() * population[0].get_numOfChrom();
	end = start + end;
	for(start; start < end; start  = start + 2){
        
        int randomPar1 = rouletteWheel(population, prevPop);
        int randomPar2 = rouletteWheel(population, prevPop);
        
		while(randomPar1 == randomPar2)
		{
			randomPar2 = rouletteWheel(population, prevPop);

		}	
        
        //Random 2 point crossover
        
        int rand1 = random() % population[0].get_sizeOfGenes();
        int rand2 = random() % population[0].get_sizeOfGenes();
        int point1, point2;
        
        if(rand1 >= rand2){
            point2 = rand1;
            point1 = rand2;
        }
        else if(rand1 <= rand2){
            point1 = rand1;
            point2 = rand2;
        }
*/        
		/*
        //Two Point Crossover
        int midPoint = population[0].get_sizeOfGenes() / 2;
        int point1 = midPoint / 2;
        int point2 = midPoint + point1;
        */
		//go from o to point1 for both children
        //offspring1 gets parent2 middle and parent1 exterior
        //offspring2 gets parent1 middle and parent2 exterior
        
/*
        for(int gene = 0; start < point1; start++){
        
            temp[0].set_gene( gene, population[prevPop].get_gene(randomPar1, gene));
			temp[1].set_gene( gene, population[prevPop].get_gene(randomPar2, gene));
		}
        
		for(int gene = point2; gene < population[0].get_sizeOfGenes(); gene++){
            
			//Parents switch 
            temp[0].set_gene( gene, population[prevPop].get_gene(randomPar2, gene)); 
			temp[1].set_gene( gene, population[prevPop].get_gene(randomPar1, gene));
		}
        
		population[popNum].set_chrom(start, temp[0]);
		population[popNum].set_chrom((start + 1), temp[1]);
	}
} 
*/

/*
void altCross(vector<Population> &population, int popNum){
	vector<Chromosome> temp;
	temp.push_back(Chromosome(160,10));
	temp.push_back(Chromosome(160,10));

    int start = population[0].get_elite() * population[0].get_numOfChrom();
    int end = start + (population[0].get_cross() * population[0].get_numOfChrom());
	int prevPop = popNum - 1;
        
    for(start; start < end ; start  = start + 2){

        int randomPar1 = rouletteWheel(population, prevPop);
        int randomPar2 = rouletteWheel(population, prevPop);
        //alternating crossover
        
        for(int gene = 0; gene < population[0].get_sizeOfGenes(); gene++){
            if(gene % 2 == 0){
             
                //temp.population[0].chromosome[n] = generation[generationNumber].population[randomPar1].chromosome[n];
				temp[0].set_gene( gene, population[prevPop].get_gene(randomPar1, gene));
				//temp.population[1].chromosome[n] = generation[generationNumber].population[randomPar2].chromosome[n];
				temp[1].set_gene(gene, population[prevPop].get_gene(randomPar2, gene));
			}
            if(gene % 2 == 1){

                //notice how the parents are swithed
				temp[0].set_gene(gene, population[prevPop].get_gene(randomPar2, gene));			
				temp[1].set_gene(gene, population[prevPop].get_gene(randomPar1, gene));
			}       
        }
		population[popNum].set_chrom(start, temp[0]);
		population[popNum].set_chrom((start + 1), temp[1]);
	}
} 
*/


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
	
	
	std::cout << "population[0] = " <<  population[0].get_fitness(0) << "\n";
	std::cout << "Similarity[0] = " << population[0].get_similarity() << "\n";	
	
	
	int populationNumber = 1;
	int previousPopulation = 0;
	
	int dummy = 0;

	for(int i = 0; i < 1000; i++)
	{
		
		population.push_back(Population(200, 10));
		population[0].set_elite(0.05);
		population[0].set_cross(0.8);
		preserveElites(population, 0); //0
		cross1(population, 1);
		population[1].mutate(10);
		population[1].sort();
		//population[1].findSim();		
			
		std::cout << "population " << i << " = " <<  population[1].get_fitness(0) << "\n";
		//cout << "Similarity " << i << " = " << population[1].get_similarity() << "\n";	
		
		
		population.erase(population.begin());
		
	
	}
	




}
