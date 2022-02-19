#include "phonebook.hpp"

#include <ostream>

Phonebook::iterator Phonebook::begin()
{
  return list_.begin();
}

Phonebook::iterator Phonebook::end()
{
  return list_.end();
}

bool Phonebook::isEmpty() const
{
  return list_.empty();
}

Phonebook::iterator Phonebook::move(iterator &iter, int step)
{
  if (step >= 0)
  {
    while ((std::next(iter) != list_.end()) && (step > 0))
    {
      iter = std::next(iter);
      --step;
    }
  }
  else
  {
    while ((iter != list_.begin()) && (step < 0))
    {
      iter = std::prev(iter);
      ++step;
    }
  }
  return iter;
}

Phonebook::iterator Phonebook::insert(const iterator &iter, const record &record)
{
  return list_.insert(iter, record);
}

void Phonebook::pushBack(const record &node)
{
  list_.push_back(node);
}

Phonebook::iterator Phonebook::remove(iterator &iter)
{
  return list_.erase(iter);
}

std::ostream &operator<<(std::ostream &out, Phonebook::record &record)
{
  out << record.number << ' ' << record.name;
  return out;
}
