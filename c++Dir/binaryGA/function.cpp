#include "function.h"

function::function(){};


std::vector<double> function::function1Bounds(std::vector<int> variables, int numOfVars)
{
	
	std::vector<double> boundedVars;
	for(int i = 0; i < numOfVars; i++){
		double boundedVar = ((variables[i] - 32768) / 32);
		boundedVars.push_back(boundedVar);
	}

	return boundedVars;
}

double function::function1Fitness(std::vector<double> boundedVars, int numOfVars)
{
	double totalSum = 0; 
	double sum = 0; 
	double product = 1;
	for(int i = 0; i < numOfVars; i++){
		double variable = boundedVars[i];
		sum += (variable*variable)/4000; 
		double cosValue = (cos(variable));
		double tempVal = (cosValue/(sqrt(i + 1)));
		product = product * tempVal;
	}
	totalSum = 1 + (sum - product);

	return totalSum;

}

