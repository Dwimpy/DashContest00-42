#include "RandomMapGenerator.hpp"
#include <fstream>
#include <iostream>
#include <ostream>

RandomMapGenerator::RandomMapGenerator(): _gridSize(2), _obstacleProbability(10.0), _distribution(0, 1)
{
	_gen.seed(_rd());
}
RandomMapGenerator::RandomMapGenerator(size_t gridSize, double obstacleProbability): _distribution(0, 1)
{
	_gen.seed(_rd());
	if (gridSize <= 0)
	{
		_gridSize = 1;
		std::cerr << "Grid size must be a positive integer value greater than 0. Setting grid size to 1." << std::endl;
	}
	else
		_gridSize = gridSize;
	if (obstacleProbability > 1.0 || obstacleProbability < 0.0)
	{
		_obstacleProbability = 0.10;
		std::cerr << "Invalid probability. Setting probability to default value of 10%" << std::endl;
	}
	else
		_obstacleProbability = obstacleProbability;
}

RandomMapGenerator::~RandomMapGenerator(){}

RandomMapGenerator::RandomMapGenerator(RandomMapGenerator const &copy)
{
	if (this != &copy)
	{
		this->_gen = copy._gen;
		this->_obstacleProbability = copy._obstacleProbability;
		this->_gridSize = copy._gridSize;
	}
}

RandomMapGenerator &RandomMapGenerator::operator=(RandomMapGenerator const &copy)
{
	if (this != &copy)
	{
		this->_gen = copy._gen;
		this->_obstacleProbability = copy._obstacleProbability;
		this->_gridSize = copy._gridSize;
	}
	return (*this);
}

void RandomMapGenerator::setGridSize(size_t gridSize)
{
	this->_gridSize = gridSize;
}

void RandomMapGenerator::setObstacleProbability(double obstacleProbability)
{
	if (obstacleProbability > 1.0 || obstacleProbability < 0.0)
	{
		_obstacleProbability = 0.10;
		std::cerr << "Invalid probability. Setting probability to default value of 10%" << std::endl;
	}
	else
		_obstacleProbability = obstacleProbability;
}

double	RandomMapGenerator::getRandomDouble()
{
	return (_distribution(_gen));
}

void RandomMapGenerator::generateMap()
{
	this->_map.clear();
	std::vector<char>	line;

	for (size_t i = 0; i < this->_gridSize; i++)
	{
		line.clear();
		for (size_t j = 0; j < this->_gridSize; j++)
		{
			if (getRandomDouble() > _obstacleProbability)
				line.emplace_back('.');
			else
				line.emplace_back('o');
		}
		_map.emplace_back(line);
	}
}

void RandomMapGenerator::outputMapToFile(void)
{
	std::ofstream outFile("map.txt");

	if (!outFile.is_open())
	{
		std::cerr << "Output file didn't open, exiting" << std::endl;
		exit(1);
	}
	for (const auto& row : _map)
	{
		for (char c : row)
		{
			outFile << c;
		}
		outFile  << '\n';
	}
}

void RandomMapGenerator::printMap()
{
	for (std::vector<char> vec : _map)
	{
		for (char elem : vec)
		{
			std::cout << elem << " ";
		}
		std::cout << "\n";
	}
}