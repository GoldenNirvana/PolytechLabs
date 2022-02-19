#include "commands.hpp"

#include <iosfwd>
#include <functional>

#include "skipTillNewLine.hpp"

std::string fillCorrectNumber(std::istream &in)
{
  std::string number;
  in >> skipTillNewLine >> number;
  if (number.empty())
  {
    return "";
  }
  for (char i: number)
  {
    if (!std::isdigit(i))
    {
      return "";
    }
  }
  return number;
}

std::string fillCorrectName(std::istream &in)
{
  std::string name;
  char symbol = in.get();

  while (symbol == ' ')
  {
    symbol = in.get();
  }
  if (symbol != '\"')
  {
    return "";
  }
  symbol = in.get();
  while ((symbol != '\"') && !in.eof())
  {
    if (symbol == '\n')
    {
      return "";
    }
    if (symbol == '\\')
    {
      symbol = in.get();
      if (!((symbol == '\\') || (symbol == '\"')))
      {
        return "";
      }
    }
    name += symbol;
    symbol = in.get();
  }
  if ((symbol != '\"') || name.empty())
  {
    return "";
  }
  return name;
}

std::string fillCorrectMarkname(std::istream &in)
{
  std::string markname;
  in >> skipTillNewLine >> markname;
  if (markname.empty())
  {
    return "";
  }
  for (auto i: markname)
  {
    if ((!isalnum(i)) && (i != '-'))
    {
      return "";
    }
  }
  return markname;
}

bool isRightSteps(const std::string &step)
{
  for (char i: step)
  {
    if (!isdigit(i))
    {
      return false;
    }
  }
  return true;
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> convert(std::istream &in)
{
  static const std::map<std::string, std::function<void(Bookmarks &, std::ostream &)>(*)(std::istream &)> functions =
    {
      {"add",    add},
      {"store",  store},
      {"insert", insert},
      {"delete", remove},
      {"show",   show},
      {"move",   move}
    };

  std::string command;
  in >> std::ws >> command;

  auto iter = functions.find(command);
  if (iter == functions.end())
  {
    return printInvalidCommand;
  }
  return iter->second(in);
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> add(std::istream &in)
{
  std::string number = fillCorrectNumber(in);
  std::string name = fillCorrectName(in);
  if (number.empty() || name.empty())
  {
    return printInvalidCommand;
  }
  return [name, number](Bookmarks &bookmark, std::ostream &)
  {
    bookmark.add({name, number});
  };
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> store(std::istream &in)
{
  std::string markname = fillCorrectMarkname(in);
  std::string newMarkname = fillCorrectMarkname(in);

  if (markname.empty() || newMarkname.empty())
  {
    return printInvalidBookmark;
  }
  return [markname, newMarkname](Bookmarks &bookmark, std::ostream &out)
  {
    bookmark.store(markname, newMarkname, out);
  };
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> insert(std::istream &in)
{
  std::string position;
  in >> skipTillNewLine >> position;
  std::string markname = fillCorrectMarkname(in);
  std::string number = fillCorrectNumber(in);
  std::string name = fillCorrectName(in);

  if (markname.empty() || number.empty() || name.empty())
  {
    return printInvalidCommand;
  }
  return [position, markname, name, number](Bookmarks &bookmarks, std::ostream &out)
  {
    if (position == "before")
    {
      bookmarks.insert(markname, {name, number}, Bookmarks::InsertPosition::before, out);
    }
    else if (position == "after")
    {
      bookmarks.insert(markname, {name, number}, Bookmarks::InsertPosition::after, out);
    }
    else
    {
      printInvalidCommand(bookmarks, out);
    }
  };
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> remove(std::istream &in)
{
  std::string markname = fillCorrectMarkname(in);

  return [markname](Bookmarks &bookmarks, std::ostream &out)
  {
    if (markname.empty())
    {
      printInvalidBookmark(bookmarks, out);
    }
    else
    {
      bookmarks.remove(markname, out);
    }
  };
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> show(std::istream &in)
{
  std::string markname = fillCorrectMarkname(in);

  return [markname](Bookmarks &bookmarks, std::ostream &out)
  {
    if (markname.empty())
    {
      printInvalidBookmark(bookmarks, out);
    }
    else
    {
      bookmarks.show(markname, out);
    }
  };
}

std::function<void(Bookmarks &bookmarks, std::ostream &out)> move(std::istream &in)
{
  std::string markname = fillCorrectMarkname(in);
  std::string steps;
  std::getline(in >> skipTillNewLine, steps);


  return [markname, steps](Bookmarks &bookmarks, std::ostream &out)
  {
    if (markname.empty())
    {
      printInvalidCommand(bookmarks, out);
      return;
    }
    if (steps == "first")
    {
      bookmarks.move(markname, Bookmarks::MovePosition::first, out);
    }
    else if (steps == "last")
    {
      bookmarks.move(markname, Bookmarks::MovePosition::last, out);
    }
    else if (steps[0] == '-' || steps[0] == '+')
    {
      std::string str = steps.substr(1, steps.length() - 1);
      if (!isRightSteps(str))
      {
        printInvalidStep(out);
        return;
      }
      bookmarks.move(markname, std::stoi(steps), out);
    }
    else
    {
      if (!isRightSteps(steps))
      {
        printInvalidStep(out);
        return;
      }
      bookmarks.move(markname, std::stoi(steps), out);
    }
    if (steps.empty())
    {
      printInvalidCommand(bookmarks, out);
      return;
    }
  };
}

void printInvalidCommand(Bookmarks &, std::ostream &out)
{
  out << "<INVALID COMMAND>\n";
}

void printInvalidBookmark(Bookmarks &, std::ostream &out)
{
  out << "<INVALID BOOKMARK>\n";
}

void printInvalidStep(std::ostream &out)
{
  out << "<INVALID STEP>" << '\n';
}
