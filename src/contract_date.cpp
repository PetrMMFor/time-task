#include <string>
#include <date/date.h>
#include <date/tz.h>
#include "function.h"

uint64_t contract_date(const std::string &input_str) {

    if(input_str.empty() || input_str.size() < 4){
        throw std::runtime_error("bad input string");
    }

    size_t start_point = input_str.size() - 4;

    auto input_day = boost::lexical_cast<unsigned int>(input_str.substr(input_str.size() - 4, 2));
    auto input_month = boost::lexical_cast<unsigned int>(input_str.substr(input_str.size() - 2, 2));

    if(01 > input_day || input_day > 31){
        throw std::runtime_error("bad date value in the string");
    }
    if(01 > input_month || input_month > 12){
        throw std::runtime_error("bad month value in the string");
    }

    using namespace date;
    using namespace std::chrono;

    auto tm = make_zoned(date::current_zone(),system_clock::now());
    auto now_year_month_day = year_month_day{floor<days>(tm.get_local_time())};

    const auto hours_9 = 9h;

    auto now_time = make_time(tm.get_local_time() - floor<days>(tm.get_local_time()));

    auto hour = now_time.hours();
    sys_days out_time;
    if (now_year_month_day.month() > month{input_month}) {
        out_time = sys_days{
                ++year{now_year_month_day.year()}
                / month{input_month}
                / day{input_day}
        };
    } else if (now_year_month_day.month() < month{input_month}) {
        out_time = sys_days{
                year{now_year_month_day.year()}
                / month{input_month}
                / day{input_day}
        };
    } else {
        if (now_year_month_day.day() > day{input_day}) {
            out_time = sys_days{
                    ++year{now_year_month_day.year()}
                    / month{input_month}
                    / day{input_day}
            };
        } else if (now_year_month_day.day() < day{input_day}) {
            out_time = sys_days{
                    year{now_year_month_day.year()}
                    / month{input_month}
                    / day{input_day}
            };
        } else {
            if (hour >= hours_9) {
                out_time = sys_days{
                        year{++now_year_month_day.year()}
                        / month{input_month}
                        / day{input_day}
                };
            } else {
                out_time = sys_days{
                        year{now_year_month_day.year()}
                        / month{input_month}
                        / day{input_day}
                };
            }
        }
    }
    return microseconds{(out_time + hours_9).time_since_epoch()}.count();
}
