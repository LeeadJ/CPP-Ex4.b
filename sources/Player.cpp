#include "Player.hpp"



namespace coup{
    
    //Setter:
    void Player::setPlayer(Game& game, const std::string& name){
        this->setName(name);
        this->setGame(game);
        this->setCoins(0);
        this->setEliminated(false);
        this->setRole("Default Player");
        this->setPreviousTurn("Null");
    }
    
    //Construcor
    Player::Player(){
        this->setName("Default Name");
        this->setCoins(0);
        this->setRole("Default Player");
    }

    Player::Player(Game& game, const std::string& name){
        if(game.getPlayerDQ().size() == 6){
            throw std::runtime_error("Player Constructor Error: No room in current game. (Maximum Players: 6)");
        }
        this->setPlayer(game, name);
        this->getGame()->getPlayerDQ().push_back(this);
        
        //If this is the second player added to the game, the game is valid:
        if(game.getPlayerDQ().size() == 2){
            game.setGameStatus(true);
        }
    }

    
    //Functions:
    //Increases the players coins by 1:
    // void Player::income(){
    //     if(this->getGame()->getGameStatus()==false){
    //         throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
    //     }
    //     if(this->getGame()->getTurn() != this){
    //         throw std::runtime_error("Player income() Error: Not Players turn.");
    //     }
    //     if(this->coins() >= 10){
    //         throw std::runtime_error("Player income() Error: Player has 10 coins, must do coup().");
    //     }
    //     this->setCoins(this->coins()+1);
    //     this->setPreviousTurn("income");
    //     this->updateGameTurn();
    // }
    
    //Increases the players coins by 2:
    // void Player::foreign_aid(){
    //     if(this->getGame()->getGameStatus()==false){
    //         throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
    //     }
    //     if(this->getGame()->getTurn() != this){
    //         throw std::runtime_error("Player foreign_aid() Error: Not Players turn.");
    //     }
    //     if(this->coins() >= 10){
    //         throw std::runtime_error("Player foreign_aid() Error: More than 10 coins, must do coup().");
    //     }
    //     this->setCoins(this->coins()+2);
    //     this->setPreviousTurn("foreign_aid");
    //     this->updateGameTurn();
    // }

    //Eliminates a Player from the Game:
    // void Player::coup(Player& p){
    //     if(this->getGame()->getGameStatus()==false){
    //         throw std::runtime_error("Game Status Error: Not enough Players in the game: (Minimum Player2: 2)");
    //     }
    //     if(this->getGame()->getTurn() != this){
    //         throw std::runtime_error("Player coup() Error: Not Players turn.");
    //     }
    //     const std::deque<Player*>& dq = this->getGame()->getPlayerDQ();
    //     if(std::find(dq.begin(), dq.end(), p) == dq.end()){
    //         throw std::runtime_error("Player coup() Error: Player to coup deos not exist.");
    //     }
    //     if(p.getEliminated() == true){
    //         throw std::runtime_error("Player coup() Error: Player already eliminated");
    //     }
    //     if(this->coins() < 7){
    //         throw std::runtime_error("Player coup() Error: Not enough coins to use coup().");
    //     }
    //     //If reached here, player is eligable to be elimiated:
    //     p.setEliminated(true);
    //     //Cost of coup: 7 coins:
    //     this->setCoins(this->coins()-7);
    //     this->setPreviousTurn("coup");
    //     //updates the turn to the next player:
    //     this->updateGameTurn();
    // }

    //Returns the Players role:
    // std::string Player::role() const{
    //     return this->getRole();
    // }

    //Returns the Players coin count:
    // int Player::coins() const{
    //     return this->getCoins();
    // }

    //Updates the Games turn after finishing current turn:
    // void Player::updateGameTurn(){
    //     //Placing the current player at the end of the DQ:
    //     Player* current_player = this->getGame()->getPlayerDQ().front();
    //     this->getGame()->getPlayerDQ().pop_front();
    //     this->getGame()->getPlayerDQ().push_back(current_player);
    //     //Loop to find the next player eligible to play. 
    //     //While the current players Eliminated status is true, pop him from the front, and push him to the back of the DQ:
    //     //Exit loop if finding a player with Eliminated status false of returning to the original player.
    //     while(this->getGame()->getPlayerDQ().front()->getEliminated() == true){
    //         Player* next_payer = this->getGame()->getPlayerDQ().front();
    //         this->getGame()->getPlayerDQ().pop_front();
    //         this->getGame()->getPlayerDQ().push_back(next_payer);
    //     }
    //     // const std::vector<Player>& v = this->getGame().getPlayersVec();
    //     // //Looping the Players Vector in the game: 
    //     // for(int i=0; i<v.size(); i++){
    //     //     //Stopping at the current players index:
    //     //     if(&(v[i]) == this){
    //     //         //If the next index exceeds the vector size, then the current player is the last player in the vector:
    //     //         if(i+1 == v.size()){
    //     //             //stop at the first possible player that isn't currently eliminated to update turn:
    //     //             int j=0;
    //     //             while(v[j].getEliminated()==true){
    //     //                 j++;
    //     //             }
    //     //             if(j==i){
    //     //                 //In this case, we made a full loop. No next player (because they are eliminated).
    //     //                 //No need to update next turn:
    //     //                 break;
    //     //             }
    //     //             this->getGame().setTurn(v[j]);
    //     //             break;
    //     //         }
    //     //         //i+1 does not exceed the vec size:
    //     //         else{
    //     //             int j = i+1;
    //     //             while(v[j].getEliminated()==true){
    //     //                 j = (j+1) % v.size();
    //     //             }
    //     //             if(j==i){
    //     //                 //In this case, we made a full loop. No next player (because they are eliminated).
    //     //                 //No need to update next turn:
    //     //                 break;
    //     //             }
    //     //             this->getGame().setTurn(v[j]);
    //     //             break;
    //     //         }
    //     //     }
    //     // }
    // }
}

