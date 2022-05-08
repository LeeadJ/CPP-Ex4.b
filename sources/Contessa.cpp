#include "Contessa.hpp"

namespace coup{
    //Constructor:
    Contessa::Contessa(Game& game, const std::string& name) : Player(game, name){
        this->setRole("Contessa");
    }

    //Functions:
    //Blocks the Assassin from assasinating. Does not waste trun. 
    void Contessa::block(Assassin& ass){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Contessa block() Error: Player is eliminated, can't use block().");
        }
        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &ass) == dq.end()){
            throw std::runtime_error("Contessa block() Error: Assassin to block not in the game.");
        }
        if(ass.getPreviousTurn()!="coup"){
            throw std::runtime_error("Contessa block() Error: Assassins previous turn was not coup.");
        }
        //Block can be made, undoing coup:
        //Returning the victim to the game. 
        ass.getVictimStack().top()->setEliminated(false);
        ass.setPreviousTurn("Blocked from coup");
        
        //Checking the correct turn:
        
        Player* v = ass.getVictimStack().top();
        Player* back = this->getGame()->getPlayerDQ().back();
        Player* front = this->getGame()->getPlayerDQ().front();
        //If the victim is at the end of the playerDQ  when block was made, return the victim to the game, and set turn to him:
        if(v == back){
            // std::cout<<"Reached victim at end of DQ"<<std::endl;
            //Returning the victim to the front of plaerDQ:
            this->getGame()->getPlayerDQ().pop_back();
            this->getGame()->getPlayerDQ().push_front(ass.getVictimStack().top());
            //Removing the victim from the victim stack:
            ass.getVictimStack().pop();
            return; 
            }
        //If the current turn is the assassins at the time the block was made, there has to be a player that played:
        if(&ass == front){
            return;
        }
        //Back of playerDQ is not victim and the current turn is not the assassins, loop through the playerDQ in reversed order:
        for(auto it = dq.rbegin(); it != dq.rend(); ++it){
            //If the temp player already played, victim lost his turn:
            if((*it)->getPlayed()){
                return;
            }
            //If we reached the victim, then no player after him played, return the victim to the game, and set turn to him:
            if((*it)==v){
                // std::cout<<"Reached iter victim loop"<<std::endl;
                //Returning the victim to the front of plaerDQ:
                this->getGame()->getPlayerDQ().pop_back();
                this->getGame()->getPlayerDQ().push_front(ass.getVictimStack().top());
                //Removing the victim from the victim stack:
                ass.getVictimStack().pop();
                return; 
            }
            // std::cout<<"Iter: "<<(*it)->getName()<<std::endl;
            // std::cout<<"Reached 1"<<std::endl;
            

        }
    }

    //Throws Error.
    void Contessa::block(Player& p){
        if(p.getRole()!="Assasin"){
            throw std::runtime_error("Contessa Block() Error: Contessa can only block Assassin.");
        }
    }
}