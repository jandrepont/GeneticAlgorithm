#include "Population.h" 

class GenAlg{
	private:
		std::vector<Population> population;

	public:
		
		GenAlg();

		GenAlg(int numOfPops);
		
		int rouletteWheel(vector<Population> population);
		void cross1(vector<Population> population);
		
