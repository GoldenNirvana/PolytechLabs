#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>

struct Point
{
  int x;
  int y;
};

using Shape = std::vector<Point>;

bool isTriangle(const Shape &shape);
bool isRectangle(const Shape &shape);
bool isSquare(const Shape &shape);
bool isPentagon(const Shape &shape);

size_t getSquaredDistance(const Point &firstPoint, const Point &secondPoint);

std::istream &operator>>(std::istream &in, Point &point);
std::istream &operator>>(std::istream &in, Shape &shape);
std::ostream &operator<<(std::ostream &out, const Point &point);
std::ostream &operator<<(std::ostream &out, const Shape &shape);

struct compare
{
  bool operator()(const Shape &first, const Shape &second);
};

#endif
