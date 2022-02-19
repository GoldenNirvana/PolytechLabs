#include <algorithm>

#include "bookmarks.hpp"
#include "commands.hpp"
#include "factorialcontainer.hpp"

void performBookmarks(std::istream &in, std::ostream &out)
{
  Bookmarks bookmarks;

  while (in >> std::ws, !in.eof())
  {
    convert(in)(bookmarks, out);
    std::string extraString;
    in.unget();
    char symbol = in.get();
    if (symbol != '\n')
    {
      std::getline(in, extraString, '\n');
    }
  }
  if (!in.eof())
  {
    throw std::invalid_argument("Failed to read.\n");
  }
}

void performFactorial(std::ostream &out)
{
  FactorialContainer container(1, 10);
  std::copy(container.begin(), container.end(), std::ostream_iterator<int>(out, " "));
  out << "\n";
  std::reverse_copy(container.begin(), container.end(), std::ostream_iterator<int>(out, " "));
  out << "\n";
}
