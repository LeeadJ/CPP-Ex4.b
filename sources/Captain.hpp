#pragma once
#include "Player.hpp"
#include <stack>

namespace coup{
    class Captain : public Player{

        std::stack<Player> _victimStealStack;

        public:
        //Getters:
        std::stack<Player> getVictimStealStack() const {return this->_victimStealStack;}
        
        //Constructor:
        Captain(const Game& game, const std::string& name);

        //Functions:
        //This function steals 2 coins from a different player.
        void steal(Player& p);

        //Blocks a different Captain from stealing 2 coins.
        void block(Captain& p);
        
    };
}