#include "Game.hpp"

namespace coup{
    //Constructor:
    Game::Game(){
        // this->setTurn();
        // this->setGameSize(0);
    }
    //Returns the name of the current players turn:
    std::string Game::turn() const{
        return this->getTurn().getName();
    }

    //Returns a vector of players currently in the game:
    std::vector<std::string> Game::players() const{
        std::vector<std::string> names;
        for(int i=0; i<this->getPlayersVec().size(); i++){
            if(this->getPlayersVec()[i].getEliminated() == false){
                names.push_back(this->getPlayersVec()[i].getName());
            }
        }
        return names;
    }

    //Returns the name of the winner. Throws Error if the game isn't over:
    std::string Game::winner() {
        int size=0;
        int winner=0;
        for(int i=0; i<this->getPlayersVec().size(); i++){
            if(this->getPlayersVec()[i].getEliminated()==false){
                size++;
                winner=i;
            }
        }
        if(size > 1){
            throw std::runtime_error("Game Winner() Error: Game is not over (More than 1 player remaining).");
        }
        if(size == 0){
            throw std::runtime_error("Game Winner() Error: No Players in the game. Game is empty.");
        }
        return this->players()[winner];
    }
}