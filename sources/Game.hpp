//
// Created by yuval on 6/18/22.
//

#ifndef BASKETBALL_LEAGUE_SIM_GAME_HPP
#define BASKETBALL_LEAGUE_SIM_GAME_HPP

#include "Team.hpp"

namespace ex6 {
    class Game {
    private:
        int homeTeamScore;
        int awayTeamScore;
    public:
        Team *homeTeam;
        Team *awayTeam;

        Game(Team &homeTeam, Team &awayTeam);

        ~Game();

        void play_game();

        Team *get_winner();

        Team *get_home_team() const;

        Team *get_away_team() const;

        int get_home_team_score() const;

        int get_away_team_score() const;

        void set_home_team_score(int score);

        void set_away_team_score(int score);
    };
}


#endif //BASKETBALL_LEAGUE_SIM_GAME_HPP
