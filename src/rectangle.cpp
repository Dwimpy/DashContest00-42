#include "dash.hpp"

namespace dash
{
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
} // namespace dash
