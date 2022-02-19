#include <sstream>
#include <cstddef>
#include <string>
#include <boost/test/unit_test.hpp>

#include "DataStruct.hpp"

const DataStruct CORRECT_DATA_1 = {1, -1, "Counter Strike Global Offensive"};
const DataStruct CORRECT_DATA_2 = {2, -2, "Delivery club"};
const DataStruct CORRECT_DATA_3 = {3, -3, "Alpen Gold"};
const DataStruct CORRECT_DATA_4 = {4, -4, "Minecraft"};

const std::string CORRECT_DATA_1_STRING = "1, -1, Counter Strike Global Offensive";
const std::string CORRECT_DATA_2_STRING = "2, -2, Delivery club";
const std::string CORRECT_DATA_3_STRING = "3, -3, Alpen Gold";
const std::string CORRECT_DATA_4_STRING = "4, -4, Minecraft";

const std::size_t SIZE = 4;
const std::string VECTOR_OF_DATA_IN[4] = {CORRECT_DATA_1_STRING, CORRECT_DATA_2_STRING, CORRECT_DATA_3_STRING,
                                          CORRECT_DATA_4_STRING};

const DataStruct VECTOR_OF_DATA_OUT[4] = {CORRECT_DATA_1, CORRECT_DATA_2, CORRECT_DATA_3,
                                          CORRECT_DATA_4};

const std::string BAD_DATA_1 = "-10, -10, inputString";
const std::string BAD_DATA_2 = "10, 10, inputString";
const std::string BAD_DATA_3 = "q, q, q";
const std::string BAD_DATA_4 = "q, q,";
const std::string BAD_DATA_5 = "";

const std::string BAD_INPUT[5] = {BAD_DATA_1, BAD_DATA_2, BAD_DATA_3, BAD_DATA_4, BAD_DATA_5};

BOOST_AUTO_TEST_SUITE(CorrectDataStructTest)

  BOOST_AUTO_TEST_CASE(compareLessTest)
  {
    BOOST_CHECK(CORRECT_DATA_1 < CORRECT_DATA_2);
  }

  BOOST_AUTO_TEST_CASE(compareMoreTest)
  {
    BOOST_CHECK(!(CORRECT_DATA_4 < CORRECT_DATA_3));
  }

  BOOST_AUTO_TEST_CASE(correctInputTest)
  {
    for (size_t i = 0; i < SIZE; i++)
    {
      std::istringstream in(VECTOR_OF_DATA_IN[i]);
      DataStruct data = {0, 0, ""};
      in >> data;
      BOOST_CHECK(data.key1 == VECTOR_OF_DATA_OUT[i].key1);
      BOOST_CHECK(data.key2 == VECTOR_OF_DATA_OUT[i].key2);
      BOOST_CHECK(data.str == VECTOR_OF_DATA_OUT[i].str);
    }
  }

  BOOST_AUTO_TEST_CASE(incorrectInputTest)
  {
    for (std::size_t i = 0; i < SIZE; i++)
    {
      std::istringstream in(BAD_INPUT[i]);
      DataStruct dataStruct = {0, 0, ""};
      in >> dataStruct;
      BOOST_CHECK(in.fail());
    }
  }

BOOST_AUTO_TEST_SUITE_END()
