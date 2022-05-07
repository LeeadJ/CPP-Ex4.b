#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <map>
#include <algorithm>
#include <deque>
#include "Player.hpp"

namespace coup{
    class Player;
    class Game{

        std::vector<Player*> _playersVec;
        std::deque<Player*> _playerDQ;
        // Player* _winner;
        bool _gameStatus;
        std::string _gameName;


        public:
            //Getters:
            std::vector<Player*>& getPlayersVec() {return this->_playersVec;}
            std::deque<Player*>& getPlayerDQ() {return this->_playerDQ;}
            // Player* getWinner() const {return this->_winner;}
            Player& getTurn() {return *(this->getPlayerDQ().front());}
            bool getGameStatus() const {return this->_gameStatus;}
            std::string gameName() const {return this->_gameName;}

            //Setters:
            // void setWinner(Player& p) {this->_winner=&p;}
            void setGameStatus(bool x) {this->_gameStatus=x;}
            void setGameName(const std::string name) {this->_gameName=name;}
            //Constructor:
            Game(const std::string& name);
            

            //Game Functions:
            //Returns the name of the current players turn:
            std::string turn();

            //Returns a vector of players currently in the game:
            std::vector<std::string> players() const;

            //Returns the name of the winner. Throws Error if the game isn't over:
            // std::string winner();
    };
}