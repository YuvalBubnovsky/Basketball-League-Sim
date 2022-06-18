//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_LEAGUE_HPP
#define BASKETBALL_LEAGUE_SIM_LEAGUE_HPP

#include "Schedule.hpp"
#include "Team.hpp"
#include <vector>

namespace ex6 {
    class Schedule;
    class League {
    public:
        vector<Team *> _roster;
        Schedule* _schedule;
        const int ROSTER_SIZE = 20;

        League();

        League(vector<Team *> roster);

        League(const League &other);

        League &operator=(const League &other);

        ~League();

        vector<Team *> getRoster() const;

        void addTeam(Team &team) const;

        void removeTeam(Team &team) const;

        void printRoster() const;

        void printSchedule() const;

        void run_league() const;

        void printStandings() const;

        bool comapre_by_wins(Team *team1, Team *team2);

        void printByPointRanking() const;

        int teams_positive_score_ratio() const;
    };
}


#endif //BASKETBALL_LEAGUE_SIM_LEAGUE_HPP
