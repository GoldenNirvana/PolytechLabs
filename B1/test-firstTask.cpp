#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <vector>
#include <forward_list>

#include "sorts.hpp"

const std::vector<int> VECTOR{128, 8, 64, 4, 2, 1, 16, 256, 32};
const std::forward_list<int> LIST{128, 8, 64, 4, 2, 1, 16, 256, 32};

BOOST_AUTO_TEST_SUITE(bubbleSortingTest)

  BOOST_AUTO_TEST_CASE(succesfullAscendingVectorbubbleSort)
  {
    std::vector<int> vector(VECTOR);
    BOOST_CHECK_NO_THROW(bubble_sort<OperatorAccess>(vector, ASCENDING));

    for (size_t i = 0; i < vector.size() - 1; i++)
    {
      BOOST_CHECK(vector[i] <= vector[i + 1]);
    }
  }

  BOOST_AUTO_TEST_CASE(succesfullAscendingVectorbubbleSortwithAt)
  {
    std::vector<int> vector(VECTOR);
    BOOST_CHECK_NO_THROW(bubble_sort<AtAccess>(vector, ASCENDING));

    for (size_t i = 0; i < vector.size() - 1; i++)
    {
      BOOST_CHECK(vector[i] <= vector[i + 1]);
    }
  }

  BOOST_AUTO_TEST_CASE(succesfullAscendingListbubbleSort)
  {
    std::forward_list<int> list(LIST);
    BOOST_CHECK_NO_THROW(bubble_sort<IteratorAccess>(list, ASCENDING));

    for (auto i = list.cbegin(), temp = ++i, end = list.cend(); temp != end; i++, temp++)
    {
      BOOST_CHECK(*i <= *temp);
    }
  }

  BOOST_AUTO_TEST_CASE(succesfullDescendingVectorbubbleSort)
  {
    std::vector<int> vector(VECTOR);
    BOOST_CHECK_NO_THROW(bubble_sort<OperatorAccess>(vector, DESCENDING));

    for (size_t i = 0; i < vector.size() - 1; i++)
    {
      BOOST_CHECK(vector[i] >= vector[i + 1]);
    }
  }

  BOOST_AUTO_TEST_CASE(succesfullDescendingVectorbubbleSortwithAt)
  {
    std::vector<int> vector(VECTOR);
    BOOST_CHECK_NO_THROW(bubble_sort<AtAccess>(vector, DESCENDING));

    for (size_t i = 0; i < vector.size() - 1; i++)
    {
      BOOST_CHECK(vector[i] >= vector[i + 1]);
    }
  }

  BOOST_AUTO_TEST_CASE(succesfullDescendingListbubbleSort)
  {
    std::forward_list<int> list(LIST);
    BOOST_CHECK_NO_THROW(bubble_sort<IteratorAccess>(list, DESCENDING));

    for (auto i = list.cbegin(), temp = ++i, end = list.cend(); temp != end; i++, temp++)
    {
      BOOST_CHECK(*i >= *temp);
    }
  }

BOOST_AUTO_TEST_SUITE_END()
