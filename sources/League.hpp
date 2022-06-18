//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_LEAGUE_HPP
#define BASKETBALL_LEAGUE_SIM_LEAGUE_HPP

#include "Team.hpp"
#include "Schedule.hpp"
#include <vector>

namespace ex6 {
    class League {
    public:
        vector<Team*> _roster;
        Schedule _schedule{};
        const int ROSTER_SIZE = 20;

        League();
        League(vector<Team*> roster);
        League(const League &other);
        League& operator=(const League &other);
        ~League();

        void addTeam(Team& team);
        void removeTeam(Team& team);
        void printRoster();
        void printSchedule();

    };
}


#endif //BASKETBALL_LEAGUE_SIM_LEAGUE_HPP
