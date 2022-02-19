#include <iostream>
#include <set>
#include <vector>
#include <numeric>
#include <iterator>
#include <algorithm>

#include "shape.hpp"

void fillDictionary(std::istream &in, std::ostream &out)
{
  std::set<std::string> dictionary((std::istream_iterator<std::string>(in)),
                                   std::istream_iterator<std::string>());
  if (!in.eof())
  {
    throw std::invalid_argument("Incorrect input");
  }
  std::copy(dictionary.begin(), dictionary.end(), std::ostream_iterator<std::string>(out, "\n"));
}

void fillAndSortShapes(std::istream &in, std::ostream &out)
{
  std::vector<Shape> shapes((std::istream_iterator<Shape>(in)), std::istream_iterator<Shape>());

  if ((in.fail() || in.bad()) && !in.eof())
  {
    throw std::ios_base::failure("Incorrect input");
  }

  size_t numberAllVertices = std::accumulate(shapes.begin(), shapes.end(), 0,
                                             [](int sum, const Shape &shape)
                                             {
                                               return sum + shape.size();
                                             });
  size_t numberTriangles = 0;
  size_t numberSquares = 0;
  size_t numberRectangles = 0;

  std::for_each(shapes.begin(), shapes.end(), [&](const Shape &shape)
  {
    if (isTriangle(shape))
    {
      ++numberTriangles;
    }
    if (isRectangle(shape))
    {
      if (isSquare(shape))
      {
        ++numberSquares;
      }
      ++numberRectangles;
    }
  });

  out << "Vertices: " << numberAllVertices << '\n';
  out << "Triangles: " << numberTriangles << '\n';
  out << "Squares: " << numberSquares << '\n';
  out << "Rectangles: " << numberRectangles << '\n';

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector<Point> points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), [](const Shape &shape)
  {
    return shape.front();
  });

  std::sort(shapes.begin(), shapes.end(), compare());

  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(out, "\n"));
}
