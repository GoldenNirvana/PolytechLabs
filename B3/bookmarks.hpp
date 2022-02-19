#ifndef BOOKMARKS_HPP
#define BOOKMARKS_HPP

#include <iosfwd>
#include <map>

#include "phonebook.hpp"

class Bookmarks
{
public:
  enum InsertPosition
  {
    before,
    after
  };

  enum MovePosition
  {
    first,
    last
  };

  Bookmarks();
  void add(const Phonebook::record &node);
  void store(const std::string &bookmark, const std::string &newMark, std::ostream &out);
  void insert(const std::string &bookmark, const Phonebook::record &record, const InsertPosition &position,
              std::ostream &out);
  void remove(const std::string &bookmark, std::ostream &out);
  void show(const std::string &bookmark, std::ostream &out) const;
  void move(const std::string &bookmark, const int step, std::ostream &out);
  void move(const std::string &bookmark, const MovePosition &position, std::ostream &out);

private:
  Phonebook nodes_;
  std::map<std::string, Phonebook::iterator> bookmarks_;
};


#endif
