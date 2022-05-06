#include "Captain.hpp"

namespace coup{
    //Constructor:
    Captain::Captain(const Game& game, const std::string& name) : Player(game, name){
        this->setRole("Captain");
    }

    //Functions:
    //This function steals 2 coins from a different player.
    void Captain::steal(Player& p){
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), p) == v.end()){
            throw std::runtime_error("Captain steal() Error: Player to steal not in the game.");
        }
        if(p.coins() < 2){
            throw std::runtime_error("Captain steal() Error: Victim does not enough coins.");
        }
        p.setCoins(p.coins()-2);
        this->setCoins(this->coins()+2);
        //Check if the victim stack is empty.
        //If not empty, previous steal can not be blocked.
        while(this->getVictimStealStack().size() != 0){
            this->getVictimStealStack().pop();
        }
        //add the new victim to the victim Steal stack:
        this->getVictimStealStack().push(p);
        this->setPreviousTurn("steal");
    }

    //Blocks a different Captain from stealing 2 coins. Does not waste turn.
    void Captain::block(Captain& cap){
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), cap) == v.end()){
            throw std::runtime_error("Captain block() Error: Different Captain to block not in the game.");
        }
        if(cap.getPreviousTurn().compare("steal") != 0){
            throw std::runtime_error("Captain block() Error: Captain to block previous turn was not steal. Captain to block can not be blocked!");
        }
        if(cap.coins() < 2){
            throw std::runtime_error("Captain block() Error: Captain to be blocked doesn't have 2 coins to return.");
        }
        //Block can be made, undoing Block:
        //Removing the other captains stolen coins.
        cap.setCoins(cap.coins()-2); 
        //Returning the stolen coins to the victim in the victimStealStack:
        cap.getVictimStealStack().top().setCoins(cap.getVictimStealStack().top().coins()+2); 
        //Removing the victim from the captains victimStealStack.
        cap.getVictimStealStack().pop();
        cap.setPreviousTurn("Blocked from steal");
    }
    
}