//Chromsome data structure used in populations
#include "function.h"
#include <cmath>
#include <time.h>




#ifndef CHROM_H
#define CHROM_H

class Chromosome{

    public:
		// default constructor
		Chromosome();
        Chromosome(int size);
		//destructor
		//~Chromosome();

		//Comparison function for comparing fitness and sorting chromosomes
		bool operator<(const Chromosome rhs);

		//Getters and Setters
		void set_gene(int index, double value);
		double get_gene(int index);

		int get_size();

		//Getters and Setters for entirety of vector<int> gene
		void set_chrom(std::vector<double> _gene);
		std::vector<double> get_chrom();

		//getter and setter for fitness
		//uses function.h to get values
		void set_fitness();
		double get_fitness();

        //getter and setter for gene fitness
        //uses function.h to get values
        double get_gene_fitness(int index);

		//set fitness
		void set_fit(int fit);

        //getter and setter for localSim, stores similarity
        //of a gene to other genes
        void set_locSim(int index, double similarity);
        double get_locSim(int index);

        //getter and setter for totalSim, stores similarity of a chromosome's
        //total input relative to all other chrom in a population
        void set_totSim(double similarity);
        double get_totSim();


        //get_input gets sum of input for chromosome
        double get_input();

		//Mutate method that is called by population
		void mutate_gene(int index);




	private:

		std::vector<double> gene;
        std::vector<double> localSim;
		int size;
		double fitness;
        double totalSim;
        double globalAverage;

};

#endif
