#include <vector>
#include <math.h>
#include <iostream>
#include <stdlib.h>



class function{

	public:

	//each function needs to properly define the bounds that the function will receive
	//and needs to define the actual function that returns a fitness value
	function();

	//function1 is defined as
	// f = 1 + Sum(1,10) of (x^2)/4000 - Product(1,10) cos(x/sqrt(i))
	//function1 bounds and function1 fitnessfunction
	double function1Fitness(const std::vector<double> &gene, int &size);


	double functionEllipsoid(const std::vector<double> &gene, int &size);

	double functionZakharov(const std::vector<double> &gene, int &size);
};
