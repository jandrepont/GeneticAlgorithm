#include "function.h"

function::function(){};



double function::function1Fitness(const std::vector<double> &gene, int &size)
{

	double totalSum = 0;
	double sum = 0;
	double product = 1;
	for(int i = 0; i < size; i++){
		double variable = gene[i];
		sum += (variable*variable)/4000;
		double cosValue = (cos(variable));
		double tempVal = (cosValue/(sqrt(i + 1)));
		product = product * tempVal;
	}
	totalSum = 1 + (sum - product);
	return totalSum;

}
