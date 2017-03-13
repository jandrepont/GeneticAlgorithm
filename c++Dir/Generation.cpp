#include "Generation.h" 
#include <stdio.h>
#include <ctime> 
#include <time.h> 
#include <stdlib.h>
/*
 * Default constructor
 *
 */
Generation::Generation(){
	chromLength;
    populationSize;
    variables;
    generations;
    eliteRate;
    crossRate;
    mutationRate;
    totalSimilarity;
    population;
}
/*
 *
 * input_value asks user input to define all of the type double variable values in
 * Generation
 *
 */

double Generation::input_valuesF(const string& varName){ //returns a float values
     
        float value = 0;
        cout << "\n Enter a value for" <<  varName;
        cin >> value;
        cout << "You entered: " << value << " for " <<  varName << ".\n";
        return value;
}//end function input_value

/*
 *
 * input_value asks user input to define all of the type int variable values in
 * Generation
 *
 */

int Generation::input_valuesI(const string& varName){ //returns a int values

        int value = 0;
        cout << "\n Enter a value for" <<  varName;
        cin >> value;
        cout << "You entered: " << value << " for " <<  varName << ".\n";
        return value;
}//end function input_value
/*
 * set_variables called to instantiate variables used in building the Generation
 * dataStruct, note that totalSimilarity and population[] are not modified here
 *
 */

void Generation::set_variables(){
	this->chromLength = input_valuesI("Chromosome Length");
	this->populationSize = input_valuesI("Population Size");
	this->variables = input_valuesI("Number of Variables");
	this->generations = input_valuesI("Number of Generations");
	this->eliteRate = input_valuesF("Elite Rate");
	this->crossRate = input_valuesF("Cross Rate");
	this->mutationRate = input_valuesF("Mutation Rate");
}

/*
 * Mutator & Accessor for chromLength
 */
void Generation::set_chromLength(int _chromLength){
	this->chromLength = _chromLength;
}

int Generation::get_chromLength(){
	return chromLength;
}

/*
 * Mutator & Accessor for populationSize
 */ 
void Generation::set_populationSize(int _popSize){
	this->populationSize = _popSize;
}
int Generation::get_populationSize(){
	return populationSize;
}

/*
 * Mutator and Accessor for variables
 */
void Generation::set_variables(int _variables){
	this->variables = _variables;
}
int Generation::get_variables(){
	return variables;
}

/*
 * Mutator & Accessor for generations
 */
void Generation::set_generations(int _generations){
	this->generations = _generations;
}
int Generation::get_generations(){
	return generations;
}

/*
 * Mutator & Accessor for eliteRate
 */
void Generation::set_eliteRate(float _eliteRate){
	this->eliteRate = _eliteRate;
}
double Generation::get_eliteRate(){
	return eliteRate;
}

/*
 * Mutator & Accessor for crossRate
 */
void Generation::set_crossRate(float _crossRate){
	this->crossRate = _crossRate;
}
double Generation::get_crossRate(){
	return crossRate;
}

/*
 * Mutator & Accessor for mutationRate
 */
void Generation::set_mutationRate(float _mutationRate){
	this->mutationRate = _mutationRate;
}
double Generation::get_mutationRate(){
	return mutationRate;
}

/*
 * Mutator & Accessor for totalSimilarity 
 */
void Generation::set_totalSimilarity(double _totalSimilarity){
	this->totalSimilarity = _totalSimilarity;
}
double Generation::get_totalSimilarity(){
	return totalSimilarity;
}



/*
*
* takes an array and fills each index with random 0 or 1 
* @param pointer to empty arrray
* @ret array with each index filled
*
*/

void Generation::inst_Solution(Generation _generation[], int generationNumber){
	srand (time(0));
	//first we declare a vector tempChrom
	vector<int> tempChrom;
	//loop through = to # of population
	for(int i = 0; i < _generation->get_populationSize(); i++){
		//create random 1s & 0s for length = to chromLength
		for(int j = 0; j < _generation->get_chromLength(); j++){ 
			tempChrom[j] = rand() % 2;
		}
		//set chrom for pop[i] using set_chromosome which takes a vector
		_generation[generationNumber].population[i].set_chromosome(tempChrom);
	}	    
}

