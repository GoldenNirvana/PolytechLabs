#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include <string>

void convertVector(std::istream &in, std::ostream &out);

const std::string CORRECT_STRING_1("1 2 3 4 5 6 7 8 0");
const std::string CORRECT_STRING_1_OUT("1 2 3 4 5 6 7 8 ");
const std::string CORRECT_STRING_2("1 2 3 4 5 6 7 8 1 0");
const std::string CORRECT_STRING_2_OUT("1 3 5 7 1 ");
const std::string CORRECT_STRING_3("1 2 3 4 5 6 7 8 2 0");
const std::string CORRECT_STRING_3_OUT("1 2 3 1 1 1 4 5 6 1 1 1 7 8 2 ");

const std::string INCORRECT_STRING("1 2 3 4");
const std::string INCORRECT_STRING_2("R R S 1 5 T 0");

BOOST_AUTO_TEST_SUITE(Task3Tests)

  BOOST_AUTO_TEST_CASE(correctTest1)
  {
    std::istringstream in(CORRECT_STRING_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(convertVector(in, out));
    BOOST_CHECK(out.str() == CORRECT_STRING_1_OUT);
  }

  BOOST_AUTO_TEST_CASE(correctTest2)
  {
    std::istringstream in(CORRECT_STRING_2);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(convertVector(in, out));
    BOOST_CHECK(out.str() == CORRECT_STRING_2_OUT);
  }

  BOOST_AUTO_TEST_CASE(correctTest3)
  {
    std::istringstream in(CORRECT_STRING_3);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(convertVector(in, out));
    BOOST_CHECK(out.str() == CORRECT_STRING_3_OUT);
  }

  BOOST_AUTO_TEST_CASE(incorrectInTest1)
  {
    std::istringstream in(INCORRECT_STRING);
    std::ostringstream out;
    BOOST_CHECK_THROW(convertVector(in, out), std::invalid_argument);
  }

  BOOST_AUTO_TEST_CASE(incorrectInTest2)
  {
    std::istringstream in(INCORRECT_STRING_2);
    std::ostringstream out;
    BOOST_CHECK_THROW(convertVector(in, out), std::invalid_argument);
  }

BOOST_AUTO_TEST_SUITE_END()
