#include <string>
#include <asianrobot/core/Logger.h>
#include <date/date.h>
#include <date/tz.h>
#include <chrono>
#include "function.h"

lasts_fridays last_friday_of_month(const unsigned int &day_limit = 0) {

    using namespace date;
    using namespace std::chrono;

    lasts_fridays out;

    auto this_week = year_month_weekday{floor<days>(system_clock::now()) + days{day_limit}};

    year_month_day this_week_friday = {this_week.year() / this_week.month() / fri[this_week.index()]};
    year_month_day next_week_friday = {this_week.year() / this_week.month() / fri[this_week.index() + 1]};
    year_month_day quarter{};

    auto tmp_year = next_week_friday.year();
    auto tmp_month = next_week_friday.month();

    while (1) {
        if ((tmp_month == March) || (tmp_month == June) || (tmp_month == September) || (tmp_month == December)) {
            quarter = year_month_day{tmp_year / tmp_month / fri[last]};
            break;
        } else {
            tmp_month = ++month{tmp_month};
        }
    }

    out.next_week_friday = parsing_date(next_week_friday);
    out.this_week_friday = parsing_date(this_week_friday);
    out.quarter_friday = parsing_date(quarter);

    return out;
}
