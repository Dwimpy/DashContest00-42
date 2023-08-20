#include <cstdlib>

#include <iostream>
#include <stack>
#include <tuple>
#include <vector>

struct  rectangle
{
	int top_left_x;
	int top_left_y;
	int bottom_right_x;
	int bottom_right_y;
	int area;
};

struct  program
{
	std::stack<int>   histogram_indices;
	std::vector<int>  histogram;
	struct rectangle	largest_rectangle;
};

void	rectangle_empty(struct rectangle &rectangle)
{
	rectangle = (struct rectangle){
		.top_left_x = 0,
		.top_left_y = 0,
		.bottom_right_x = 0,
		.bottom_right_y = 0,
		.area = 0
	};
}

void	rectangle_print(struct rectangle &rectangle)
{
	std::cout << "Top left: (" << rectangle.top_left_x << ", " << rectangle.top_left_y << ")" << std::endl;
	std::cout << "Bottom right: (" << rectangle.bottom_right_x << ", " << rectangle.bottom_right_y << ")" << std::endl;
	std::cout << "Area: " << rectangle.area << std::endl;
}

void  area_of_a_rectangle(struct program& program, int row_index, int current_bar_index)
{
  int height = program.histogram[program.histogram_indices.top()];
  program.histogram_indices.pop();
  int width = program.histogram_indices.empty() ? current_bar_index : current_bar_index - program.histogram_indices.top() - 1;
  // area = height * width. The width is the current index minus the index of the previous bar - 1.
  int area = height * width;
  if (area > program.largest_rectangle.area)
  {
    program.largest_rectangle = (struct rectangle){
      .top_left_x = current_bar_index - width,
      .top_left_y = row_index - height + 1,
      .bottom_right_x = current_bar_index - 1,
      .bottom_right_y = row_index,
      .area = area
    };
  }
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

int main(void)
{
	struct  program program;
	program.histogram.push_back(2);
	program.histogram.push_back(1);
	program.histogram.push_back(5);
	program.histogram.push_back(6);
	program.histogram.push_back(3);
	program.histogram.push_back(3);

	rectangle_empty(program.largest_rectangle);
	largest_area_from_histogram(program, 5);
	rectangle_print(program.largest_rectangle);
	return EXIT_SUCCESS;
}
