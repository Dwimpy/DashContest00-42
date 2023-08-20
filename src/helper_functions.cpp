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

void	dash::createHeightMap(std::ifstream &inputMap, Buffer &buffer)
{
	std::string	lineData;
	size_t		lineDataSize;
	std::getline(inputMap, lineData);
	for (char elem : lineData)
		if (elem == '.')
			buffer.emplace_back(1);
		else
			buffer.emplace_back(0);
	while (std::getline(inputMap, lineData))
	{
		lineDataSize = lineData.size();
		for (size_t idx = 0; idx < lineDataSize; idx++)
		{
			if (lineData[idx] == '.')
				buffer[idx] += 1;
			else
				buffer[idx] = 0;
		}
		dash::printBufferElements(buffer);
	}
}

void	dash::printBufferElements(Buffer const &buffer)
{
	for (int elem : buffer)
		std::cout << elem << " ";
	std::cout << "\n";
}