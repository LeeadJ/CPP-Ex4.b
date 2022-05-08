#include "Assassin.hpp"

namespace coup{
    //Constructor
    Assassin::Assassin(Game& game, const std::string& name) : Player(game, name){
        this->setRole("Assassin");
    }

    //Function
    // Eliminates a Player from the Game:
    void Assassin::coup(Player& p){
        if(this->getGame()->getGameStatus()==false){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated() == true){
            throw std::runtime_error("Assassin coup() Error: Player is eliminated, can't use coup().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Assassin coup() Error: Not Assassins turn.");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &p) == dq.end()){
            throw std::runtime_error("Assassin coup() Error: Player to coup not in the game.");
        }
        if(p.getEliminated()==true){
            throw std::runtime_error("Assassin coup() Error: Player already eliminated");
        }
        if(this->coins() < 3){
            throw std::runtime_error("Assassin coup() Error: Not enough coins to use coup().");
        }
        //If reached here, Player can be eliminated:
        p.setEliminated(true);
        
        //Check if the victim stack is empty.
        //If not empty, previous victim to be couped can not return to the game:
        while(this->getVictimStack().size() != 0){
            this->getVictimStack().pop();
        }
        //add the curret victim to the victim stack:
        this->getVictimStack().push(&p);

        //cost of the assassination: 3 coins:
        this->setCoins(this->coins()-3);
        this->setPreviousTurn("coup");
        this->updateGameTurn();
    }
}