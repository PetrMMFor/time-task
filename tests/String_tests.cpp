#include <gtest/gtest.h>
#include <date/date.h>
#include <boost/concept_check.hpp>
#include "../src/function.h"
#include "../src/contract_date.cpp"
#include <chrono>


struct TestSerializationTwo : public testing::Test {
    std::vector<std::string> input_str = {
            "contract2707",
            "",
            "1",
            "12",
            "123",
            "1234",
            "    ",
            "contract",
            "contract0007",
            "contract2700",
            "contract3607",
            "contract2715",
            "contract2801",
            "contract2807",
            "contract0108",
            "contract2607",
            "contract3007",
    };

    long valid_date_16 = std::chrono::microseconds{date::sys_days{
        date::year{2019}/
        date::month{7}/
        date::day{30}
    }.time_since_epoch()}.count();

    long valid_date_14 = std::chrono::microseconds{date::sys_days{
            date::year{2019}/
            date::month{8}/
            date::day{01}
    }.time_since_epoch()}.count();
};

TEST_F(TestSerializationTwo, testing_string16) {
    auto parcing_time = contract_date(input_str[16]);
    ASSERT_EQ(valid_date_16, parcing_time);
}

TEST_F(TestSerializationTwo, testing_string14) {
    auto parcing_time = contract_date(input_str[14]);
    ASSERT_EQ(valid_date_14, parcing_time);
}

TEST_F(TestSerializationTwo, assert_testing) {
    ASSERT_ANY_THROW(contract_date(input_str[1]));
    ASSERT_ANY_THROW(contract_date(input_str[2]));
    ASSERT_ANY_THROW(contract_date(input_str[3]));
    ASSERT_ANY_THROW(contract_date(input_str[4]));
    ASSERT_ANY_THROW(contract_date(input_str[5]));
    ASSERT_ANY_THROW(contract_date(input_str[6]));
    ASSERT_ANY_THROW(contract_date(input_str[7]));
    ASSERT_ANY_THROW(contract_date(input_str[8]));
    ASSERT_ANY_THROW(contract_date(input_str[9]));
    ASSERT_ANY_THROW(contract_date(input_str[10]));
    ASSERT_ANY_THROW(contract_date(input_str[11]));
}