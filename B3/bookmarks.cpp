#include "bookmarks.hpp"

#include <ostream>
#include <algorithm>

using iterator = std::map<std::string, Phonebook::iterator>::iterator;
using const_iterator = std::map<std::string, Phonebook::iterator>::const_iterator;

Bookmarks::Bookmarks()
{
  bookmarks_["current"] = nodes_.begin();
}

void Bookmarks::add(const Phonebook::record &record)
{
  nodes_.pushBack(record);
  if (std::next(nodes_.begin()) == nodes_.end())
  {
    std::for_each(bookmarks_.begin(), bookmarks_.end(), [&](auto &iter)
    {
      iter.second = nodes_.begin();
    });
  }
}

void Bookmarks::store(const std::string &bookmark, const std::string &newMark, std::ostream &out)
{
  iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    bookmarks_.emplace(newMark, iter->second);
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }

}

void Bookmarks::insert(const std::string &bookmark, const Phonebook::record &record, const InsertPosition &position,
                       std::ostream &out)
{
  iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (iter->second == nodes_.end())
    {
      add(record);
    }

    switch (position)
    {
      case before:
      {
        nodes_.insert(iter->second, record);
        break;
      }
      case after:
      {
        nodes_.insert(std::next(iter->second), record);
        break;
      }
    }
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmarks::remove(const std::string &bookmark, std::ostream &out)
{
  iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    auto deleteIter = iter->second;
    for (auto &mark: bookmarks_)
    {
      if (mark.second == deleteIter)
      {
        if (std::next(mark.second) == nodes_.end())
        {
          mark.second = std::prev(deleteIter);
        }
        else
        {
          mark.second = std::next(deleteIter);
        }
      }
    }
    nodes_.remove(deleteIter);
    return;
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmarks::show(const std::string &bookmark, std::ostream &out) const
{
  const_iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (nodes_.isEmpty())
    {
      out << "<EMPTY>\n";
      return;
    }
    out << *iter->second << "\n";

    return;
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmarks::move(const std::string &bookmark, const int step, std::ostream &out)
{
  iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (nodes_.isEmpty())
    {
      return;
    }
    iter->second = nodes_.move(iter->second, step);
    return;
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}

void Bookmarks::move(const std::string &bookmark, const MovePosition &position, std::ostream &out)
{
  iterator iter = bookmarks_.find(bookmark);
  if (iter != bookmarks_.end())
  {
    if (nodes_.isEmpty())
    {
      return;
    }
    switch (position)
    {
      case first:
      {
        iter->second = nodes_.begin();
        break;
      }
      case last:
      {
        iter->second = --nodes_.end();
        break;
      }
    }
    return;
  }
  else
  {
    out << "<INVALID BOOKMARK>\n";
  }
}
