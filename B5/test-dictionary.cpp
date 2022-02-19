#include <string>
#include <sstream>
#include <boost/test/unit_test.hpp>

void fillDictionary(std::istream &in, std::ostream &out);

const std::string STRING_WITH_ONE_WORD = " \n Metal   ";
const std::string STRING_WITH_THREE_WORDS = " you \n and  me \n  ";
const std::string STRING_WITH_FIVE_WORDS = " Breaking \n  Benjamin And \n Adam Gontier";
const std::string ONE_WORD_OUT = "Metal\n";
const std::string THREE_WORDS_OUT = "and\nme\nyou\n";
const std::string FIVE_WORDS_OUT = "Adam\nAnd\nBenjamin\nBreaking\nGontier\n";

const std::string EMPTY = "";

BOOST_AUTO_TEST_SUITE(DictionaryTest)

  BOOST_AUTO_TEST_CASE(emptyTest)
  {
    std::istringstream in(EMPTY);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillDictionary(in, out));
    BOOST_CHECK_EQUAL(out.str(), EMPTY);
  }

  BOOST_AUTO_TEST_CASE(oneWordTest)
  {
    std::istringstream in(STRING_WITH_ONE_WORD);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillDictionary(in, out));
    BOOST_CHECK_EQUAL(out.str(), ONE_WORD_OUT);
  }

  BOOST_AUTO_TEST_CASE(threeWordsTest)
  {
    std::istringstream in(STRING_WITH_THREE_WORDS);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillDictionary(in, out));
    BOOST_CHECK_EQUAL(out.str(), THREE_WORDS_OUT);
  }

  BOOST_AUTO_TEST_CASE(fiveWordsTest)
  {
    std::istringstream in(STRING_WITH_FIVE_WORDS);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(fillDictionary(in, out));
    BOOST_CHECK_EQUAL(out.str(), FIVE_WORDS_OUT);
  }

BOOST_AUTO_TEST_SUITE_END()
