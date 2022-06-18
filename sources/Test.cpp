//
// Created by yuval on 6/18/22.
//

#include "doctest.h"
#include <string>
#include <iostream>
#include <vector>
#include "Game.hpp"
#include "Team.hpp"
#include "League.hpp"
#include "Round.hpp"
#include "Schedule.hpp"
using namespace std;
using namespace ex6;

TEST_CASE("Running The League"){
    auto* league = new League();
    CHECK_NOTHROW(league->run_league());
    CHECK_NOTHROW(league->printRoster());
    CHECK_NOTHROW(league->printSchedule());
    CHECK_NOTHROW(league->printStandings());
    CHECK_NOTHROW(league->printByPointRanking());
    CHECK_NOTHROW(league->teams_positive_score_ratio());
    for(auto& team : league->getRoster()) {
        CHECK_NOTHROW(team->getWins());
        CHECK_NOTHROW(team->getLosses());
        CHECK_NOTHROW(team->getPointsFor());
        CHECK_NOTHROW(team->getPointsAgainst());
    }
    for(auto& round : *league->_schedule) {
        for(auto& game : round.game_list) {
            CHECK_NOTHROW(game.get_home_team_score());
            CHECK_NOTHROW(game.get_away_team_score());
            CHECK_NOTHROW(game.get_home_team());
            CHECK_NOTHROW(game.get_away_team());
        }
    }
}