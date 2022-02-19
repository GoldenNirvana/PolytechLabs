#include "factorialcontainer.hpp"

FactorialContainer::FactorialContainer(const size_t minVal, const size_t maxVal):
  minVal_(minVal),
  maxVal_(maxVal + 1)
{
  if (minVal > maxVal)
  {
    throw std::invalid_argument("Incorrect order of values");
  }
}

FactorialIterator FactorialContainer::begin() const
{
  return FactorialIterator(minVal_, minVal_, maxVal_);
}

FactorialIterator FactorialContainer::end() const
{
  return FactorialIterator(maxVal_, minVal_, maxVal_);
}
