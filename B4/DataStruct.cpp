#include "DataStruct.hpp"

#include <string>
#include <iostream>

#include "skipTillNewLine.hpp"

const char COMMA = ',';
const int MAX_KEY = 5;
const int MIN_KEY = -5;

std::istream &operator>>(std::istream &in, DataStruct &data)
{
  char symbol1 = ' ';
  char symbol2 = ' ';
  int keys[2] = {0, 0};

  std::noskipws(in);
  in >> skipTillNewLine >> keys[0] >> skipTillNewLine >> symbol1 >> skipTillNewLine >> keys[1] >> skipTillNewLine
     >> symbol2;

  if ((keys[0] > MAX_KEY) || (keys[1] > MAX_KEY) || (keys[0] < MIN_KEY) || (keys[1] < MIN_KEY)
      || (symbol1 != COMMA) || (symbol2 != COMMA))
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }

  std::string str;
  getline(in >> skipTillNewLine, str);
  if (str.empty())
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  data = {keys[0], keys[1], str};
  return in;
}

std::ostream &operator<<(std::ostream &out, const DataStruct &data)
{
  out << data.key1 << "," << data.key2 << "," << data.str;
  return out;
}

bool operator<(const DataStruct &left, const DataStruct &right)
{
  if (left.key1 != right.key1)
  {
    return left.key1 < right.key1;
  }
  if (left.key2 != right.key2)
  {
    return left.key2 < right.key2;
  }
  return left.str.size() < right.str.size();
}
