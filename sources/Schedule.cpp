//
// Created by yuval on 6/18/22.
//

#include "Schedule.hpp"

#include <utility>
#include "Round.hpp"

using namespace ex6;

constexpr size_t ROSTER_SIZE = 20;

list<Round> round_robin_algo(vector<Team *> &roster) {
    /*
    * round-robin algorithm to scheduale the league, wikipedia page:
    * https://en.wikipedia.org/wiki/Round-robin_tournament#Scheduling_algorithm
    * Also, thanks to Amir Sabag for helping with this algorithm
    */

    list<Round> result_rounds_to_return;
    vector<size_t> ordered_roster_per_round(ROSTER_SIZE);
    for (size_t num = 0; num < ROSTER_SIZE; num++) {
        ordered_roster_per_round.at(num) = num;
    }

    for (size_t i = 0; i < ROSTER_SIZE - 1; i++) {
        Round round;
        for (size_t j = 0; j < ROSTER_SIZE / 2; j++) {
            round.game_list.emplace_back(*(roster.at(ordered_roster_per_round.at(j))),
                                         *(roster.at(ordered_roster_per_round.at(ROSTER_SIZE - 1 - j))));
            round.game_list.emplace_back(*(roster.at(ordered_roster_per_round.at(ROSTER_SIZE - 1 - j))),
                                         *(roster.at(ordered_roster_per_round.at(j))));
        }

        size_t last = ordered_roster_per_round.at(ordered_roster_per_round.size() - 1);
        for (size_t j = ordered_roster_per_round.size() - 1; j >= 2; j--) {
            ordered_roster_per_round.at(j) = ordered_roster_per_round.at(j - 1);
        }
        ordered_roster_per_round.at(1) = last;
        result_rounds_to_return.push_back(round);
    }

    return result_rounds_to_return;

}

void Schedule::update(vector<Team *> &roster) {
    this->rounds_sorted = round_robin_algo(roster);
}

list<Round>::iterator Schedule::begin() {
    return this->rounds_sorted.begin();
}

list<Round>::iterator Schedule::end() {
    return this->rounds_sorted.end();
}

