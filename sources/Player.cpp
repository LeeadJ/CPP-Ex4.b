#include "Player.hpp"


namespace coup{
    //Setter:
    void Player::setPlayer(const Game& game, const std::string& name){
        this->setName(name);
        this->setGame(game);
        this->setCoins(0);
        this->setRole("Default Player");
        this->setPreviousTurn("Null");
    }
    //Construcor
    Player::Player(){
        this->setName("Default Name");
        this->setCoins(0);
        this->setRole("Default Player");
    }
    Player::Player(const Game& game, const std::string& name){
        this->setPlayer(game, name);
        this->_myGame.players().push_back(name);
    }
    Player::Player(const Player& other){
        this->setPlayer(other.getGame(), other.getName());
        this->setCoins(other.coins());
        this->setRole(other.role());
    }

    
    //Functions:
    //Increases the players coins by 1:
    void Player::income(){
        if(this->getGame().turn().compare(this->getName()) != 0){
            throw std::runtime_error("Player income() Error: Not Players turn.");
        }
        this->setCoins(this->coins()+1);
        this->setPreviousTurn("income");
    }
    
    //Increases the players coins by 2:
    void Player::foreign_aid(){
        if(this->getGame().turn().compare(this->getName()) != 0){
            throw std::runtime_error("Player foreign_aid() Error: Not Players turn.");
        }
        this->setCoins(this->coins()+2);
        this->setPreviousTurn("foreign_aid");
    }

    //Eliminates a Player from the Game:
    void Player::coup(Player& p){
        const std::vector<Player>& v = this->getGame().getPlayersVec(); 
        if(std::find(v.begin(), v.end(), p) == v.end()){
            throw std::runtime_error("Player coup() Error: Player to coup not in the game.");
        }
        if(this->role().compare("Assassin") == 0){
                if(this->coins() < 3){
                    throw std::runtime_error("Player coup() Error: Assassin does not have enough coins to use coup().");
                }
        }
        else{
            if(this->coins() < 7){
                throw std::runtime_error("Player coup() Error: Not enough coins to use coup().");
            }
        }
        for(int i=0; i<this->getGame().getGameSize(); i++){
            if(&(this->getGame().getPlayersVec()[i]) == &p){
                //Erasing the victims name from the game PlayernameVec:
                this->getGame().getPlayerNameVec().erase(this->getGame().getPlayerNameVec().begin()+i);
                 //Erasing the victims name from the game playersVec:
                this->getGame().getPlayersVec().erase(this->getGame().getPlayersVec().begin()+i);
                break;
            }
        } 
        //Check if the victim stack is empty.
        //If sack isn't empty, Player has previously used coup ad it was not blocked.
        //Victim that remained in the stack can not return to the game.
        while(this->getVictimStack().size() != 0){
            this->getVictimStack().pop();
        }
        //add current victim to the victim stack:
        this->getVictimStack().push(p);
        //cost of the assassination: 7 coins for a Player, 3 coins for an Assassin:
        if(this->role().compare("Assassin")==0){
            this->setCoins(this->coins()-3)
        }
        else{
            this->setCoins(this->coins()-7);
        }
        this->setPreviousTurn("coup");
    }

    //Returns the Players role:
    std::string Player::role() const{
        return this->getRole();
    }

    //Returns the Players coin count:
    int Player::coins() const{
        return this->getCoins();
    }
}