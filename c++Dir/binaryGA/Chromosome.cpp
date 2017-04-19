#include "Chromosome.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <math.h> 

/*
 * Default Constructor
 */
Chromosome::Chromosome()
{
	this->size = 160;
	this->numOfVars = 10;
	vector<int> variable(10, int());
	vector<int> gene(160, int());
	
	for(int i = 0; i < size; i++){
		gene[i] =  rand() % 2;
	}
	set_vars(false);
	set_boundedVariable();
	set_fitness();
}

/*
 * Constructor that sets size of array of genes
 */
Chromosome::Chromosome(int _size, int _numOfVars)
{
	this->size = _size;
	this->numOfVars = _numOfVars;
	
	//vector<int> variable(numOfVars, int(0));
	//vector<int> gene(size, int(0));
	

	for(int i = 0; i < size; i++){
		this->gene.push_back( rand() % 2);
	}
	set_vars(false);
	set_boundedVariable();
	set_fitness();
}

/*
Chromosome::~Chromosome() 
{
	fitness = 0;
}
*/


/*
 *bool comparison for sorting
 */ 
bool Chromosome::operator<(const Chromosome rhs)
{
	return fitness < rhs.fitness;
}

/*
 *Getter and setter for genes
 */
void Chromosome::set_gene(int index, int value)
{
	this->gene[index] = value;
}

int Chromosome::get_gene(int index)
{
	return gene[index];
}
/*
 * Getter for size
 */
int Chromosome::get_size()
{
	return size;
}

/*
 * Getter and setter for whole array of genes 
 */
void Chromosome::set_chrom(vector<int> chrom)
{
	this->gene = chrom;	
}

vector<int>  Chromosome::get_chrom()
{
	return gene;
}

/*
 * Setter and getter for decVal 
 * **(setter only called implicitly)**
 */
void Chromosome::set_vars(bool mutate)
{
	
	//this will act as a sum of value where all binary
	//vals are added together
	int varValue = 0;
	
	//this acts as the sum value for a particular bit value
	int bitValue = 0;
	
	//length acts as the length of each variable, s.t. if
	//length = 10 then each variable is 10 bits added together
	int length = this->size / this->numOfVars;
	
	//This is the index for the vector<int> variable
	//where the variable values are stored
	int varIndex = 0;
	for(int start = 0; start < this->size; start++)
	{
		//bit is value at each index of vector<int> gene
		int bit = this->gene[start];
	
		//relStart is the relative value of each bit for each variable s.t. if a variable is 
		//length = 10 then the highest bit value can only be 2^9
		int relStart = start % length;

		if(bit == 1)
		{
			//base case for relStart = 0, i.e. 2^0=1
			if(relStart == 0)
			{
				varValue ++; //2^0 = 1
			}
			//for 2^n where n != 0;
			if(relStart != 0)
			{
				//loop that adds values of bits together
				for(int x = 0; x <= relStart; x++)
				{
					if(x == 0)
					{
						bitValue++;
					}
					if(x != 0)
					{
						bitValue = 2*bitValue;
					}
				}
			varValue += bitValue;
			bitValue = 0;
			}
		}
		//if called by mutate == false;
		if(length -1 == relStart && mutate == false)
		{
			//this is where the varValue is stored, then set to 0
			//and increment varIndex
			this->variable.push_back(varValue);
			varValue = 0;
			varIndex++;
		}
		//if called by mutate == true
		if(length -1 == relStart && mutate == true)
		{
			//this is where the varValue is stored, then set to 0
			//and increment varIndex
			this->variable[varIndex] = varValue;
			varValue = 0;
			varIndex++;
		}
	}
}

int Chromosome::get_var(int index)
{
	return variable[index];
}

/*
 * Getters and setters for numOfVars
 */
void Chromosome::set_numOfVars(int _numOfVars)
{
	this->numOfVars = _numOfVars;
}

int Chromosome::get_numOfVars()
{
	return numOfVars;
}
/*
 * Getters and setter for boundedVariable, calls functions from function.h
 */
void Chromosome::set_boundedVariable()
{
	function funct;
	this->boundedVariable = funct.function1Bounds(variable, numOfVars);
}
double Chromosome::get_boundedVariable(int index)
{
	return boundedVariable[index];
}

/*
 * Getter and setter for fitness values, calls function from function.h
 */
void Chromosome::set_fitness()
{
	function funct;
	this->fitness = funct.function1Fitness(boundedVariable, numOfVars);
}
double Chromosome::get_fitness()
{
	return fitness;
}

//set fitness
void Chromosome::set_fit(int fit){
	this->fitness = fit;
}

/*
 * mutate method that is called by Population, changes the bit value of a random gene
 * after doing this the variables are calculated again as is the fitness value
 */
void Chromosome::mutate_gene(int index)
{
	int originalVal = this->gene[index];
	originalVal++;
	int mutatedVal = originalVal % 2;
	this->gene[index] = mutatedVal;	
	set_vars(true);
	set_boundedVariable();
	set_fitness();
}



















