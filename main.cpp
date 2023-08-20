#include "RandomMapGenerator.hpp"
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

bool	isFloat(const std::string &str)
{
	std::istringstream	iss(str);
	double				value;
	iss >> std::noskipws >> value;
	if (!iss.eof() || iss.fail())
		return (false);
	return (true);
}

bool	isInt(const std::string &str)
{
	try{
		std::stoi(str);
		return (true);
	}catch (...) {
		return (false);
	}
}


int main(int argc, char **argv)
{
	RandomMapGenerator		rng;

	if (argc == 3)
	{
		if (!isInt(argv[1]) || !isFloat(argv[2]))
		{
			std::cerr << "Incorrect input paramterers" << std::endl;
			return (EXIT_FAILURE);
		}
		rng.setGridSize(std::stoi(argv[1]));
		rng.setObstacleProbability(std::stof(argv[2]));
		rng.generateMap();
		rng.printMap();
		rng.outputMapToFile();
			return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
