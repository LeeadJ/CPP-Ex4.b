#pragma once
#include "Player.hpp"
#include "Assassin.hpp"

namespace coup{
    class Contessa : public Player{
        public:
        //Constructor:
        Contessa(const Game& game, const std::string& name);

        //Functions:
        //Blocks the Assassin from assasinating. 
        void block(Assassin& ass);
    };
}