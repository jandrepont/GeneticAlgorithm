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
float input_value(char* variable){
	
	float value; 
	printf("\n Enter a value for %s: \n", variable);
	scanf("%f", &value);
	printf("You entered: %f, for %s \n", value, variable);
	return value;
}


/*
 *
 * takes an array and fills each index with random 0 or 1 
 * @param pointer to empty array
 * @ret array with each index filled
 *
*/

void inst_Solution(int popLength, int soluLength, int solution[popLength][soluLength]){

	srand ( time(NULL) );
	
	for(int i = 0; i < popLength; i++){
		
		for(int j = 0; j < soluLength; j++){

			solution[i][j] = rand() % 2;	
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

int binary2Decimal(int popLength, int soluLength, int solution[popLength][soluLength], int start, int end, int row){
	int variableValue = 0;  //this will act as a sum value where all the binary values will be added together
	int bitValue = 0;	//this acts as the sum value for a particular bit value
	int length = end - start;
	//int relativeStart = length % start;
	//for( int row = 0; row < popLength; row++){
		for( ; start < end; start++){
			int bit = solution[row][start];
			int relativeStart = start % length;
			//printf("relativeStart = %d \n", relativeStart);
			//printf("%d \n", variableValue);	
			if(bit == 1){ //only do something if the binary value is 1, not 0
				if(relativeStart == 0){
//					printf("printing value in if start == 0, before adding to, tha value is: %d \n", variableValue);
					variableValue ++; //if the binary value is 1 and in the 0th position, add one to the variableValue
//					printf("printing value in if start == 0, after adding to, tha value is: %d \n", variableValue);
				}
				if(relativeStart != 0){
					if(bit == 1){
						for(int x = 0; x <= relativeStart; x++){
							if(x == 0){
//								printf("printing value in if == 0, before adding to, the value is: %d \n", variableValue);
								bitValue++;
//								printf("printing value in if x == 0, after adding to, the value is: %d \n", variableValue);
							}
						
							if(x != 0){
						
//								printf("printing bitValue in if x != 0, before adding to, the value is: %d \n", bitValue);
								bitValue = 2*bitValue;
//								printf("printing bitValue in if x != 0, after adding to, the value is: %d \n", bitValue);
							}
						//variableValue += bitValue;
						}
						//variableValue += bitValue;
					}
				variableValue += bitValue;
				bitValue = 0;	 
				}
			//variableValue += bitValue;
			//bitValue = 0;
			}	
		}
		return variableValue;
	//}		
	//return variableValue;
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










int main(int argc, char* argv[0]){  //command line arguments
	
	float populationSize, chromosomeLength, variables, maxGenerations, eliteRate, crossOverRate, mutation, bottomRate;
	//Start and input values
	//setVariables();

	printf("\n Program name is : %s \n", argv[0]);
	
	/*
	 *ask user to enter in values for variables
	 *
	*/
	
	printf("All values must be entered as decimal values. Where 5 percent is 0.05.");
	populationSize = input_value("population Size");
	chromosomeLength = input_value("Chromosome Length");
	variables = input_value("number of variables");
	maxGenerations = input_value("Maximum number of generations");
	eliteRate = input_value("percentage rate for preserving elites of last generation.");
	bottomRate = input_value("percentage rate for the bottom fitness solutions to be preserved for next generation");
	
	/*
	 * Instantiate array for solution representation and fill with random bit values, make a 2d array 
	*/
	int soluLength = (int)chromosomeLength;	
	int popLength = (int)populationSize;
	int solution [popLength+1] [soluLength]; //popLength + 1 b/c will add fitness values later
	inst_Solution(popLength, soluLength, solution);
	
	for(int n = 0; n < popLength; n++){
		for(int k = 0; k < soluLength; k++){
		printf("For row %d the value is %d \n", n, solution[n][k]);
		}
	}	
	

	
	printf("variables = %f \n", variables);
	int arrayLength = (int)variables;		
	int unboundedVariableValues[popLength][arrayLength];
	//1st need to convert into decimal and store in an array
	//2nd bound the variables
	//3rd create an array of the variable values
	//1st
	//for chrom length 16, 2 variables
	int start = 0;
	int variableLength = chromosomeLength / variables;
	printf("variableLength = %d \n", variableLength);
	int end = start + variableLength;
	for (int row = 0; row < popLength; row++){
		for(int n = 0; start < chromosomeLength; start = start + variableLength ){
			unboundedVariableValues[row][n] = binary2Decimal(popLength, soluLength, solution, start, end, row);
			n++;
			end = end + variableLength;
		}	
		start = 0;
		end = variableLength;	
	}
	/*
	for(int i = 0; i < popLength; i++){
		for(int j = 0; j < variables; j++){
			printf("unboundedVariables Values for row %d = %d \n", i , unboundedVariableValues[i][j]);
		}
 	}
	*/
	//2nd & 3rd
	//Need to bound the variables
	//then create 2d array with all the variable values. 
	float boundedVariableValues[popLength][arrayLength];
	for(int row = 0; row < popLength; row++){
		for(int column = 0; column < arrayLength; column++){
			int unboundedValue = unboundedVariableValues[row][column];
			boundedVariableValues[row][column] = boundVariable( unboundedValue );
		}
	}
	
	/*
	 *Check to see if values are bounded
	for(int row = 0; row < popLength; row++){
		for(int column = 0; column < arrayLength; column++){
			printf("Bounded Variable for row %d = %f \n", row, boundedVariableValues[row][column]);
		}
	}
	*/

	//Now need to test the bounded variables and get a fitness score for each one. 
	double fitnessScores[popLength];
	for(int row = 0; row < popLength; row++){
		//int solution [popLength + 1] [soluLength];
		fitnessScores[row] = functionCall(popLength, arrayLength, boundedVariableValues, row);
	}
	/*
	double swap;
	double soluSwap[popLength];
	double generationSorted[popLength+1][soluLength];
	
	for (int c = 0 ; c < ( popLength - 1 ); c++){
    	for (int d = 0 ; d < popLength - c - 1; d++){

      		if (fitnessScores[d] > fitnessScores[d+1])  For decreasing order use < {
				swap = fitnessScores[d];
				for(int i = 0; i < popLength; i++){
					soluSwap[i] = solution[d][i];
					solution[d][i] = solution[d+1][i];
					solution[d+1][i] = soluSwap[i];
				}
        		fitnessScores[d]   = fitnessScores[d+1];
        		fitnessScores[d+1] = swap;
      		}
    	}
  	}

	for(int i = 0; i < popLength; i++){
		printf("The function returns %f for solution # %d \n", fitnessScores[i], i);
	}
	*/

	struct Generation generation1;
	for(int i = 0; i < popLength; i++){
		for(int n = 0; n < soluLength; n++){
			generation1.population[i].chromosome[n] = solution[i][n];
			generation1.population[i].fitnessScore = fitnessScores[i];
		}
	}	
	struct Population swap;
	for (int c = 0 ; c < ( popLength - 1 ); c++){
    	for (int d = 0 ; d < popLength - c - 1; d++){

      		if (generation1.population[d].fitnessScore < generation1.population[d+1].fitnessScore)  /*For decreasing order use <*/ {
				swap = generation1.population[d];
				/*for(int i = 0; i < popLength; i++){
					soluSwap[i] = solution[d][i];
					solution[d][i] = solution[d+1][i];
					solution[d+1][i] = soluSwap[i];
				}*/
				generation1.population[d] = generation1.population[d+1];
        		//fitnessScores[d]   = fitnessScores[d+1];
        		generation1.population[d+1] = swap;
				//fitnessScores[d+1] = swap;
      		}
    	}
  	}





	for(int i = 0; i < popLength; i++){
		printf("Row [%d] has fitness score %f \n", i , generation1.population[i].fitnessScore); 
	}
	for(int i = 0; i < soluLength; i++){
	printf("%d", generation1.population[0].chromosome[i]);
	}

	return 0;
}



























	//for(int i = 0; i < maxGenerations; i++){
		
	//Intialization();
	//all methods are working for initialization
	//order for SGA:
	//Initialization()
		//this will encompass getting the variable values, and bounding them
	//Fitness-Computation()
		//compute fitness using function call and organize a 2d data structure based on this computation
	//Sort()
		//organize the 2d structure of the fitness scores
	//Elite();
	//Crossover();
	//Weak-Elite();
	//Mutation()
	//Then loop back over.
