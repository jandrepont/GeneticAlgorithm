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

double function::functionEllipsoid(const std::vector<double> &gene, int &size)
{
    double partSum=0, totalSum=0;

    for(int i = 0; i < size; i++)
    {

        for(int j = i; j < size; j++)
        {
            partSum += gene[j];
        }
        totalSum += partSum*partSum;
        partSum=0;
    }
    return totalSum;
}

double function::functionZakharov(const std::vector<double> &gene, int &size)
{
    double sum1=0, sum2=0, sum3=0, totalSum=0, x=0;
    for(int i = 0; i < size; i++)
    {
        x = (gene[i] * gene[i]);
        sum1 += x;
        sum2 += ((i+1)*x);
    }
    sum2 = (sum2*0.5);
    sum3 = sum2;
    // sum2 = pow(sum2,2.0);
    // sum3 = pow(sum3, 4.0);
    totalSum = ((sum1 * sum2) + sum3);
    return totalSum;
}
