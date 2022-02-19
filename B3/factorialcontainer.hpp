#ifndef FACTORIALCONTAINER_HPP
#define FACTORIALCONTAINER_HPP

#include <iterator>

#include "factorialiterator.hpp"

class FactorialContainer
{
public:
  FactorialContainer(const size_t minVal, const size_t maxVal);
  FactorialIterator begin() const;
  FactorialIterator end() const;

private:
  size_t minVal_;
  size_t maxVal_;
};

#endif
