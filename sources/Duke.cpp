#include "Duke.hpp"

namespace coup{
    //Constructor:
    Duke::Duke(Game& game, const std::string& name) : Player(game, name){
        this->setRole("Duke");
    }

    //Functions:
    //Takes tax of 3 coins from the pile.
    void Duke::tax(){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Duke tax() Error: Player is eliminated, can't use tax().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Duke tax() Error: Not Dukes turn.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Duke tax() Error: More than 10 coins, must do coup().");
        }
        this->setCoins(this->coins()+3);
        this->updateGameTurn();
    }
    //Blocks a player from taking 2 coins (using foreign_aid)
    void Duke::block(Player& p){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &p) == dq.end()){
            throw std::runtime_error("Duke block() Error: Player to block not in the game.");
        }
        if(p.getPreviousTurn()=="foreign_aid"){
            throw std::runtime_error("Duke block() Error: Players previous turn was not foreign_aid(). Player can not be blocked!");
        }
        if(p.coins() < 2){
            throw std::runtime_error("Duke block() Error: Player to be blocked doesn't have 2 coins to return.");
        }
        p.setCoins(p.coins()-2);
        p.setPreviousTurn("Blocked from foreign_aid");
    }
}