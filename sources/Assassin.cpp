#include "Assassin.hpp"

namespace coup{
    //Constructor
    Assassin::Assassin(const Game& game, const std::string& name) : Player(game, name){
        this->setRole("Assassin");
    }

    //Function
    //Eliminates a Player from the Game:
    // void Assassin::coup(Player& p){
    //     const std::vector<Player>& v = this->getGame().getPlayersVec(); 
    //     if(std::find(v.begin(), v.end(), p) == v.end()){
    //         throw std::runtime_error("Assassin coup() Error: Player to coup not in the game.");
    //     }
    //     if(this->coins() < 3){
    //         throw std::runtime_error("Assassin coup() Error: Not enough coins to use coup().");
    //     }
    //     //Removing the Player from the game:
    //     for(int i=0; i<this->getGame().getGameSize(); i++){
    //         if(&(this->getGame().getPlayersVec()[i]) == &p){
    //             //Erasing the victims name from the game PlayernameVec:
    //             this->getGame().getPlayerNameVec().erase(this->getGame().getPlayerNameVec().begin()+i); 
    //             //Erasing the victims name from the game playersVec:
    //             this->getGame().getPlayersVec().erase(this->getGame().getPlayersVec().begin()+i); 
    //             break;
    //         }
    //     } 
    //     //Check if the victim stack is empty:
    //     while(this->getVictimStack().size() != 0){
    //         this->getVictimStack().pop();
    //     }
    //     //add the victim to the victim stack:
    //     this->getVictimStack().push(p);
    //     //cost of the assassination: 3 coins:
    //     this->setCoins(this->coins()-3);
    //     this->setPreviousTurn("coup");
    // }
}