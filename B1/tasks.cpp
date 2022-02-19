#include <vector>
#include <stdexcept>
#include <forward_list>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <memory>
#include "sorts.hpp"


inline SortParameter sortingTypeConverter(const char *sortParameter)
{
  if (sortParameter == nullptr)
  {
    throw std::invalid_argument("SortParameter is incorrect.");
  }
  if (std::strcmp(sortParameter, "ascending") == 0)
  {
    return ASCENDING;
  }
  if (std::strcmp(sortParameter, "descending") == 0)
  {
    return DESCENDING;
  }
  throw std::invalid_argument("SortParameter is incorrect.");
}

template<typename T>
void print(const T &data, std::ostream &out)
{
  for (auto i: data)
  {
    out << i << ' ';
  }
}

void bubbleSorts(const char *sortParameter, std::istream &in, std::ostream &out)
{
  SortParameter sorting = sortingTypeConverter(sortParameter);
  std::vector<int> vectorOne;
  std::vector<int> vectorTwo;
  std::forward_list<int> list;
  int value = 0;

  while ((!in.eof()) && (in >> value))
  {
    if (!in)
    {
      throw std::invalid_argument("Incorrect arguments");
    }
    vectorOne.push_back(value);
    vectorTwo.push_back(value);
    list.push_front(value);
  }
  if (!in.eof())
  {
    throw std::invalid_argument("Incorrect arguments");
  }
  bubble_sort<OperatorAccess>(vectorOne, sorting);
  bubble_sort<AtAccess>(vectorTwo, sorting);
  bubble_sort<IteratorAccess>(list, sorting);
  print(vectorOne, out);
  out << '\n';
  print(vectorTwo, out);
  out << '\n';
  print(list, out);
  out << '\n';
}

void readFromFile(const char *fileName, std::ostream &out)
{
  if (fileName == nullptr)
  {
    throw std::invalid_argument("File doesn't exist.");
  }
  size_t maxArraySize = 1000;
  std::ifstream inFile(fileName);
  if (!inFile.is_open())
  {
    throw std::logic_error("Can't open the file!");
  }

  std::unique_ptr<char[], decltype(&free)> array(static_cast<char *>(malloc(maxArraySize)), &free);
  size_t index = 0;
  while (inFile)
  {
    inFile.read(&array[index], maxArraySize - index);
    index += inFile.gcount();
    if (index == maxArraySize)
    {
      maxArraySize += 1000;
      std::unique_ptr<char[], decltype(&free)>
        newArray(static_cast<char *>(realloc(array.get(), maxArraySize)), &free);
      if (!newArray)
      {
        throw std::bad_alloc();
      }
      array.release();
      std::swap(array, newArray);
    }
  }
  inFile.close();
  if (inFile.is_open())
  {
    throw std::ios_base::failure("Can't close file");
  }
  std::vector<char> vector(&array[0], &array[index]);
  out.write(array.get(), index);
}

void convertVector(std::istream &in, std::ostream &out)
{
  std::vector<int> vector;
  int number = 0;
  while (in >> number)
  {
    if (number == 0)
    {
      break;
    }
    vector.push_back(number);
  }
  if (!in.eof() && in.fail())
  {
    throw std::invalid_argument("Reading error!");
  }
  if (number != 0)
  {
    throw std::invalid_argument("The last element must be zero!");
  }

  if (vector.empty())
  {
    return;
  }
  if (vector.back() == 1)
  {
    for (auto i = vector.begin(); i < vector.end();)
    {
      if (*i % 2 == 0)
      {
        i = vector.erase(i);
      }
      else
      {
        ++i;
      }
    }
  }
  else
    if (vector.back() == 2)
    {
      for (auto i = vector.begin(); i < vector.end();)
      {
        if (*i % 3 == 0)
        {
          i = vector.insert(++i, 3, 1);
          i += 3;
        }
        else
        {
          ++i;
        }
      }
    }
  print(vector, out);
}

void fillRandom(double *array, const int size)
{
  if (array == nullptr)
  {
    throw std::invalid_argument("Array is nullptr.");
  }
  if (size < 0)
  {
    throw std::invalid_argument("Incorrect size");
  }
  for (int i = 0; i < size; ++i)
  {
    array[i] = (std::rand() % 201) / 100.0 - 1;
  }
}

void bubbleSortRandomValues(const char *sortParameter, const int size, std::ostream &out)
{
  if (size < 0)
  {
    throw std::invalid_argument("Size of vector is incorrect");
  }
  SortParameter sorting = sortingTypeConverter(sortParameter);
  if (size == 0)
  {
    return;
  }
  std::vector<double> vector(size);
  srand(time(0));
  fillRandom(vector.data(), size);
  print(vector, out);
  out << '\n';
  bubble_sort<OperatorAccess>(vector, sorting);
  print(vector, out);
}
