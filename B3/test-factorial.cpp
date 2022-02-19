#include <iostream>
#include <vector>
#include <cstddef>
#include <string>
#include <boost/test/unit_test.hpp>
#include "factorialcontainer.hpp"
#include "factorialiterator.hpp"

void performFactorial(std::ostream &out);

const size_t MIN_VALUE = 1;
const size_t MAX_VALUE = 10;

const std::vector<size_t> FACTORIAL_FOR_CHECK{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
const std::string OUT_FACTORIAL = "1 2 6 24 120 720 5040 40320 362880 3628800 \n3628800 362880 40320 5040 720 120 24 6 2 1 \n";

BOOST_AUTO_TEST_SUITE(testFactorial)

  BOOST_AUTO_TEST_CASE(exceptionConstrTest)
  {
    BOOST_CHECK_THROW(FactorialContainer container(MAX_VALUE, MIN_VALUE), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(noExceptionTest)
  {
    BOOST_CHECK_NO_THROW(FactorialContainer container(MIN_VALUE, MAX_VALUE));
  }

  BOOST_AUTO_TEST_CASE(noExceptionTest2)
  {
    BOOST_CHECK_NO_THROW(FactorialIterator iterator(5));
  }

  BOOST_AUTO_TEST_CASE(rightGetValutTest)
  {
    FactorialIterator iterator(8);
    BOOST_CHECK_EQUAL(*iterator, FACTORIAL_FOR_CHECK[8]);
  }

  BOOST_AUTO_TEST_CASE(noExceptionInc)
  {
    FactorialIterator iterator(4);
    BOOST_CHECK_NO_THROW(++iterator);
  }

  BOOST_AUTO_TEST_CASE(noExceptionDec)
  {
    FactorialIterator iterator(4);
    BOOST_CHECK_NO_THROW(--iterator);
  }

  BOOST_AUTO_TEST_CASE(noExceptionPostfixInc)
  {
    FactorialIterator iterator(4);
    BOOST_CHECK_NO_THROW(iterator++);
  }

  BOOST_AUTO_TEST_CASE(noExceptionPostfixDec)
  {
    FactorialIterator iterator(4);
    BOOST_CHECK_NO_THROW(iterator--);
  }

  BOOST_AUTO_TEST_CASE(incTest)
  {
    FactorialIterator iterator(4);
    ++iterator;
    BOOST_CHECK_EQUAL(*iterator, FACTORIAL_FOR_CHECK[5]);
  }

  BOOST_AUTO_TEST_CASE(incExceptionTest)
  {
    FactorialIterator iterator(10);
    BOOST_CHECK_THROW(++iterator, std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(decExceptionTest)
  {
    FactorialIterator iterator(1);
    BOOST_CHECK_THROW(--iterator, std::out_of_range);
  }

  BOOST_AUTO_TEST_CASE(decTest)
  {
    FactorialIterator iterator(4);
    --iterator;
    BOOST_CHECK_EQUAL(*iterator, FACTORIAL_FOR_CHECK[3]);
  }

  BOOST_AUTO_TEST_CASE(beginTest)
  {
    FactorialContainer container(MIN_VALUE, MAX_VALUE);
    FactorialIterator iterator = container.begin();
    BOOST_CHECK_EQUAL(*iterator, FACTORIAL_FOR_CHECK[MIN_VALUE]);
  }

  BOOST_AUTO_TEST_CASE(endTest)
  {
    FactorialContainer container(MIN_VALUE, MAX_VALUE - 1);
    FactorialIterator iterator = container.end();
    BOOST_CHECK_EQUAL(*iterator, FACTORIAL_FOR_CHECK[MAX_VALUE]);
  }

  BOOST_AUTO_TEST_CASE(correctOutTest)
  {
    std::ostringstream out;
    performFactorial(out);
    BOOST_CHECK_EQUAL(out.str(), OUT_FACTORIAL);
  }

BOOST_AUTO_TEST_SUITE_END()
