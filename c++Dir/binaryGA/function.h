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
	std::vector<double> function1Bounds(std::vector<int> variables, int numOfVars);
	double function1Fitness(std::vector<double> boundedVars, int numOfVars);

};






