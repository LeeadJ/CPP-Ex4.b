#include "Ambassador.hpp"



namespace coup{
    //Constructor:
    Ambassador::Ambassador(const Game& game, const std::string& name) : Player(game, name){
        this->setRole("Ambassador");
    }
    
    //Functions:
    //Transfers a coin from one player to another.
    void Ambassador::transfer(Player& p1, Player& p2){
        if(&(this->getGame().getTurn()) != this){
            throw std::runtime_error("Ambassador transfer() Error: Not Ambassadors turn.");
        }
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), p1) == v.end()){
            throw std::runtime_error("Ambassador transfer() Error: Player 1 to transfer from not in the game.");
        }
        if(std::find(v.begin(), v.end(), p2) == v.end()){
            throw std::runtime_error("Ambassador transfer() Error: Player 2 to transfer to not in the game.");
        }
        if(p1.getCoins() < 1){
            throw std::runtime_error("Ambassador transfer() Error: Player 1 does not have enough coins to transfer.");
        }
        p1.setCoins(p1.getCoins()-1);
        p2.setCoins(p2.getCoins()+1);
        this->setPreviousTurn("transfer");
        this->updateGameTurn();
    }
    //Blocks the Captain from stealing 2 coins. Does not waste turn.
    void Ambassador::block(Captain& cap){
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), cap) == v.end()){
            throw std::runtime_error("Ambassador block() Error: Captain to block not in the game.");
        }
        if(cap.getPreviousTurn().compare("steal") != 0){
            throw std::runtime_error("Ambassador block() Error: Captain to block previous turn was not steal. Captain to block can not be blocked!");
        }
        if(cap.coins() < 2){
            throw std::runtime_error("Ambassador block() Error: Captain to be blocked doesn't have 2 coins to return.");
        }
        //Block can be made, undoing Block:
        //Removing the captains stolen coins.
        cap.setCoins(cap.coins()-2); 
        //Returning the stolen coins to the victim.
        cap.getVictimStealStack().top().setCoins(cap.getVictimStealStack().top().coins()+2); 
        //Removing the victim from the captains victimStealStack.
        cap.getVictimStealStack().pop(); 
        cap.setPreviousTurn("Steal was Blocked");
    }
}