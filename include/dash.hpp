#pragma once
#ifndef DASH_HPP
# define DASH_HPP

# include <vector>
# include <stack>
# include <string>
# include <fstream>
# include <iostream>
# include <cstdlib>
# include <istream>


namespace dash
{
	typedef std::vector<int> Buffer;

	struct  rectangle
	{
		int top_left_x;
		int top_left_y;
		int bottom_right_x;
		int bottom_right_y;
		int area;
	};

	void	rectangle_empty(struct rectangle &rectangle);

	void	rectangle_print(struct rectangle &rectangle);

	void	rectangle_print_corners(struct rectangle &rectangle);

	struct  program
	{
		std::stack<int>		histogram_indices;
		Buffer				histogram;
		struct rectangle	largest_rectangle;
	};

	void	largest_area_from_histogram(struct program& program, int row_index);

	std::ifstream	openInputMap(std::string const &fileName);
	void			createHeightMap(std::ifstream &inputMap, struct program &program);
	void			printBufferElements(Buffer const &buffer);

} // namespace dash

#endif