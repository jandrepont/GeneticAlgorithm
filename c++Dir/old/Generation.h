//This class defines all the variables for each generation

#include "Population.h" 
#include <string>  
#ifndef GENERATION_H
#define GENERATION_H
                   
class Generation : public Population
{
    private:
        static int chromLength; 
        //static double fitness; 
        static int populationSize;
        static int variables;
        static int generations;
        static float eliteRate;
        static float crossRate;
        static float mutationRate;
        static double totalSimilarity;        
        static vector<Population> population();

    public:
    //default constructor
    Generation();

    //method for asking user for variable values 
    double input_valuesF(const string&  varName);
	int input_valuesI(const string& varName);
	
	//set_variables uses input_values to set all user defined variables in class Generation	
	void set_variables();

	//Mutator and Accessor for chromLength
    void set_chromLength(int _chromLength);
	int get_chromLength();

    //Mutator and Accessor for populationSize
	void set_populationSize(int _popSize);
	int get_populationSize();

	//Mutator and Accessor for variables
    void set_variables(int _variables);
	int get_variables();

	//Mutator and Accessor for # of generations
    void set_generations(int _generations);
	int get_generations();

	//Mutator and Accessor for eliteRate
    void set_eliteRate(float _eliteRate);
	double get_eliteRate();

	//Mutator and Accessor for crossRate
    void set_crossRate(float _crossRate);
	double get_crossRate();

	//Mutator and Accessor for mutationRate
    void set_mutationRate(float _mutation);
	double get_mutationRate();

	//Mutator and Accessor for totalSimilarity amongst a generation
    void set_totalSimilarity(double _totalSimilarity);
	double get_totalSimilarity();

	//inst_Solution fills the chromosomes in the populations for 1st generation
	void inst_Solution(Generation _generation[], int generationNumber);






};

#endif 
