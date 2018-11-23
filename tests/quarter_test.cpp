#include <gtest/gtest.h>
#include <date/date.h>
#include <date/tz.h>
#include <boost/concept_check.hpp>
#include "../src/function.h"
#include "../src/lasts_fridays.cpp"
#include "../src/parsing_date.cpp"
#include "../src/foo.cpp"


struct TestSerialization : public testing::Test {

    std::string this_week_friday0 = "0308";
    std::string next_week_friday0 = "1008";
    std::string quarter_friday0 = "2809";

    std::string this_week_friday1 = "0709";
    std::string next_week_friday1 = "1409";
    std::string quarter_friday1 = "2809";

    std::string this_week_friday2 = "0510";
    std::string next_week_friday2 = "1210";
    std::string quarter_friday2 = "2812";

    std::string this_week_friday3 = "0401";
    std::string next_week_friday3 = "1101";
    std::string quarter_friday3 = "2903";

    std::string tmp = "2018-09-28T12:00:00Z";

};

TEST_F(TestSerialization, march_quarter0) {
    auto tmp = last_friday_of_month();
    ASSERT_EQ(tmp.this_week_friday,this_week_friday0);
    ASSERT_EQ(tmp.next_week_friday, next_week_friday0);
    ASSERT_EQ(tmp.quarter_friday,quarter_friday0);
}

TEST_F(TestSerialization, march_quarter1) {
    auto tmp = last_friday_of_month(31);
    ASSERT_EQ(tmp.this_week_friday,this_week_friday1);
    ASSERT_EQ(tmp.next_week_friday, next_week_friday1);
    ASSERT_EQ(tmp.quarter_friday,quarter_friday1);
}

TEST_F(TestSerialization, march_quarter2) {
    auto tmp = last_friday_of_month(31+28);
    ASSERT_EQ(tmp.this_week_friday,this_week_friday2);
    ASSERT_EQ(tmp.next_week_friday, next_week_friday2);
    ASSERT_EQ(tmp.quarter_friday,quarter_friday2);
}

TEST_F(TestSerialization, march_quarter3) {
    auto tmp = last_friday_of_month(31+28+31+30+31);
    ASSERT_EQ(tmp.this_week_friday,this_week_friday3);
    ASSERT_EQ(tmp.next_week_friday, next_week_friday3);
    ASSERT_EQ(tmp.quarter_friday,quarter_friday3);
}

TEST_F(TestSerialization, tmp) {
    foo(tmp);
}