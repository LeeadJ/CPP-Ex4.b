#pragma once
#include "Player.hpp"
#include <stack>

namespace coup{
    class Assassin : public Player{

        std::stack<Player*> _victimStack;
        // Player* _victim;

        public:
        //Getters:
        std::stack<Player*>& getVictimStack() {return this->_victimStack;}
        // Player& getVictim() {return *(this->_victim);}

        //Setters:
        // void setVictim(Player& p) {this->_victim=&p;}

        //Constructor
        Assassin(Game& game, const std::string& name);

        //Functions:
        //Increases the players coins by 1:
        void income();
        
        //Increases the players coins by 2:
        void foreign_aid();

        //Eliminates Player:
        void coup(Player& p);
    };
}