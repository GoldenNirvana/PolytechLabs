#include "shape.hpp"

#include <iostream>
#include <cmath>
#include <iterator>

#include "skipTillNewLine.hpp"

bool isTriangle(const Shape &shape)
{
  return (shape.size() == 3);
}

bool isRectangle(const Shape &shape)
{
  return ((shape.size() == 4) && (getSquaredDistance(shape[0], shape[1]) == getSquaredDistance(shape[2], shape[3])) &&
          (getSquaredDistance(shape[0], shape[3]) == getSquaredDistance(shape[1], shape[2])) &&
          (getSquaredDistance(shape[1], shape[3]) == getSquaredDistance(shape[0], shape[2])));
}

bool isSquare(const Shape &shape)
{
  return (isRectangle(shape) && (getSquaredDistance(shape[0], shape[1]) == getSquaredDistance(shape[1], shape[2])));
}

bool isPentagon(const Shape &shape)
{
  return (shape.size() == 5);
}

size_t getSquaredDistance(const Point &firstPoint, const Point &secondPoint)
{
  return std::pow(firstPoint.x - secondPoint.x, 2) + std::pow(firstPoint.y - secondPoint.y, 2);
}

std::istream &operator>>(std::istream &in, Point &point)
{
  char firstBracket = ' ';
  char semicolon = ' ';
  char secondBracket = ' ';
  int x = 0;
  int y = 0;

  in >> skipTillNewLine >> std::noskipws >> firstBracket >> skipTillNewLine >> std::noskipws >> x >> skipTillNewLine
     >> std::noskipws >> semicolon >> skipTillNewLine >> std::noskipws >> y >> skipTillNewLine >> std::noskipws
     >> secondBracket;

  if (in.fail() || (firstBracket != '(') || (semicolon != ';') || (secondBracket != ')'))
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  point = {x, y};
  return in;
}

std::istream &operator>>(std::istream &in, Shape &shape)
{
  size_t numberVertices = 0;
  in >> std::ws >> numberVertices;
  if (numberVertices < 3)
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  if (in.eof() || in.fail())
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }
  shape.clear();

  Point vertex{0, 0};
  for (size_t i = 0; i < numberVertices; i++)
  {
    in >> vertex;
    if (in.fail())
    {
      if (in.eof())
      {
        in.clear();
        in.setstate(std::ios_base::failbit);
      }
      return in;
    }
    shape.push_back(vertex);
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
  return out << "(" << point.x << "; " << point.y << ")";
}

std::ostream &operator<<(std::ostream &out, const Shape &shape)
{
  out << shape.size() << ' ';
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}

bool compare::operator()(const Shape &first, const Shape &second)
{
  if (first.size() != second.size())
  {
    return first.size() < second.size();
  }
  return ((isRectangle(first) && !isRectangle(second)) || (isSquare(first) && !isSquare((second))));
}
