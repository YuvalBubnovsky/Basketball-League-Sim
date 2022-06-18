//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_ROUND_HPP
#define BASKETBALL_LEAGUE_SIM_ROUND_HPP

#include <list>
#include "Game.hpp"
#include "League.hpp"

namespace ex6 {
    class Round {
    public:
        Round() = default;

        ~Round() = default;

        list<Game> game_list;

        list<Game>::iterator begin() {
            return game_list.begin();
        }

        list<Game>::iterator end() {
            return game_list.end();
        }
    };
}


#endif //BASKETBALL_LEAGUE_SIM_ROUND_HPP
