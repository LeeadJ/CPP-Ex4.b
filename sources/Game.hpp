#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <map>
#include <algorithm>
#include "Player.hpp"

namespace coup{
    class Game{
        // //Variables:
        std::vector<Player> _playersVec;
        std::vector<std::string> _playerNameVec;
        int _turn;
        // std::map<std::string, Player> _playersCouped;


        public:
            //Getters:
            std::vector<Player> getPlayersVec() const {return this->_playersVec;}
            std::vector<std::string> getPlayerNameVec() const {return this->_playerNameVec;}
            int getGameSize() const { return this->getPlayersVec().size();}
            int getTurn() const {return this->_turn;}
            // std::map<std::string, Player> getPlayersEliminatedMap() const {return this->_playersCouped;}

            //Constructor:
            Game() : _turn(0){}
            
            //Game Functions:
            //Returns the name of the current players turn:
            std::string turn() const;

            //Returns a vector of players currently in the game:
            std::vector<std::string> players() const;

            //Returns the name of the winner. Throws Error if the game isn't over:
            std::string winner();

            //User added Functions:
            //Adds a player to the game:
            // void addPlayer(const Player& p);

            //Updates the current turn:
            void updateTurn();

            // //Addes a player to the Coup Map:
            // void addPlayer_coupMap(const Player& p);
    };
}