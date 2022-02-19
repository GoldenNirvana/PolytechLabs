#ifndef DATASTRUCT_HPP
#define DATASTRUCT_HPP

#include <iosfwd>
#include <string>

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
};

std::istream &operator>>(std::istream &in, DataStruct &data);
std::ostream &operator<<(std::ostream &out, const DataStruct &data);
bool operator<(const DataStruct &lhs, const DataStruct &rhs);

#endif
