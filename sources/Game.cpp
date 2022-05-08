#include "Game.hpp"

namespace coup{
    //Constructor:
    Game::Game(){
        this->setGameStatus(false);
        // this->setGameName(name);
    }

    //Returns the name of the current players turn:
    std::string Game::turn() {
        if(this->getGameStatus()==false){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getPlayerDQ().size()==0){
            throw std::runtime_error("Game turn() Error: No players in Game.");
        }
        return this->getTurn().getName();
    }

    //Returns a vector of players currently in the game:
    std::vector<std::string> Game::players() {
        //Looping through the playersVec: Add to names vector only playrs who are not eliminated in the correct order:
        std::vector<std::string> names;
        for(Player* p : this->getPlayersVec()){
            if(p->getEliminated() == false){
                names.push_back(p->getName());
            }
        }
        //If the Game is empty or all players eliminated, throw Error:
        if(names.empty()){
            throw std::runtime_error("Game players() Error: No players in Game.");
        }
        return names;
    }
    

    //Returns the name of the winner. Throws Error if the game isn't over:
    std::string Game::winner() {
        if(this->getGameStatus()==false){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getPlayerDQ().empty()){
            throw std::runtime_error("Game Winner() Error: No Players in the game. Game is empty.");
        }
        int size=0;
        Player* temp = this->getPlayerDQ().front();
        for(Player* p : this->getPlayerDQ()){
            if(p->getEliminated() == false){
                size++;
                temp = p;
            }
        }
        if(size == 0){
            throw std::runtime_error("Game Winner() Error: All Players were eliminated (Can't happen?).");
        }
        if(size > 1){
            throw std::runtime_error("Game Winner() Error: Game is not over (More than 1 player remaining).");
        }
        //If reached here there is only 1 player remaining (being pointed currently by temp):
        this->setWinner(*temp);
        return this->getWinner().getName();
    }
}