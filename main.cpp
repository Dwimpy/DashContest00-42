#include "dash.hpp"



int main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	std::ifstream			inputMap;
	std::string 			lineData;
	dash::Buffer			dataBuffer;

	inputMap = dash::openInputMap("map.txt");
	dash::createHeightMap(inputMap, dataBuffer);

	return (EXIT_SUCCESS);
}
