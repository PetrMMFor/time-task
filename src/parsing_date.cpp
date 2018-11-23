#include <date/date.h>
#include <boost/lexical_cast.hpp>
#include "function.h"


std::string parsing_date(date::year_month_day input_date){

    std::string tmp_str = boost::lexical_cast<std::string>(input_date);

    std::string month = tmp_str.substr(5,2);
    std::string day   = tmp_str.substr(8);

    return day + month;
}
