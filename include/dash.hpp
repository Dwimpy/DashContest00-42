#pragma once
#ifndef DASH_Hpp
# define DASH_Hpp

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