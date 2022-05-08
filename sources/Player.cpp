#include "Player.hpp"



namespace coup{
    
    //Setter:
    void Player::setPlayer(Game& game, const std::string& name){
        this->setName(name);
        this->setGame(game);
        this->setCoins(0);
        this->setEliminated(false);
        this->setPlayed(false);
        this->setRole("Default Player");
        this->setPreviousTurn("No Previous turn");
    }
    
    //Construcor
    Player::Player(){
        this->setName("Default Name");
        this->setCoins(0);
        this->setRole("Default Player");
    }

    Player::Player(Game& game, const std::string& name){
        if(game.getPlayerDQ().size() == MAX_GAME_SIZE){
            throw std::runtime_error("Player Constructor Error: No room in current game. (Maximum Players: 6)");
        }
        this->setPlayer(game, name);
        this->getGame()->getPlayerDQ().push_back(this);
        this->getGame()->getPlayersVec().push_back(this);
        //If this is the second player added to the game, the game is valid:
        if(game.getPlayerDQ().size() == MIN_GAME_SIZE){
            game.setGameStatus(true);
        }
    }

    //Functions:
    //Returns the Players role:
    std::string Player::role() const{
        return this->getRole();
    }

    //Returns the Players coin count:
    int Player::coins() const{
        return this->getCoins();
    }

    //Updates the Games turn after finishing current turn:
    void Player::updateGameTurn() const{
        Player* current_player = this->getGame()->getPlayerDQ().front();
        //Changing the current playes status to true:
        current_player->setPlayed(true);
        //Placing the current player at the end of the DQ:
        this->getGame()->getPlayerDQ().pop_front();
        this->getGame()->getPlayerDQ().push_back(current_player);
        //Loop to find the next player eligible to play. 
        //While the current players Eliminated status is true, pop him from the front, and push him to the back of the DQ:
        //Exit loop if finding a player with Eliminated status false of returning to the original player.
        while(this->getGame()->getPlayerDQ().front()->getEliminated()){
            //setting the temp players played status to false:
            this->getGame()->getPlayerDQ().front()->setPlayed(false);
            Player* next_payer = this->getGame()->getPlayerDQ().front();
            this->getGame()->getPlayerDQ().pop_front();
            this->getGame()->getPlayerDQ().push_back(next_payer);
        }
    }

    //Increases the players coins by 1:
    void Player::income(){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Player income() Error: Player is eliminated, can't use income().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Player income() Error: Not Players turn.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Player income() Error: Player has 10 coins, must do coup().");
        }
        this->setCoins(this->coins()+1);
        this->setPreviousTurn("income");
        this->updateGameTurn();
    }
    
    //Increases the players coins by 2:
    void Player::foreign_aid(){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Player foreign_aid() Error: Player is eliminated, can't use foreign_aid().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Player foreign_aid() Error: Not Players turn.");
        }
        if(this->coins() >= MAX_COINS){
            throw std::runtime_error("Player foreign_aid() Error: More than 10 coins, must do coup().");
        }
        this->setCoins(this->coins()+2);
        this->setPreviousTurn("foreign_aid");
        this->updateGameTurn();
    }

    //Eliminates a Player from the Game:
    void Player::coup(Player& p){
        if(!this->getGame()->getGameStatus()){
            throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
        }
        if(this->getEliminated()){
            throw std::runtime_error("Player coup() Error: Player is eliminated, can't use coup().");
        }
        if(&this->getGame()->getTurn() != this){
            throw std::runtime_error("Player coup() Error: Not Players turn.");
        }

        const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
        if(std::find(dq.begin(), dq.end(), &p) == dq.end()){
            throw std::runtime_error("Player coup() Error: Player to coup deos not exist.");
        }
        if(p.getEliminated()){
            throw std::runtime_error("Player coup() Error: Player already eliminated.");
        }
        if(this->coins() < PLAYER_COINS){
            throw std::runtime_error("Player coup() Error: Not enough coins to use coup() (Minimum coins: 7).");
        }
        //If reached here, player is eligable to be elimiated:
        p.setEliminated(true);
        //Cost of coup: 7 coins:
        this->setCoins(this->coins()-PLAYER_COINS);
        this->setPreviousTurn("coup");
        //updates the turn to the next player:
        this->updateGameTurn();
    }

    
    //Operator (==):
    bool Player::operator == (const Player& other) const{
        bool c1 = this->getName()==other.getName();
        bool c2 = this->getCoins() == other.getCoins();
        bool c3 = this->getEliminated() == other.getEliminated();
        bool c4 = this->getPlayed() == other.getPlayed();
        bool c5 = this->getPreviousTurn() == other.getPreviousTurn();
        bool c6 = this->getRole() == other.getRole();
        return (c1 && c2 && c3 && c4 && c5 && c6);
    }
    
}

