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
        list<Round> rounds_sorted;

        ~Schedule() {};

        list<Round>::iterator begin();

        list<Round>::iterator end();

    public:
        void update(vector<Team *> roster);

        Schedule() {}
    };
}


#endif //BASKETBALL_LEAGUE_SIM_SCHEDULE_HPP
