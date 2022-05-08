#include "Ambassador.hpp"



namespace coup{
    //Constructor:
    Ambassador::Ambassador(Game& game, const std::string& name) : Player(game, name){
        this->setRole("Ambassador");
    }
    
    //Functions:
    //Transfers a coin from one player to another.
    void Ambassador::transfer(Player& p1, Player& p2){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Ambassador transfer() Error: Player is eliminated, can't use transfer().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Ambassador transfer() Error: Not Ambassadors turn.");
        }
        if(&p1 == this || &p2 == this){
            throw std::runtime_error("Ambassador transfer() Error: Can't transfer to self.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Ambassador transfer() Error: More than 10 coins, must do coup().");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &p1) == dq.end()){
            throw std::runtime_error("Ambassador transfer() Error: Player 1 to transfer from not in the game.");
        }
        if(std::find(dq.begin(), dq.end(), &p2) == dq.end()){
            throw std::runtime_error("Ambassador transfer() Error: Player 2 to transfer to not in the game.");
        }
        if(p1.getCoins() < 1){
            throw std::runtime_error("Ambassador transfer() Error: Player 1 does not have enough coins to transfer.");
        }
        this->getGame()->setStart(true);
        p1.setCoins(p1.getCoins()-1);
        p2.setCoins(p2.getCoins()+1);
        this->setPreviousTurn("transfer");
        this->updateGameTurn();
    }
    //Blocks the Captain from stealing 2 coins. Does not waste turn.
    void Ambassador::block(Captain& cap){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Ambassador block() Error: Player is eliminated, can't use block().");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &cap) == dq.end()){
            throw std::runtime_error("Ambassador block() Error: Captain to block not in the game.");
        }
        if(cap.getPreviousTurn()!="steal"){
            throw std::runtime_error("Ambassador block() Error: Captain to block previous turn was not steal. Captain to block can not be blocked!");
        }
        if(cap.coins() < 2){
            throw std::runtime_error("Ambassador block() Error: Captain to be blocked doesn't have 2 coins to return.");
        }
        //Block can be made, undoing Block:
        //Removing the captains stolen coins.
        this->getGame()->setStart(true);
        cap.setCoins(cap.coins()-2); 
        //Returning the stolen coins to the victim.
        cap.getVictimStealStack().top()->setCoins(cap.getVictimStealStack().top()->coins()+2); 
        //Removing the victim from the captains victimStealStack.
        cap.getVictimStealStack().pop(); 
        cap.setPreviousTurn("Blocked from Steal");
    }

    //Throws Error.
    void Ambassador::block(Player& p){
        if(p.getRole()!="Captain"){
            throw std::runtime_error("Ambassador Block() Error: Ambassador can only block other captain.");
        }
    }
}