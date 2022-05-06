#pragma once
#include<iostream>
#include<string>
#include "Game.hpp"


namespace coup{
    class Player{
        
        std::string _myName;
        std::string _myRole;
        int _myCoins;
        Game _myGame;
        std::string _previousTurn;
        
        

        public:
            //Getters:
            std::string getName() const {return this->_myName;}
            std::string getRole() const {return this->_myRole;}
            int getCoins() const {return this->_myCoins;}
            Game getGame() const {return this->_myGame;}
            std::string getPreviousTurn() const {return this->_previousTurn;}
            


            //Setters:
            void setName(const std::string& n) {this->_myName=n;}
            void setRole(const std::string& r) {this->_myRole=r;}
            void setCoins(int num) {this->_myCoins=num;}
            void setGame(const Game& g) {this->_myGame=g;}
            void setPreviousTurn(const std::string turn) {this->_previousTurn=turn;}
            void setPlayer(const Game& game, const std::string& name);
            


            //Constructor
            Player();
            Player(const Game& game, const std::string& name);
            Player(const Player& other);
            
            //functions:
            //Increases the players coins by 1:
            void income();
            
            //Increases the players coins by 2:
            void foreign_aid();

            //Eliminates a Player from the Game:
            void coup(Player& p);

            //Returns the Players role:
            std::string role() const;

            //Returns the amount of coins the Player has:
            int coins() const;
    };
}