//
// Created by yuval on 6/18/22.
//

#include "League.hpp"

#include <utility>
#include <iostream>
#include <algorithm>

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
    this->_roster.resize(this->ROSTER_SIZE);
    for (size_t i = 0; i < this->ROSTER_SIZE; i++) {
        this->_roster.at(i) = pre_generated_roster.at(i);
    }
    this->_schedule = new Schedule();
    _schedule->update(this->_roster);
}

League::League(vector<Team *> roster) {
    this->_roster.resize(this->ROSTER_SIZE);
    if (roster.size() == this->ROSTER_SIZE) {
        this->_roster = std::move(roster);
        this->_schedule = new Schedule();
        _schedule->update(this->_roster);
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
    delete this->_schedule;
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
    for (long i = 0; i < this->getRoster().size(); i++) {
        if (this->getRoster().at(static_cast<size_t>(i)) == &team) {
            this->getRoster().erase(this->getRoster().begin() + i);
            return;
        }
    }
    throw std::invalid_argument("Team not found");
}

void League::printRoster() const {
    cout << "=========== LEAGUE ROSTER ===========" << endl;
    for (auto &i: this->getRoster()) {
        cout << i->getName() << std::endl;
    }
    cout << "=====================================" << endl;
}

void League::run_league() const {
    for(const Round& round: this->_schedule->rounds_sorted){
        for(Game game: round.game_list){
            game.play_game();
        }
    }
}

void League::printSchedule() const {
    cout << "=========== LEAGUE SCHEDULE ===========" << endl;
    for (Round &round: this->_schedule->rounds_sorted) {
        for (Game &game: round) {
            cout << game.get_home_team()->getName() << " vs " << game.get_away_team()->getName() << endl;
        }
    }
    cout << "=======================================" << endl;
}

/*
 *
 * THIS SECTION IS FOR SORTING AND STATISTICS FUNCTIONS
 *
 */

struct compare_by_points_for_against
{
    inline bool operator() (Team *team1, Team *team2)
    {
        return (team1->getPointsFor() - team1->getPointsAgainst() > team2->getPointsFor() - team2->getPointsAgainst());
    }
};

struct compare_by_wins
{
    inline bool operator() (Team *team1, Team *team2)
    {
        if(team1->getWins() == team2->getWins()) {
            return compare_by_points_for_against()(team1, team2);
        }
        return (team1->getWins() > team2->getWins());
    }
};

struct compare_by_points_average
{
    inline bool operator() (Team *team1, Team *team2)
    {
        return (team1->getPointsFor()/38 > team2->getPointsFor()/38);
    }
};



void League::printStandings() const {
    vector<Team *> sorted_teams = this->_roster;
    sort(sorted_teams.begin(), sorted_teams.end(), compare_by_wins());
    cout << "=========== FINAL LEAGUE STANDINGS BY WINS ===========" << endl;
    for(size_t i = 0; i < sorted_teams.size(); i++) {
        cout << i+1 << ". " << sorted_teams.at(i)->getName() << " " << sorted_teams.at(i)->getWins() << " wins" << endl;
    }
}

void League::printByPointRanking() const {
    vector<Team *> sorted_teams = this->_roster;
    sort(sorted_teams.begin(), sorted_teams.end(), compare_by_points_average());
    cout << "=========== FINAL LEAGUE BY POINT RANKING ===========" << endl;
    for(size_t i = 0; i < sorted_teams.size(); i++) {
        cout << i+1 << ". " << sorted_teams.at(i)->getName() << " " << sorted_teams.at(i)->getPointsFor()/38 << " points per game" << endl;
    }
}

int League::teams_positive_score_ratio() const {
    int positive_score_ratio = 0;
    for (Team *team: this->_roster) {
        if (team->getPointsFor()/team->getPointsAgainst() > 0) {
            positive_score_ratio++;
        }
    }
    cout << " No Of Teams Who Have A Positive Score Ratio: " << positive_score_ratio << endl;
    return positive_score_ratio;
}










