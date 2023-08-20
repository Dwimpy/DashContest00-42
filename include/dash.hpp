#pragma once
#ifndef DASH_HPP
# define DASH_HPP

# include <vector>
# include <string>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <istream>


namespace dash
{
	typedef std::vector<int> Buffer;
	std::ifstream	openInputMap(std::string const &fileName);
	void	createHeightMap(std::ifstream &inputMap, Buffer &buffer);
	void	printBufferElements(Buffer const &buffer);



} // namespace dash

#endif