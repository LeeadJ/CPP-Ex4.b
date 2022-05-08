// #include "Player.hpp"
// #include "Game.hpp"
// #include "Duke.hpp"
// #include "Assassin.hpp"
// #include "Ambassador.hpp"
// #include "Captain.hpp"
// #include "Contessa.hpp"
// using namespace std;
// using namespace coup;

// int main(){
//     // // cout<<"hello"<<endl;
//     // Game g{"TestGame"};
    
//     // Assassin p1{g,"p1"};
//     // Assassin p2{g,"p2"};
//     // Ambassador p3{g,"p3"};
//     // Captain p4{g,"p4"};
//     // Contessa p5{g,"p5"};
    
//     // for(Player* p : g.getPlayerDQ()){
//     //     cout<<p->getRole()<<": ";
//     //     cout<<p->getName()<<" coins: "<<p->coins()<<endl;
//     // }

//     // cout<<"\n\n"<<endl;

//     // for(int i=0; i<6; i++){
//     //     for(Player* p : g.getPlayerDQ()){
//     //         p->income();
//     //     }
//     // }
//     // for(Player* p : g.getPlayerDQ()){
//     //     cout<<p->getRole()<<": ";
//     //     cout<<p->getName()<<" coins: "<<p->coins()<<endl;
//     // }
//     // cout<<"\n\n"<<endl;
//     // p1.income();
//     // cout<<"p1 income"<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;
    
//     // p2.coup(p3);
//     // cout<<"p2 killed p3 "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;
    
//     // p4.income();
//     // cout<<"p4 income "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;

//     // p5.income();
//     // cout<<"p5 income "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;
    
//     // p1.income();
//     // cout<<"p1 income round 2"<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;

//     // p5.block(p2);
//     // cout<<"p5 blocked p2 before p2  second turn "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;

//     // p2.income();
//     // cout<<"p2 income "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;

//     // p3.income();
//     // cout<<"p3 income "<<endl;
//     // cout<<"Current Turn: "<<g.turn()<<endl;
    
    
//     // cout<<"\n"<<endl;
    
//     // for(string name : g.players()){
//     //     cout<<name<<endl;
//     // }
//     // cout<<"\n\n";
//     // for(Player* p : g.getPlayerDQ()){
//     //     cout<<p->getRole()<<": ";
//     //     cout<<p->getName()<<" coins: "<<p->coins()<<endl;
//     // }
    

    
//     Game game_1{};
//     /* This player drew the "Duke" card, his name is Moshe
// 	and he is a player in game_1 */
// 	Duke duke{game_1, "Moshe"};
// 	Assassin assassin{game_1, "Yossi"};
// 	Ambassador ambassador{game_1, "Meirav"};
// 	Captain captain{game_1, "Reut"};
// 	Contessa contessa{game_1, "Gilad"};

//     vector<string> players = game_1.players();
//     for(string name : players){
// 		cout << name << endl;
// 	}
//     cout<<"\n"<<endl;
//     // prints Moshe
// 	cout << game_1.turn() << endl;
//     cout<<"\n"<<endl;

//     // throws no exceptions
// 	duke.income();
// 	assassin.income();
// 	ambassador.income();
// 	captain.income();
// 	contessa.income();
//     cout<<"\n"<<endl;

//     // throws exception, it is duke's turn now
// 	// assassin.income();

//     duke.income();
// 	assassin.foreign_aid();

// 	// // throws exception, the last operation duke performed
// 	// // is income, which cannot be blocked by any role
// 	// captain.block(duke);

// 	cout << duke.coins() << endl; // prints 2
// 	cout << assassin.coins() << endl; // prints 3

// 	// // throws exception, the last operation duke performed
// 	// // is foreign aid, which cannot be blocked by contessa
// 	// contessa.block(assassin);

// 	duke.block(assassin);
// 	cout << assassin.coins() << endl; // prints 1

// 	ambassador.transfer(duke, assassin); //transfers 1 coin from duke to assassin
// 	captain.foreign_aid();
// 	contessa.foreign_aid();

// 	duke.tax();
// 	assassin.income();
// 	ambassador.foreign_aid();
// 	captain.steal(contessa);
// 	contessa.foreign_aid();

// 	duke.tax();
// 	// // no exception, assassin can coup with only 3 coins
// 	assassin.coup(duke);

// 	players = game_1.players();
// 	// /*
// 	// 	prints:
// 	// 	Yossi
// 	// 	Meirav
// 	// 	Reut
// 	// 	Gilad
// 	// */
// 	for (string name : players)
// 	{
// 		cout << name << endl;
// 	}

// 	contessa.block(assassin);

// 	players = game_1.players();
// 	// /*
// 	// 	prints:
// 	// 	Moshe
// 	// 	Yossi
// 	// 	Meirav
// 	// 	Reut
// 	// 	Gilad
// 	// */
//     cout<<"\n\n";
// 	for (string name : players)
// 	{
// 		cout << name << endl;
// 	}

//     return 0;
// }