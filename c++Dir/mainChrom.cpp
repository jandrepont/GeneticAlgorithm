#include "Chromosome.h"

int main(){
	srand(time(NULL));

	std::vector<Chromosome>  chromosome(2, Chromosome(160, 10));
	/*
	for(int i = 0; i < chromosome.get_size(); i++){
		cout << "Contents of Chromosome: " << chromosome.get_gene(i) << "at " << i << "\n"; 
	}
	for(int i = 0; i < 10; i++){
		cout << "Variable Value of Chromosome: " << chromosome.get_var(i) << " \n";
		cout << "Unbounded Variable Value: " << chromosome.get_boundedVariable(i) << "\n";
	}
	cout<< "Fitness = " << chromosome.get_fitness() << "\n";
	
	int randGene = rand() % 160;
	cout << "\n AHHHHHHHHHHHHHHHH" << randGene << "\n"; 
	chromosome.mutate_gene(randGene);
	
	for(int i = 0; i < chromosome.get_size(); i++){
		cout << "Contents of Chromosome: " << chromosome.get_gene(i) << "at " << i << "\n"; 
	}
	for(int i = 0; i < 10; i++){
		cout << "Variable Value of Chromosome: " << chromosome.get_var(i) << " \n";
		cout << "Unbounded Variable Value: " << chromosome.get_boundedVariable(i) << "\n";
	}
	cout<< "Fitness = " << chromosome.get_fitness();
	*/
	
	
return 0;
}
