//
// Created by yuval on 6/18/22.
//

#include "Game.hpp"

using std::rand;
using namespace ex6;

Game::Game(ex6::Team &homeTeam, ex6::Team &awayTeam) {
    this->homeTeam = new Team(homeTeam.getName(), homeTeam.getSkill());
    this->awayTeam = new Team(awayTeam.getName(), awayTeam.getSkill());
}

Game::~Game() {
    delete this->homeTeam;
    delete this->awayTeam;
}

int Game::get_home_team_score() const {
    return this->homeTeamScore;
}

int Game::get_away_team_score() const {
    return this->awayTeamScore;
}

void Game::set_home_team_score(int score) {
    this->homeTeamScore = score;
}

void Game::set_away_team_score(int score) {
    this->awayTeamScore = score;
}

void Game::play_game() {
    this->set_home_team_score(
            55 + (rand() % 45) + this->get_home_team()->getSkill() * 10); // will generate a number between 55 and 100
    this->get_home_team()->setPointsFor(this->get_home_team_score());
    this->get_away_team()->setPointsAgainst(this->get_home_team_score());
    this->set_away_team_score(
            50 + (rand() % 45) + this->get_away_team()->getSkill() * 10); // will generate a number between 50 and 100
    this->get_away_team()->setPointsFor(this->get_away_team_score());
    this->get_home_team()->setPointsAgainst(this->get_away_team_score());
}

Team *Game::get_winner() {
    if (this->get_home_team_score() == this->get_away_team_score()) {
        if (this->get_home_team()->getSkill() > this->get_away_team()->getSkill()) {
            this->get_home_team()->setWins(this->get_home_team()->getWins() + 1);
            this->get_away_team()->setLosses(this->get_away_team()->getLosses() + 1);
            return this->get_home_team();
        } else {
            this->get_away_team()->setWins(this->get_away_team()->getWins() + 1);
            this->get_home_team()->setLosses(this->get_home_team()->getLosses() + 1);
            return this->get_away_team();
        }
    }
    if (this->get_home_team_score() > this->get_away_team_score()) {
        this->get_home_team()->setWins(this->get_home_team()->getWins() + 1);
        this->get_away_team()->setLosses(this->get_away_team()->getLosses() + 1);
        return this->get_home_team();
    } else {
        this->get_away_team()->setWins(this->get_away_team()->getWins() + 1);
        this->get_home_team()->setLosses(this->get_home_team()->getLosses() + 1);
        return this->get_away_team();
    }
}

Team *Game::get_home_team() const {
    return this->homeTeam;
}

Team *Game::get_away_team() const {
    return this->awayTeam;
}


















