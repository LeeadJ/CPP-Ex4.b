#include "Game.hpp"

namespace coup{
    
    //Returns the name of the current players turn:
    std::string Game::turn() const{
        return this->getTurn();
    }

    //Returns a vector of players currently in the game:
    std::vector<std::string> Game::players() const{
        return this->getPlayerNameVec();
    }

    //Returns the name of the winner. Throws Error if the game isn't over:
    std::string Game::winner() {
        if(this->getGameSize() > 1){
            throw std::runtime_error("Game Winner() Error: Game is not over.");
        }
        if(this->getGameSize() == 0){
            throw std::runtime_error("Game Winner() Error: No Players in the game. Game is empty.");
        }
        return this->players()[0];
    }

    // //Adds a player to the game:
    // void Game::addPlayer(const Player& p){
    //     this->getPlayersVec().push_back(p);
    //     this->getPlayerNameVec().push_back(p.getName());
    //     this->players().push_back(p.getName());
    // }

    // //Addes a player to the Coup Map:
    // void Game::addPlayer_coupMap(const Player& p){
    //     this->getPlayersCouped()[p.getName()] = p;
    // }

}