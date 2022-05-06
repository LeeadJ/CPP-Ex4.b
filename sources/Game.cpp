#include "Game.hpp"

namespace coup{
    
    //Returns the name of the current players turn:
    std::string Game::turn() const{
        return this->players()[(unsigned int)this->getTurn()];
    }

    //Returns a vector of players currently in the game:
    std::vector<std::string> Game::players() const{
        return this->getPlayerNameVec();
    }

    //Returns the name of the winner. Throws Error if the game isn't over:
    std::string Game::winner() {
        if(this->getGameSize() != 1){
            throw std::runtime_error("Game Wnner Error: Game is not over.");
        }
        return this->players()[0];
    }

    //Adds a player to the game:
    void Game::addPlayer(const Player& p){
        this->getPlayersVec().push_back(p);
        this->getPlayerNameVec().push_back(p.getName());
    }

    //Updates the current turn:
    void Game::updateTurn(){
        this->_turn++;
    }

    // //Addes a player to the Coup Map:
    // void Game::addPlayer_coupMap(const Player& p){
    //     this->getPlayersCouped()[p.getName()] = p;
    // }

}