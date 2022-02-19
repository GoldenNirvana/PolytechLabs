#ifndef SORTS_HPP
#define SORTS_HPP

#include <stdexcept>
#include "access.hpp"

enum SortParameter
{
  DESCENDING,
  ASCENDING
};

template<typename T>
bool getComparator(const T &first, const T &second, SortParameter &sortParameter)
{
  if (sortParameter == ASCENDING)
  {
    return first > second;
  }
  if (sortParameter == DESCENDING)
  {
    return first < second;
  }
  throw std::invalid_argument("Wrong sortParameter.");
}

template<template<typename Container> class AccessType, typename T>
void bubble_sort(T &container, SortParameter parameter)
{
  for (auto i = AccessType<T>::begin(container);
       i != AccessType<T>::end(container); i++)
  {
    for (auto j = i; j != AccessType<T>::end(container); j++)
    {
      if (getComparator(AccessType<T>::get(container, i), AccessType<T>::get(container, j), parameter))
      {
        std::swap(AccessType<T>::get(container, i), AccessType<T>::get(container, j));
      }
    }
  }
}

#endif
