#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include <string>
#include <iostream>
#include <functional>

#include "bookmarks.hpp"

std::string fillCorrectNumber(std::istream &in);
std::string fillCorrectName(std::istream &in);
std::string fillCorrectMarkname(std::istream &in);
bool isRightSteps(const std::string &step);

using command = std::function<void(Bookmarks &bookmarks, std::ostream &out)>;
command convert(std::istream &in);
command add(std::istream &in);
command store(std::istream &in);
command insert(std::istream &in);
command remove(std::istream &in);
command show(std::istream &in);
command move(std::istream &in);

void printInvalidCommand(Bookmarks &, std::ostream &out = std::cout);
void printInvalidBookmark(Bookmarks &, std::ostream &out = std::cout);
void printInvalidStep(std::ostream &out = std::cout);

#endif
