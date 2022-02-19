#include <boost/test/unit_test.hpp>

#include <stdexcept>
#include <cstring>
#include <string>
#include <sstream>

void bubbleSortRandomValues(const char *sortParameter, const int size, std::ostream &out);

const int IGNORE_VALUE = 1000;
const int INT_SIZE = 10;
const char *ASC = "ascending";
const char *DESC = "descending";

BOOST_AUTO_TEST_SUITE(task4Tests)

  BOOST_AUTO_TEST_CASE(AscendingTestCorrect)
  {
    std::stringstream stream;
    BOOST_CHECK_NO_THROW(bubbleSortRandomValues(ASC, INT_SIZE, stream));
    stream.ignore(IGNORE_VALUE, '\n');
    double tempResult = 0;
    stream >> tempResult;
    double current = 0;
    for (size_t i = 1; i < INT_SIZE; i++)
    {
      stream >> current;
      BOOST_CHECK(current >= tempResult);
      tempResult = current;
    }
  }

  BOOST_AUTO_TEST_CASE(DescendingTestCorrect)
  {
    std::stringstream stream;
    BOOST_CHECK_NO_THROW(bubbleSortRandomValues(DESC, INT_SIZE, stream));
    stream.ignore(IGNORE_VALUE, '\n');
    double tempResult = 0;
    stream >> tempResult;
    double current = 0;
    for (size_t i = 1; i < INT_SIZE; i++)
    {
      stream >> current;
      BOOST_CHECK(current <= tempResult);
      tempResult = current;
    }
  }

  BOOST_AUTO_TEST_CASE(emptySortMethodTest)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(bubbleSortRandomValues(nullptr, INT_SIZE, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectSortMethodTest)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(bubbleSortRandomValues("AScendingORdescending", INT_SIZE, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectSizeOfArrayTest)
  {
    std::ostringstream out;
    BOOST_CHECK_THROW(bubbleSortRandomValues(ASC, -INT_SIZE, out), std::invalid_argument);
  }


BOOST_AUTO_TEST_SUITE_END()
