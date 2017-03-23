
#include "Population.h" 

int main(){


	//Population population;
	Population population(200, 160, 10); 
	
	for(int i = 0; i < 10; i++){
		std::cout << population.get_fitness(i) << "Chrom # : " << i <<  "\n" ;
	}

	population.mutate(10);
	//population.sort();	
	std::cout << "\n \n \n \n ";
	for(int i = 0; i < 10; i++){
		std::cout << population.get_fitness(i) << "Chrom # : " <<  i << "\n" ;
	}


}
