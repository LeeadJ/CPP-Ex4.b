#include "Assassin.hpp"

namespace coup{
    //Constructor
    Assassin::Assassin(Game& game, const std::string& name) : Player(game, name){
        this->setRole("Assassin");
    }

    //Function
    //Increases the players coins by 1:
    void Assassin::income(){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Assassin income() Error: Player is eliminated, can't use income().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Assassin income() Error: Not Players turn.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Assassin income() Error: Player has 10 coins, must do coup().");
        }
        this->setCoins(this->coins()+1);
        this->setPreviousTurn("income");
        //If victimStack is not empty when usung income(), victim is permanently eliminated:
        while(!this->getVictimStack().empty()){
            this->getVictimStack().pop();
        }
        this->updateGameTurn();
    }
    
    //Increases the players coins by 2:
    void Assassin::foreign_aid(){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Assassin foreign_aid() Error: Player is eliminated, can't use foreign_aid().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Assassin foreign_aid() Error: Not Players turn.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Assassin foreign_aid() Error: More than 10 coins, must do coup().");
        }
        this->setCoins(this->coins()+2);
        this->setPreviousTurn("foreign_aid");
        //If victimStack is not empty when usung foreign_aid(), victim is permanently eliminated:
        while(!this->getVictimStack().empty()){
            this->getVictimStack().pop();
        }
        this->updateGameTurn();

    }

    // Eliminates a Player from the Game:
    void Assassin::coup(Player& p){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Assassin coup() Error: Player is eliminated, can't use coup().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Assassin coup() Error: Not Assassins turn.");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &p) == dq.end()){
            throw std::runtime_error("Assassin coup() Error: Player to coup not in the game.");
        }
        if(p.getEliminated()){
            throw std::runtime_error("Assassin coup() Error: Player already eliminated");
        }
        if(this->coins() < ASS_COINS){
            throw std::runtime_error("Assassin coup() Error: Not enough coins to use coup().");
        }
        //If Assassin has more than 7 coins he can eliminate without being blocked:
        if(this->coins() >= PLAYER_COINS){
            this->Player::coup(p);
        }
        else{
            //If reached here, Player will be eliminated with option of being blocked:
            p.setEliminated(true);
            
            //Check if the victim stack is empty.
            //If victimStack is not empty when usung coup(), victim is permanently eliminated:
            while(!this->getVictimStack().empty()){
                this->getVictimStack().pop();
            }
            //add the curret victim to the victim stack:
            this->getVictimStack().push(&p);
            // this->setVictim(p);
            //cost of the assassination: 3 coins:
            this->setCoins(this->coins()-ASS_COINS);
            this->setPreviousTurn("coup3");
            this->updateGameTurn();
        }
        
    }
}