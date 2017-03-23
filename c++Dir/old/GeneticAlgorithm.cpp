#include <iostream> 
#include <cmath>
#include <vector>

using namespace std;

#ifndef GEN_ALG
#define GEN_ALG

class GeneticAlgorithm
{
    
    
    private:
            
        //variables for the Genetic Algorithm
        static int populationSize, chromosomeLength, variables, maxGenerations, arrayLength;
        static double eliteRate, crossRate, mutation;
        
 
    
    
    public:
        
        struct Population{
            vector<int> chromosome[160];
            double fitnessScore;
        };

        //Default Constructor 
        struct Generation{
            vector<Population> population[200];
        };
        
        //method for asking user for variable values
        double input_values(char* string);
        

        //method for creating first population w/ random bits
        void inst_Solution(int popLength, int soluLength, struct Generation generation[], 
                int generationNumber);
        
        //gets the decimal value of each chrom of a population
        int binary2Decimal(int populationSize, int chromosomeLength, 
                struct Generation* generation, int start, int end, 
                int row, int generationNumber);
        
        //bounds the variables 
        double boundVariable(int unboundedVariableValue);
        
        //plugs bounded variables into the function
        double functionCall(int populationSize, int arrayLength, 
                vector<float>* boundedVariableValues, int row);
        
        //sorts each pop according to fitness scores
        void sort(Generation* generation, int generationNumber, int populationSize);
        
        //preserve a % of the elites for the next generation
        void preserveElites(Generation* generation, int generationNumber, int popLength);
        
        //roulette Wheel selection for cross/baby making
        int rouletteWheel(Generation* generation, int previousGeneration, int popLength);
        
        //cross method based on selecting one random point to cross chromosomes
        void cross1(Generation* generation, int generationNumber, int chromLength, int
                popLength, int mutationRate, int eliteRate, int crossRate);
        
        //cross method based on selecting two points such that a middle section is 
        //created, this middle is switched between the two parents to make 2 children
        void cross2(Generation* generation, int generationNumber, int chromLength, 
                int popLength, int mutationRate, int eliteRate, int crossRate);
        
        //every other point is switched from the parents to create the children
        void alternatingCross(Generation* generation, int generationNumber, int chromLength, 
               int popLength, int mutationRate, int eliteRate, int crossRate);

        void fillPop(Generation* generation, int generationNumber, int chromLength, 
                int popLength, float mutation, float eliteRate, int crossRate);
        
        void mutate(Generation* generation, int generationNumber, int chromLength, 
                int popLength, float mutation, float eliteRate);          
};
#endif 
