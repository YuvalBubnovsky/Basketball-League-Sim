//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_SCHEDULE_HPP
#define BASKETBALL_LEAGUE_SIM_SCHEDULE_HPP

#include <iostream>
#include "League.hpp"
#include "Round.hpp"

namespace ex6 {
    class Schedule {
    public:
        list<Round> rounds_sorted;

        list<Round>::iterator begin();

        list<Round>::iterator end();


        void update(vector<Team *> &roster);

        Schedule() {}
        ~Schedule() {};

    };
}


#endif //BASKETBALL_LEAGUE_SIM_SCHEDULE_HPP
