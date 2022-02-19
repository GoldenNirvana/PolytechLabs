#ifndef FACTORIALITERATOR_HPP
#define FACTORIALITERATOR_HPP

#include <iterator>

class FactorialIterator : public std::iterator<std::bidirectional_iterator_tag, size_t, size_t, const size_t *, size_t>
{
public:
  FactorialIterator(const size_t pos);
  FactorialIterator(const size_t position, const size_t min, const size_t max);

  FactorialIterator &operator++();
  FactorialIterator operator++(int);
  FactorialIterator &operator--();
  FactorialIterator operator--(int);

  const size_t &operator*() const;
  bool operator==(const FactorialIterator &) const;
  bool operator!=(const FactorialIterator &) const;

private:
  size_t pos_;
  size_t value_;
  size_t minPos_;
  size_t maxPos_;
  size_t getValue(const size_t number) const;
};

#endif
