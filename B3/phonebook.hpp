#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <string>
#include <iosfwd>

class Phonebook
{
public:
  struct record
  {
    std::string name;
    std::string number;
  };

  using container = std::list<record>;
  using iterator = container::iterator;

  iterator begin();
  iterator end();

  bool isEmpty() const;
  iterator move(iterator &iter, int step);
  iterator insert(const iterator &iter, const record &record);
  void pushBack(const record &node);
  iterator remove(iterator &iter);
  friend std::ostream &operator<<(std::ostream &out, record &record);

private:
  container list_;
};

#endif
