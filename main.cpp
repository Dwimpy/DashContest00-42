#include "dash.hpp"
#include <iostream>



int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	std::ifstream			inputMap;
	std::string 			lineData;
	dash::Buffer			dataBuffer;
	RandomMapGenerator		rng;

	inputMap = dash::openInputMap("map.txt");
	dash::createHeightMap(inputMap, dataBuffer);
	std::cout << "\n\n\n";
	rng.setGridSize(10);
	rng.setObstacleProbability(0.15);
	rng.generateMap();
	rng.printMap();
	return (EXIT_SUCCESS);
}
