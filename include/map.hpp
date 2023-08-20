#pragma once
#ifndef DASH_MAP_HPP
# define DASH_MAP_HPP

# include <vector>

namespace dash
{
  class Map
  {
    typedef std::vector<char> Buffer;
    public:
      Map();
      ~Map();

    private:
      Buffer  buffer;
      int     width;
      int     height;
  };
} // namespace dash

#endif