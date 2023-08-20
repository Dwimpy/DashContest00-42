#include "dash.hpp"

namespace dash
{
	static void  area_of_a_rectangle(struct program& program, int row_index, int current_bar_index)
	{
		int height = program.histogram[program.histogram_indices.top()];
		program.histogram_indices.pop();
		int width = program.histogram_indices.empty() ? current_bar_index : current_bar_index - program.histogram_indices.top() - 1;
		// area = height * width. The width is the current index minus the index of the previous bar - 1.
		int area = height * width;

		if (area < program.largest_rectangle.area)
			return ;
		int	top_left_x = current_bar_index - width;
		int	top_left_y = row_index - height + 1;
		if (area == program.largest_rectangle.area)
		{
			if (top_left_y > program.largest_rectangle.top_left_y)
				return ;
			else if (top_left_y == program.largest_rectangle.top_left_y)
			{
				if (top_left_x > program.largest_rectangle.top_left_x)
					return ;
				else if (top_left_x == program.largest_rectangle.top_left_x)
				{
					if (width <= program.largest_rectangle.bottom_right_x - program.largest_rectangle.top_left_x)
						return ;
				}
			}
		}
		program.largest_rectangle = (struct rectangle){
			.top_left_x = top_left_x,
			.top_left_y = top_left_y,
			.bottom_right_x = current_bar_index - 1,
			.bottom_right_y = row_index,
			.area = area
		};
	}

	void	largest_area_from_histogram(struct program& program, int row_index)
	{
		int current_bar_index = 0;

		while (current_bar_index < static_cast<int>(program.histogram.size()))
		{
			// When the current bar is bigger than the bar at the top of the stack, push it onto the stack.
			if (program.histogram_indices.empty() || \
			program.histogram[program.histogram_indices.top()] <= program.histogram[current_bar_index])
				program.histogram_indices.push(current_bar_index++);
			else
				area_of_a_rectangle(program, row_index, current_bar_index);
		}

		while (!program.histogram_indices.empty())
		{
			area_of_a_rectangle(program, row_index, current_bar_index);
		}
	}

} // namespace dash