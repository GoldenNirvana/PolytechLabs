#ifndef B1_ACCESS_HPP
#define B1_ACCESS_HPP

#include <iostream>
#include <cstring>
#include <stdexcept>

template<typename Container>
class OperatorAccess
{
public:
  using value_type = typename Container::value_type;
  using index_type = size_t;

  static index_type begin(const Container &)
  {
    return 0;
  }
  static index_type end(const Container &container)
  {
    return container.size();
  }
  static value_type &get(Container &container, size_t index)
  {
    return container[index];
  }
};

template<typename Container>
class AtAccess
{
public:
  using value_type = typename Container::value_type;
  using index_type = size_t;

  static index_type begin(const Container &)
  {
    return 0;
  }
  static index_type end(const Container &container)
  {
    return container.size();
  }
  static value_type &get(Container &container, size_t index)
  {
    return container.at(index);
  }
};

template<typename Container>
class IteratorAccess
{
public:
  using iterator = typename Container::iterator;
  using value_type = typename Container::value_type;

  static iterator begin(Container &container)
  {
    return container.begin();
  }
  static iterator end(Container &container)
  {
    return container.end();
  }
  static value_type &get(Container &, iterator &index)
  {
    return *index;
  }
};

#endif
