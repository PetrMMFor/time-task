#include "../src/function.h"
#include <boost/date_time.hpp>

void foo(std::string in){

    using namespace date;
    using namespace std::chrono;

    system_clock::time_point time;
    std::istringstream string_time{"2018-09-28T12:00:00.000Z"};

    string_time >> parse("%FT%H:%M:%SZ",time);

    std::cout << "\n" << time << std::endl;
}

