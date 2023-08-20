#pragma once

#include <iostream>
#include <random>
#include <vector>
#include <ostream>
#include <string>
#include <sstream>

class RandomMapGenerator
{
  public:
	RandomMapGenerator();
	RandomMapGenerator(size_t gridSize, double obstacleProbability);
	~RandomMapGenerator();
	RandomMapGenerator(RandomMapGenerator const &copy);
	RandomMapGenerator &operator=(RandomMapGenerator const &copy);
	void	setGridSize(size_t gridSize);
	void	setObstacleProbability(double obstacleProbability);
	void	generateMap();
	void	printMap();
	void	outputMapToFile();
  private:
	double	getRandomDouble();

	std::random_device						_rd;
	std::mt19937							_gen;
	size_t									_gridSize;
	double									_obstacleProbability;
	std::uniform_real_distribution<double>	_distribution;
	std::vector<std::vector<char> >			_map;
};
