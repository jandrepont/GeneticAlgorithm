#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>

//char variable[100];
float input_value(char*);
char* variable[200];
//void inst_Solution(int, int, int*);
//int binary2Decimal(int*, int, int);
float boundVariable( int );
//int maxGenerations = 10;


/*
 *
 * organizes the data into a coherent data structure for each generation
 *
*/


typedef struct Population {
	int chromosome[160];
	double fitnessScore;
} Population;

typedef struct Generation {
	struct Population population[200];
} Generation;


/*
 * Asks user for values used for genetic algorithm
*/
float input_value(char* string){
	
	float value; 
	printf("\n Enter a value for %s: \n", string);
	scanf("%f", &value);
	printf("You entered: %f, for %s \n", value, string);
	return value;
}


/*
 *
 * takes an array and fills each index with random 0 or 1 
 * @param pointer to empty array
 * @ret array with each index filled
 *
*/

void inst_Solution(int popLength, int soluLength, struct Generation generation[], int generationNumber){

	srand ( time(NULL) );
	
	for(int i = 0; i < popLength; i++){
		
		for(int j = 0; j < soluLength; j++){

			generation[generationNumber].population[i].chromosome[j] = rand() % 2;	
		}
	}

}

/*
*
* split chromosome length based on number of variables
* and convert the binary value into decimal value
* need to pass in the array, fill in an array from 0 to 15 of the binary digits
* 
*/

int binary2Decimal(int popLength, int soluLength, struct Generation* generation,
	int start, int end, int row, int generationNumber){
	int variableValue = 0;  //this will act as a sum value where all the binary values will be added together
	int bitValue = 0;	//this acts as the sum value for a particular bit value
	int length = end - start;
		for( ; start < end; start++){
			int bit = generation[generationNumber].population[row].chromosome[start];
			//int bit = solution[row][start];
			int relativeStart = start % length;
			
			if(bit == 1){ //only do something if the binary value is 1, not 0
				if(relativeStart == 0){
					variableValue ++; //if the binary value is 1 and in the 0th position, add one to the variableValue
				}
				if(relativeStart != 0){
					if(bit == 1){
						for(int x = 0; x <= relativeStart; x++){
							if(x == 0){
								bitValue++;
							}
						
							if(x != 0){
						
								bitValue = 2*bitValue;
							}
						}
					}
				variableValue += bitValue;
				bitValue = 0;	 
				}
			}	
		}
		return variableValue;
}



//Method for bounding a variable value.
float boundVariable( int unboundedVariableValue ){
	float boundedVariable;
	float floatUnboundedVariableValue = (float)unboundedVariableValue;
	boundedVariable = (floatUnboundedVariableValue - 32768) / 32;

	return boundedVariable;
}


//function is defined as
// f = 1 + Sum(1,10) of (x^2)/4000 - Product(1,10) cos(x/sqrt(i))
//I have an array of all of the bounded variable values. 
double functionCall(int popLength, int arrayLength, float boundedVariableValues[popLength][arrayLength], int row){

	double totalSum = 0; 
	double sum = 0; 
	double product = 1;
	for(int column = 0; column < arrayLength; column++){
		float variable = boundedVariableValues[row][column];
		double dVariable = (double)variable;
		sum += (dVariable*dVariable)/4000; 
		double cosValue = (cos(dVariable));
		//printf("value for cosValue is %f \n", cosValue);
		double tempVal = (cosValue/(sqrt(column + 1)));
		//printf("tempVal = %f", tempVal);
		product = product * tempVal;
		//printf("Value for product = %f & Value for sum = %f for row[%d] column [%d] \n", product, sum, row, column);
	}
	totalSum = 1 + (sum - product);

	return totalSum;

}


void sort(Generation* generation, int generationNumber, int popLength){		
	struct Population swap;
	for (int c = 0 ; c < ( popLength - 1 ); c++){
		for (int d = 0 ; d < popLength - c - 1; d++){

			if (generation[generationNumber].population[d].fitnessScore < generation[generationNumber].population[d+1].fitnessScore) {
				swap = generation[generationNumber].population[d];
				generation[generationNumber].population[d] = generation[generationNumber].population[d+1];
				generation[generationNumber].population[d+1] = swap;
			}
		}
	}
}

void preserveElites(Generation* generation, int generationNumber, int eliteRate){ 
	for(int n = 0; n < eliteRate; n++){
		generation[generationNumber].population[n] = generation[generationNumber - 1].population[n];
	}  
}

void preserveWorst(Generation* generation, int generationNumber, int popLength, int bottomRate){
	for(; bottomRate > 0; bottomRate --){
		int current = popLength - bottomRate;
		generation[generationNumber].population[current] = generation[generationNumber - 1].population[current];
	}
}

void mutation(Generation* generation, int generationNumber, int chromLength, 
				int popLength, int mutation, int eliteRate, int bottomRate){
	int modLength = popLength - (eliteRate + bottomRate);
	srand(time(NULL));
		
	/*Need 
	* To
	* Fix 
	* This
	* Soon
	*/
	
	int randomPop = rand() % modLength;
	int randomGene = rand() % chromLength;
	int bitValue = generation[generationNumber].population[randomPop].chromosome[randGene];
	bitValue += 1;
	bitValue = bitValue % 2;
	generation[generationNumber].population[randomPop].chromosome[randGene] = bitValue;	
}

void cross(Generation generaton, int generationNumber, int chromLength, int popLength, 
			int mutationRate, int eliteRate, int bottomRate){
	srand(time(NULL));
	for(n = 0; n < mutationRate; n++){
		int randomPop = rand() % modLength;
		int randomCross = rand() % 


	}
	//make it to where if x < bottomRate then x = x + bottomRate
	// & where if x > popLength - eliteRate then x = x - eliteRate




} 








int main(int argc, char* argv[0]){  //command line arguments
			
	int populationSize, chromosomeLength, variables, maxGenerations, eliteRate, crossOverRate, mutation, bottomRate;
	//Start and input values
	//setVariables();

	printf("\n Program name is : %s \n", argv[0]);
	
	/*
	 *ask user to enter in values for variables
	 *
	*/
	
	printf("All values must be entered as integer values. Where 5 percent is 5.");
	populationSize = input_value("population Size");
	chromosomeLength = input_value("Chromosome Length");
	variables = input_value("number of variables");
	maxGenerations = input_value("Maximum number of generations");
	eliteRate = input_value("percentage rate for preserving elites of last generation.");
	bottomRate = input_value("percentage rate for the bottom fitness solutions to be preserved for next generation");
	
	/*
	 * Instantiate array for solution representation and fill with random bit values, make a 2d array 
	*/
	int soluLength = chromosomeLength;	
	int popLength = populationSize;
	struct Generation generation[2];
	
	for(int generationNumber = 0; generationNumber < maxGenerations; generationNumber ++){	
		//instantiate
		if(generationNumber == 0){
			inst_Solution(popLength, soluLength, generation, generationNumber);
		}
	
		else{
			preserveElites(generation , generationNumber, eliteRate);
			preserveWorst(generation , generationNumber, popLength, bottomRate);
			mutation(generation, generationNumber, chromLength, popLength, mutation, eliteRate, bottomRate);
			cross(generaton, generationNumber, chromLength, popLength, mutation, eliteRate, bottomRate);	
		//cross();
		
	
				
		//get variable values
		int arrayLength = variables;		
		int unboundedVariableValues[popLength][arrayLength];
		int start = 0;
		int variableLength = chromosomeLength / variables;
		int end = start + variableLength;	
		for (int row = 0; row < popLength; row++){
			for(int n = 0; start < chromosomeLength; start = start + variableLength ){
				unboundedVariableValues[row][n] = binary2Decimal(popLength, soluLength, generation, start, end, row, generationNumber);
				n++;
				end = end + variableLength;
			}	
			start = 0;
			end = variableLength;	
		}
		float boundedVariableValues[popLength][arrayLength];
		for(int row = 0; row < popLength; row++){
			for(int column = 0; column < arrayLength; column++){
				int unboundedValue = unboundedVariableValues[row][column];
				boundedVariableValues[row][column] = boundVariable( unboundedValue );
			}
		}
		
		//Now need to test the bounded variables and get a fitness score for each one. 
		//double fitnessScores[popLength];
		for(int row = 0; row < popLength; row++){
			//int solution [popLength + 1] [soluLength];
			//fitnessScores[row] = functionCall(popLength, arrayLength, boundedVariableValues, row);
			generation[generationNumber].population[row].fitnessScore = functionCall(popLength, 
																		arrayLength, boundedVariableValues, row);
		}
		//sort the generation
		sort(generation, generationNumber, popLength);
		//populate the next generation
		

		
		for(int i = 0; i < popLength; i++){
			printf("Row [%d] has fitness score %f \n", i , generation[generationNumber].population[i].fitnessScore); 
		}
	}

	return 0;
}














