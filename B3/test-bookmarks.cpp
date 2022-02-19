#include <string>
#include <sstream>
#include <boost/test/unit_test.hpp>

void performBookmarks(std::istream &in, std::ostream &out);

const std::string EMPTY = "<EMPTY>\n";
const std::string INVALID_BOOKMARK = "<INVALID BOOKMARK>\n";
const std::string INVALID_COMMAND = "<INVALID COMMAND>\n";
const std::string INVALID_STEP = "<INVALID STEP>\n";
const std::string EX_INVALID_COMMAND = "adding\n";

const std::string ADD_ME = "add 89373069777 \"Me\"\n";
const std::string ADD_MOTHER = "add 89373186888 \"\\\"Svaikina\\\"Olga\"\n";
const std::string ADD_FATHER = "add 89373093999 \"\\\"Svaikin\\\"Sergei\"\n";
const std::string ADD_FRIEND = "add 89374767800 \"\\\"Daniil\\\"Gindaev\"\n";
const std::string STORE_MARK_1 = "store current mark1\n";
const std::string STORE_MARK_2 = "store current mark2\n";
const std::string STORE_MARK_3 = "store current mark3\n";
const std::string SHOW_MARK_1 = "show mark1\n";
const std::string SHOW_MARK_2 = "show mark2\n";
const std::string SHOW_MARK_3 = "show mark3\n";
const std::string INSERT_BEFORE = "insert before mark1 89180053953 \"Lyka\"\n";
const std::string INSERT_AFTER = "insert after mark1 89185381739 \"Sasha\"\n";
const std::string MOVE_PLUS_ONE = "move mark1 1\n";
const std::string MOVE_MINUS_ONE = "move mark1 -1\n";
const std::string MOVE_TO_FIRST = "move mark1 first\n";
const std::string MOVE_TO_LAST = "move mark3 last\n";
const std::string DELETE = "delete mark1\n";

const std::string OUT_ME = "89373069777 Me\n";
const std::string OUT_MOTHER = "89373186888 \"Svaikina\"Olga\n";
const std::string OUT_FATHER = "89373093999 \"Svaikin\"Sergei\n";
const std::string OUT_FRIEND = "89374767800 \"Daniil\"Gindaev\n";
const std::string OUT_FRIEND_2 = "89180053953 Lyka\n";
const std::string OUT_FRIEND_3 = "89185381739 Sasha\n";

BOOST_AUTO_TEST_SUITE(bookmarkTest)

  BOOST_AUTO_TEST_CASE(testCommandAdd)
  {
    std::istringstream in(ADD_ME);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
  }

  BOOST_AUTO_TEST_CASE(testCommandAdd2)
  {
    std::istringstream in(ADD_MOTHER);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
  }

  BOOST_AUTO_TEST_CASE(testCommandAdd3)
  {
    std::istringstream in(ADD_FATHER);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
  }

  BOOST_AUTO_TEST_CASE(testStoreNoException)
  {
    std::istringstream in(STORE_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
  }

  BOOST_AUTO_TEST_CASE(testShow)
  {
    std::istringstream in(ADD_ME + STORE_MARK_1 + SHOW_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_ME);
  }

  BOOST_AUTO_TEST_CASE(testShow2)
  {
    std::istringstream in(ADD_MOTHER + STORE_MARK_2 + SHOW_MARK_2);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_MOTHER);
  }

  BOOST_AUTO_TEST_CASE(testShow3)
  {
    std::istringstream in(ADD_FATHER + STORE_MARK_3 + SHOW_MARK_3);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_FATHER);
  }

  BOOST_AUTO_TEST_CASE(testShow4)
  {
    std::istringstream in(ADD_FRIEND + STORE_MARK_3 + SHOW_MARK_3);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_FRIEND);
  }

  BOOST_AUTO_TEST_CASE(testInsertAfter)
  {
    std::istringstream in(ADD_ME + STORE_MARK_1 + INSERT_AFTER + MOVE_PLUS_ONE + SHOW_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_FRIEND_3);
  }

  BOOST_AUTO_TEST_CASE(testInserBefore)
  {
    std::istringstream in(ADD_ME + STORE_MARK_1 + INSERT_BEFORE + MOVE_MINUS_ONE + SHOW_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_FRIEND_2);
  }

  BOOST_AUTO_TEST_CASE(testDelete)
  {
    std::istringstream in(ADD_ME + STORE_MARK_1 + DELETE + SHOW_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), EMPTY);
  }

  BOOST_AUTO_TEST_CASE(testMoveToFirst)
  {
    std::istringstream in(ADD_ME + ADD_MOTHER + ADD_FATHER + ADD_FRIEND + STORE_MARK_1 + MOVE_TO_FIRST + SHOW_MARK_1);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_ME);
  }

  BOOST_AUTO_TEST_CASE(testMoveToLast)
  {
    std::istringstream in(ADD_ME + ADD_MOTHER + ADD_FATHER + ADD_FRIEND + STORE_MARK_3 + MOVE_TO_LAST + SHOW_MARK_3);
    std::ostringstream out;
    BOOST_CHECK_NO_THROW(performBookmarks(in, out));
    BOOST_CHECK_EQUAL(out.str(), OUT_FRIEND);
  }

BOOST_AUTO_TEST_SUITE_END()
