#pragma once
#include "Player.hpp"
#include <stack>

namespace coup{
    class Assassin : public Player{

        std::stack<Player*> _victimStack;

        public:
        //Getters:
        std::stack<Player*>& getVictimStack() {return this->_victimStack;}

        //Constructor
        Assassin(Game& game, const std::string& name);

        //Functions
        void coup(Player& p);
    };
}