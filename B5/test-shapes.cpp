#include <string>
#include <sstream>
#include <cstddef>
#include <boost/test/unit_test.hpp>

#include "shape.hpp"

void fillAndSortShapes(std::istream &in, std::ostream &out);

const Point ZERO_POINT = {0, 0};
const Point POINT = {6, 8};
const size_t SQUARED_DISTANCE_BETWEEN_POINTS = 100;

const Shape TRIANGLE = {{0, 0}, {5, 0}, {0, 5}};
const Shape INCORRECT_RECTANGLE = {{0, 0}, {5, 0}, {5, 10}, {0, 9}};
const Shape RECTANGLE = {{0, 0}, {5, 0}, {5, 10}, {0, 10}};
const Shape INCORRECT_SQUARE = {{0, 0}, {5, 0}, {5, 5}, {0, 4}};
const Shape SQUARE = {{0, 0}, {0, 5}, {5, 5}, {5, 0}};
const Shape TRAPEZOID = {{0, 0}, {2, 2}, {4, 2}, {6, 0}};
const Shape PARALLELOGRAM = {{0, 0}, {2, 2}, {4, 2}, {2, 0}};
const Shape PENTAGON = {{0, 0}, {2, 2}, {3, 2}, {4, 3}, {7, 0}};

const std::string EMPTY_IN = "";
const std::string EMPTY_OUT = "Vertices: 0\nTriangles: 0\nSquares: 0\nRectangles: 0\nPoints: \nShapes:\n";

const std::string COLLECTION_ONE = "4 (2;2) (0;2) (0;0) (2;0)\n5 (0;2) (2;4) (4;4) (6;2) (3;0)\n3 (0;0) (5;0) (0;5)\n";
const std::string COLLECTION_ONE_OUT = "Vertices: 12\nTriangles: 1\nSquares: 1\nRectangles: 1\n"
                                       "Points: (2; 2) (0; 0) \nShapes:\n3 (0; 0) (5; 0) (0; 5) \n"
                                       "4 (2; 2) (0; 2) (0; 0) (2; 0) \n";

const std::string COLLECTION_TWO = "3 (1;1) (5;7) (8;2)\n4   (2;2) (0;2)  (0;0) (2;0)\n"
                                   "3     (0;0)  (5;0) (0;5)   ";
const std::string COLLECTION_TWO_OUT = "Vertices: 10\nTriangles: 2\nSquares: 1\nRectangles: 1\n"
                                       "Points: (1; 1) (2; 2) (0; 0) \nShapes:\n3 (1; 1) (5; 7) (8; 2) \n"
                                       "3 (0; 0) (5; 0) (0; 5) \n4 (2; 2) (0; 2) (0; 0) (2; 0) \n";

BOOST_AUTO_TEST_SUITE(ShapesTest)

  BOOST_AUTO_TEST_CASE(isTriangleTest)
  {
    BOOST_CHECK(isTriangle(TRIANGLE));
  }

  BOOST_AUTO_TEST_CASE(isRectangleTest)
  {
    BOOST_CHECK(isRectangle(RECTANGLE));
    BOOST_CHECK(!isRectangle(INCORRECT_RECTANGLE));
  }

  BOOST_AUTO_TEST_CASE(isSquareTest)
  {
    BOOST_CHECK(isSquare(SQUARE));
    BOOST_CHECK(!isSquare(INCORRECT_SQUARE));
  }

  BOOST_AUTO_TEST_CASE(isPentagonTest)
  {
    BOOST_CHECK(isPentagon(PENTAGON));
  }

  BOOST_AUTO_TEST_CASE(getSquaredDistanceTest)
  {
    BOOST_CHECK_EQUAL(getSquaredDistance(ZERO_POINT, ZERO_POINT), 0);
    BOOST_CHECK_EQUAL(getSquaredDistance(ZERO_POINT, POINT), SQUARED_DISTANCE_BETWEEN_POINTS);
  }

  BOOST_AUTO_TEST_CASE(compareTest)
  {
    BOOST_CHECK(compare()(TRIANGLE, RECTANGLE));
    BOOST_CHECK(compare()(RECTANGLE, PENTAGON));
    BOOST_CHECK(compare()(TRIANGLE, PENTAGON));
    BOOST_CHECK(compare()(SQUARE, PENTAGON));
    BOOST_CHECK(compare()(SQUARE, RECTANGLE));
    BOOST_CHECK(compare()(SQUARE, PARALLELOGRAM));
    BOOST_CHECK(compare()(RECTANGLE, PARALLELOGRAM));
    BOOST_CHECK(compare()(SQUARE, TRAPEZOID));
    BOOST_CHECK(compare()(RECTANGLE, TRAPEZOID));
  }

  BOOST_AUTO_TEST_CASE(emptyTest)
  {
    std::istringstream in(EMPTY_IN);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillAndSortShapes(in, out));
    BOOST_CHECK_EQUAL(out.str(), EMPTY_OUT);
  }

  BOOST_AUTO_TEST_CASE(correctCollection)
  {
    std::istringstream in(COLLECTION_ONE);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillAndSortShapes(in, out));
    BOOST_CHECK_EQUAL(out.str(), COLLECTION_ONE_OUT);
  }

  BOOST_AUTO_TEST_CASE(inputWithManySpaces)
  {
    std::istringstream in(COLLECTION_TWO);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillAndSortShapes(in, out));
    BOOST_CHECK_EQUAL(out.str(), COLLECTION_TWO_OUT);
  }

BOOST_AUTO_TEST_SUITE_END()
