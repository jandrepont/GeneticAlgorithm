#include "Generation.cpp"

#ifndef GEN_ALG_H
#define GEN_AL_H

class GeneticAlgorithm{
    
    private:
        vector <Generation> generation;
        


    public:
        //creation of 1st generation's population chromosomes
        void inst_Solution(Generation generation);
        //conversion method from binary chrom to decimal
        void int binary2Decimal(struct Generation* generation, int start, int end, int row);
        //method to bound variable's particular to the 

































};
