//
// Created by yuval on 6/18/22.
//

#include "Team.hpp"

#include <utility>

using namespace std;
using namespace ex6;

Team::Team(string name, double skill) {
    this->_name = move(name);
    this->_skill = skill;
}

Team::Team() {
    this->_name = "";
    this->_skill = 0;
}

string Team::getName() {
    return this->_name;
}

double Team::getSkill() const {
    return this->_skill;
}

bool Team::operator==(const Team &other) const {
    bool equal = this->_name == other._name;
    return equal;
}

int Team::getWins() {
    return this->_wins;
}

int Team::getLosses() {
    return this->_losses;
}

int Team::getPointsFor() {
    return this->_points_for;
}

int Team::getPointsAgainst() {
    return this->_points_against;
}

void Team::setWins(int wins) {
    this->_wins = wins;
}

void Team::setLosses(int losses) {
    this->_losses = losses;
}

void Team::setPointsFor(int points_for) {
    this->_points_for = points_for;
}

void Team::setPointsAgainst(int points_against) {
    this->_points_against = points_against;
}
