#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <math.h>

//char variable[100];
//float input_value(char*);
char* string[200];
//void inst_Solution(int, int, int*);
//int binary2Decimal(int*, int, int);
float boundVariable( int );
//int maxGenerations = 10;
//type *pointer = malloc(num_elems * sizeof(*pointer));
//Generation *generation = malloc(*maxGenerations * sizeof(*generation));
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
	
	float value = 0; 
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
	float boundedVariable = 0;
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

void preserveElites(Generation* generation, int generationNumber, float eliteRate, int popLength){ 
	
    int numberOfElites = popLength * eliteRate;
    for(int n = 0; n < numberOfElites; n++){
		generation[generationNumber].population[n] = generation[generationNumber - 1].population[n];
	}  
}
/*
void preserveWorst(Generation* generation, int generationNumber, int popLength, float bottomRate){
	
    int numberOfWorst = popLength * bottomRate;
    int start = popLength - numberOfWorst;
    
    for(int n = 0; n < numberOfWorst; n++){
	    	
		generation[generationNumber].population[start] = generation[generationNumber - 1].population[start];
        start ++;
	}
}
*/

int rouletteWheel (Generation* generation, int previousGeneration, int popLength){
    int maxFitness = 0;
    int selection = 0;

    for(int i = 0; i < popLength; i++){
       maxFitness = maxFitness + generation[previousGeneration].population[i].fitnessScore;
    }

    float random = rand() % maxFitness;
    int i = 0;
    while(random > 0){
        int current = generation[previousGeneration].population[i].fitnessScore;
        random = random - current;
        i++;
    }
    return i;
}


void cross(Generation* generation, int generationNumber, int chromLength, int popLength, int mutationRate, int eliteRate, int crossRate){
    struct Generation temp;
    int numOfChildren = crossRate * popLength;
    int numOfElite = eliteRate * popLength;
    int start = numOfElite;
    int end = numOfElite + numOfChildren;
   // int numOfWorst = bottomRate * popLength;
   // int end = popLength - numOfWorst;

        
    for(start; start < end ; start  = start + 2){
        int geneStart = rand() % chromLength;
       // int genestart2 = rand()% chromLength;
        int negGeneStart = geneStart;
       // int negGeneStart2 = geneStart2;
       // int previousGeneration = generationNumber - 1;
        int randomPar1 = rand() % popLength;
        int randomPar2 = rand() % popLength;
       // int randomPar1 = rouletteWheel (generation, previousGeneration, popLength);
       // int randomPar2 = rouletteWheel (generation, previousGeneration, popLength);
        
        
        
        int randGene = rand() % chromLength / 2;
        int randGene2 = randGene + (rand() % chromLength / 2);
        //go from o to randGene for both children
     
       
        //offspring1 gets parent2 middle and parent1 exterior
        //offspring2 gets parent1 middle and parent2 exterior
        for(int start  = 0; start < randGene; start++){
        
            temp.population[0].chromosome[start] = generation[generationNumber].population[randomPar1].chromosome[start];
            //temp.population[0].chromosome[geneStart] = generation[generationNumber].population[randomPar2].chromosome[negGeneStart];
            
            temp.population[1].chromosome[start] = generation[generationNumber].population[randomPar2].chromosome[start];
            //temp.population[1].chromosome[negGeneStart] = generation[generationNumber].population[randomPar1].chromosome[negGeneStart];
        }
        for(int n = randGene2; n < chromLength; n++){
            
            temp.population[0].chromosome[n] = generation[generationNumber].population[randomPar1].chromosome[n];
            temp.population[1].chromosome[n] = generation[generationNumber].population[randomPar2].chromosome[n];
        }
        for(randGene; randGene < randGene2; randGene++){

            //notice how these two are switched, this way the middles are switched for the children. 
            temp.population[1].chromosome[randGene] = generation[generationNumber].population[randomPar1].chromosome[randGene];
            temp.population[0].chromosome[randGene] = generation[generationNumber].population[randomPar2].chromosome[randGene];

        }

        //Single point crossover
        /*
        for(; geneStart < chromLength; geneStart++){
            temp.population[0].chromosome[geneStart] = generation[generationNumber].population[randomPar1].chromosome[geneStart];
            temp.population[0].chromosome[geneStart] = generation[generationNumber].population[randomPar2].chromosome[negGeneStart];
            
            temp.population[1].chromosome[negGeneStart] = generation[generationNumber].population[randomPar2].chromosome[geneStart];
            temp.population[1].chromosome[negGeneStart] = generation[generationNumber].population[randomPar1].chromosome[negGeneStart];
            
            negGeneStart--;
        }
        */

        generation[generationNumber].population[start] = temp.population[0];
        generation[generationNumber].population[start + 1] = temp.population[1];
	}
} 

void fillPop(Generation* generation, int generationNumber, int chromLength, int popLength, float mutation, float eliteRate, int crossRate){
    
    int numberOfElite = popLength * eliteRate;
    int numberOfChildren = popLength * crossRate;
    int start = numberOfElite + numberOfChildren;
    for(start; start < popLength; start++){
        for(int i = 0; i < chromLength; i++){
                generation[generationNumber].population[start].chromosome[i] = rand() % 2;	
        }
    }
}

void mutate(Generation* generation, int generationNumber, int chromLength, int popLength, float mutation, float eliteRate){

    int numberOfMutations = mutation * popLength;
    int excluded = eliteRate * popLength;
   //int start = excluded;
    for(int n = 0; n < numberOfMutations; n++){
        int randomPop = rand() % popLength;
        int randGene = rand() % chromLength;
        int randGene2 = rand() % chromLength; 
        if(randomPop  < excluded){
            randomPop = randomPop + excluded;
        }
        int bitValue = generation[generationNumber].population[randomPop].chromosome[randGene];
        bitValue = bitValue + 1;
        bitValue = bitValue % 2;
        generation[generationNumber].population[randomPop].chromosome[randGene] = bitValue;	 
        
        bitValue = generation[generationNumber].population[randomPop].chromosome[randGene2];
        bitValue = bitValue + 1;
        bitValue = bitValue % 2;
        generation[generationNumber].population[randomPop].chromosome[randGene2] = bitValue;
        
    }
}





int main(){
			
	int populationSize = 200;
    int chromosomeLength =160; 
    int variables = 10; 
    int maxGenerations = 50; 
    float eliteRate = .05;
    float crossRate = 0.05; 
    float mutation = 0.1;
   // float bottomRate = 0.8;
	
   //Start and input values 
    printf("Would you like to input own values? Enter y or n : \n ");
    char choice[0];
    scanf("%c", choice);
    if(choice[0] == 'y'){
        printf("All values must be entered as decimal values. i.e. 5 percent is .05 \n");    
        populationSize = input_value("population Size");
        chromosomeLength = input_value("Chromosome Length");
        variables = input_value("number of variables");
        maxGenerations = input_value("Maximum number of generations");
        eliteRate = input_value("percentage rate for preserving elites of last generation.");
       // bottomRate = input_value("percentage rate for the bottom fitness solutions to be preserved for next generation");
        crossRate = input_value("percentage rate of cross/children for next generation"); 
        mutation = input_value("percentage rate of mutation for next generation");
    }	
    /*
	 * Instantiate array for solution representation and fill with random bit values, make a 2d array 
	*/
	int soluLength = chromosomeLength;	
	int popLength = populationSize;
	

    //student *p = (student *)malloc(sizeof(student));

    //int *list;

    //list  = (int *) malloc(N * sizeof(int));i

    struct Generation* generation = malloc(maxGenerations * sizeof(*generation));
    generation[maxGenerations];
    //hashTable *table = malloc(N*sizeof(hashTable)); //allocate memory
    //... use it
    //    free(table); //free memory

	for(int generationNumber = 0; generationNumber < maxGenerations; generationNumber ++){	
		//instantiate
		if(generationNumber == 0){
			inst_Solution(popLength, soluLength, generation, generationNumber);
		}
	    //Since all new generation are built from old generations we pass
        //generationNumber -1
        //int previousGeneration = generationNumber - 1;

		else{
			preserveElites(generation , generationNumber, eliteRate, popLength);
			//preserveWorst(generation , generationNumber, popLength, bottomRate);
			cross(generation, generationNumber, chromosomeLength, popLength, mutation, eliteRate, crossRate);
            fillPop(generation, generationNumber, chromosomeLength, popLength, mutation, eliteRate, crossRate);
			mutate(generation, generationNumber, chromosomeLength, popLength, mutation, eliteRate);
            //cross();
	    }	
		
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
		

    
      //  for(int i = 0; i < popLength; i++){
      //      printf("Generation %d row [%d] has fitness score %f \n" , generationNumber , i,  generation[generationNumber].population[i].fitnessScore);
      //  }
    	
	    printf("Generation %d has fitness score %f \n" , generationNumber , generation[generationNumber].population[0].fitnessScore); 
      
    }

    free(generation);
	return 0;
}














