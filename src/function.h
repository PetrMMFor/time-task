#ifndef STRING_TO_TIME_FUNCTION_H
#define STRING_TO_TIME_FUNCTION_H


#include <date/date.h>
#include <vector>

struct lasts_fridays{

    std::string this_week_friday;
    std::string next_week_friday;
    std::string quarter_friday;
};

uint64_t contract_date(const std::string &input_str);

lasts_fridays last_friday_of_month(const unsigned int &day_limit);

std::string parsing_date(date::year_month_day input_date);

void foo(std::string in);


#endif //STRING_TO_TIME_FUNCTION_H
