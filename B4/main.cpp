#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

#include "DataStruct.hpp"

int main()
{
  std::vector<DataStruct> vector((std::istream_iterator<DataStruct>(std::cin)), std::istream_iterator<DataStruct>());

  if (std::cin.bad())
  {
    std::cerr << "Incorrect data.";
    return 1;
  }
  if (!std::cin.eof())
  {
    std::cerr << "Error reading file.";
    return 1;
  }

  std::sort(vector.begin(), vector.end());
  std::copy(vector.begin(), vector.end(), std::ostream_iterator<DataStruct>(std::cout, "\n"));
  return 0;
}
