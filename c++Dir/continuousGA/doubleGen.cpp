#include <random>
#include <iostream>
#include <ctime> 

int main()
{
	//Type of random number distribution
	std::uniform_real_distribution<double> dist(-1023.00, 1024.00);  //(min, max)

	//Mersenne Twister: Good quality random number generator
	std::mt19937 rng; 
	
	//Initialize with non-deterministic seeds
	rng.seed(std::random_device{}()); 

	// generate 10 random numbers.
	for (int i=0; i<100; i++)
	{
		std::cout << dist(rng) << std::endl;
	}
	
	return 0;
}
