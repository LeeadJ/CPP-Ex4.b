#pragma once
#include "Player.hpp"
#include <stack>

namespace coup{
    class Captain : public Player{

        std::stack<Player*> _victimStealStack;

        public:
        //Getters:
        std::stack<Player*>& getVictimStealStack() {return this->_victimStealStack;}
        
        //Constructor:
        Captain(Game& game, const std::string& name);

        //Functions:
        //This function steals 2 coins from a different player.
        void steal(Player& p);

        //Blocks a different Captain from stealing 2 coins.
        void block(Captain& p);

        //Throws Error.
        void block(Player& p);

        //Increases the players coins by 1:
        void income();
        
        //Increases the players coins by 2:
        void foreign_aid();
    };
}