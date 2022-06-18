//
// Created by yuval on 6/18/22.
//

#include "League.hpp"

#include <utility>
#include <iostream>

using namespace ex6;

const vector<Team *> pre_generated_roster = {
        new Team("Boston Celtics", 0.5),
        new Team("Los Angeles Lakers", 0.6),
        new Team("Miami Heat", 0.7),
        new Team("Oklahoma Thunder", 0.8),
        new Team("Milwaukee Bucks", 0.9),
        new Team("Golden State Warriors", 1.0),
        new Team("Indiana Pacers", 0.1),
        new Team("Atlanta Hawks", 0.2),
        new Team("San Antonio Spurs", 0.3),
        new Team("Cleveland Cavaliers", 0.4),
        new Team("Los Angeles Clippers", 0.5),
        new Team("Dallas Mavericks", 0.6),
        new Team("Memphis Grizzlies", 0.7),
        new Team("New Jersey Nets", 0.8),
        new Team("Chicago Bulls", 0.9),
        new Team("Toronto Raptors", 1.0),
        new Team("Detroit Pistons", 0.1),
        new Team("Charlotte Hornets", 0.2),
        new Team("Orlando Magic", 0.3),
        new Team("Washington Wizards", 0.4)
};

League::League() {
    this->getRoster().resize(this->ROSTER_SIZE);
    for (size_t i = 0; i < this->ROSTER_SIZE; i++) {
        this->getRoster().at(i) = pre_generated_roster.at(i);
    }
    _schedule.update(this->getRoster());
}

League::League(vector<Team *> roster) {
    this->getRoster().resize(this->ROSTER_SIZE);
    if (roster.size() == this->ROSTER_SIZE) {
        this->getRoster() = std::move(roster);
        _schedule.update(this->getRoster());
    } else {
        throw std::invalid_argument("Invalid roster size, must be 20");
    }
}

League::League(const League &other) {
    this->getRoster().resize(this->ROSTER_SIZE);
    for (size_t i = 0; i < this->ROSTER_SIZE; i++) {
        this->getRoster().at(i) = other._roster.at(i);
    }
}

League &League::operator=(const League &other) {
    this->getRoster().resize(this->ROSTER_SIZE);
    for (size_t i = 0; i < this->ROSTER_SIZE; i++) {
        this->getRoster().at(i) = other._roster.at(i);
    }
    return *this;
}

League::~League() {
    for (auto &i: this->_roster) {
        delete i;
    }
    for (auto i: pre_generated_roster) {
        delete i;
    }
}

vector<Team *> League::getRoster() const {
    return this->_roster;
}

void League::addTeam(Team &team) const {
    if (this->getRoster().size() < this->ROSTER_SIZE) {
        this->getRoster().push_back(&team);
    } else {
        throw std::invalid_argument("Roster is full");
    }
}

void League::removeTeam(Team &team) const {
    for (size_t i = 0; i < this->getRoster().size(); i++) {
        if (this->getRoster().at(i) == &team) {
            this->getRoster().erase(this->getRoster().begin() + i);
            return;
        }
    }
    throw std::invalid_argument("Team not found");
}

void League::printRoster() const {
    for (auto &i: this->getRoster()) {
        cout << i->getName() << std::endl;
    }

}

void League::run_league() {
    for (Round &round: this->_schedule) {
        for (Game &game: round) {
            game.play_game();
        }
    }
}
void League::printSchedule() {
    for (Round &round: this->_schedule) {
        for (Game &game: round) {
            cout << game.get_home_team()->getName() << " vs " << game.get_away_team()->getName() << endl;
        }
    }
}








