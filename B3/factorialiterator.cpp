#include "factorialiterator.hpp"

FactorialIterator::FactorialIterator(const size_t pos):
  FactorialIterator(pos, 1, 10) {}

FactorialIterator::FactorialIterator(const size_t position, const size_t min, const size_t max):
  pos_(position),
  value_(getValue(position)),
  minPos_(min),
  maxPos_(max) {}

const size_t &FactorialIterator::operator*() const
{
  return value_;
}

FactorialIterator &FactorialIterator::operator++()
{
  if (pos_ == maxPos_)
  {
    throw std::out_of_range("Value is out of range");
  }
  value_ *= ++pos_;
  return *this;
}

FactorialIterator FactorialIterator::operator++(int)
{
  FactorialIterator iter = *this;
  ++(*this);
  return iter;
}

FactorialIterator &FactorialIterator::operator--()
{
  if (pos_ == minPos_)
  {
    throw std::out_of_range("Value can not be less than 1");
  }
  value_ /= pos_--;
  return *this;
}

FactorialIterator FactorialIterator::operator--(int)
{
  FactorialIterator iter = *this;
  --(*this);
  return iter;
}

bool FactorialIterator::operator==(const FactorialIterator &iter) const
{
  return pos_ == iter.pos_;
}

bool FactorialIterator::operator!=(const FactorialIterator &iter) const
{
  return !(*this == iter);
}

size_t FactorialIterator::getValue(const size_t number) const
{
  size_t result = 1;
  for (size_t i = 1; i <= number; i++)
  {
    result *= i;
  }
  return result;
}
