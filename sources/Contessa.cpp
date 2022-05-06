#include "Contessa.hpp"

namespace coup{
    //Constructor:
    Contessa::Contessa(const Game& game, const std::string& name) : Player(game, name){
        this->setRole("Contessa");
    }

    //Functions:
    //Blocks the Assassin from assasinating. Does not waste trun. 
    void Contessa::block(Assassin& ass){
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), ass) == v.end()){
            throw std::runtime_error("Contessa block() Error: Assassin to block not in the game.");
        }
        if(ass.getPreviousTurn().compare("coup") != 0){
            throw std::runtime_error("Contessa block() Error: Assassins previous turn was not coup.");
        }
        //Block can be made, undoing coup:
        //Returning the victim to the game. 
        ass.getVictimStack().top().setEliminated(false);
        //Removing the victim from the victim stack:
        ass.getVictimStack().pop(); 
        ass.setPreviousTurn("Blocked from coup");
    }
}