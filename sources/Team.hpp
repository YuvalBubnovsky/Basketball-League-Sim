//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_TEAM_HPP
#define BASKETBALL_LEAGUE_SIM_TEAM_HPP

#include <string>
#include <memory>
#include <vector>

using namespace std;

// TODO: add winning & losing streak tracking possibly

namespace ex6 {
    class Team {
    private:
        string _name;
        double _skill;
        int _wins;
        int _losses;
        int _points_for;
        int _points_against;

    public:
        Team();

        Team(string name, double skill);

        ~Team() = default;

        string getName();

        double getSkill() const;

        bool operator==(const Team &other) const;

        int getWins() const;

        int getLosses() const;

        int getPointsFor() const;

        int getPointsAgainst() const;

        void setWins(int wins);

        void setLosses(int losses);

        void setPointsFor(int points_for);

        void setPointsAgainst(int points_against);
    };
}


#endif //BASKETBALL_LEAGUE_SIM_TEAM_HPP
