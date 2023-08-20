#include "dash.hpp"

std::ifstream	dash::openInputMap(std::string const &fileName)
{
	std::ifstream	inputMap;

	inputMap.open(fileName);
	if (!inputMap.is_open())
	{
		std::cerr << "Error opening map" << std::endl;
		exit(EXIT_FAILURE);
	}
	return (inputMap);
}

void	dash::createHeightMap(std::ifstream &inputMap, struct program &program)
{
	std::string	lineData;
	size_t		lineDataSize;

	std::getline(inputMap, lineData);
	for (char elem : lineData)
		if (elem == '.')
			program.histogram.emplace_back(1);
		else
			program.histogram.emplace_back(0);
	largest_area_from_histogram(program, 0);
	int			idx = 1;
	while (std::getline(inputMap, lineData))
	{
		lineDataSize = lineData.size();
		for (size_t idx = 0; idx < lineDataSize; idx++)
		{
			if (lineData[idx] == '.')
				program.histogram[idx] += 1;
			else
				program.histogram[idx] = 0;
		}
		largest_area_from_histogram(program, idx);
		idx++;
	}
	rectangle_print_corners(program.largest_rectangle);
}

void	dash::printBufferElements(Buffer const &buffer)
{
	for (int elem : buffer)
		std::cout << elem << " ";
	std::cout << "\n";
}
