#include "dash.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		return EXIT_FAILURE;
	struct dash::program	program;
	std::ifstream			inputMap;

	dash::rectangle_empty(program.largest_rectangle);
	inputMap = dash::openInputMap(argv[1]);
	dash::createHeightMap(inputMap, program);

	return (EXIT_SUCCESS);
}
