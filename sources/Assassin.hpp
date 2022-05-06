#pragma once
#include "Player.hpp"
#include <stack>

namespace coup{
    class Assassin : public Player{

        std::stack<Player> _victimStack;

        public:
        //Getters:
        std::stack<Player> getVictimStack() const {return this->_victimStack;}

        //Constructor
        Assassin(const Game& game, const std::string& name);

        //Functions
        void coup(Player& p);
    };
}