#pragma once
#include "Player.hpp"
#include "Captain.hpp"


namespace coup{
    class Ambassador : public Player
    {
        public:
        //Constructor:
        Ambassador(Game& game, const std::string& name);

        //Functions:
        //Transfers a coin from one player to another.
        void transfer(Player& p1, Player& p2);

        //Blocks the Captain from stealing 2 coins.
        void block(Captain& cap);
    };
}