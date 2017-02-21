#include "GameFunctions.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Buildings{
private:
    int capacity;
    int requiredWood;
public:
    Buildings(){
        //cout<<"Building Class Called."<<endl;
    }
    int setCost(){                  ///BUILDINGS CLASS: This class is the base class for the following 3 types of buildings
        return 1;
    }
};

class Hut:public Buildings{ ///Hut is a child of the Buildings class and inherits
    int cost = 10;
public:
    Hut(){
        //cout<<"Hut Class Called."<<endl;
    }
    friend void setHutCost(int c);      ///creates a friend function that can access the cost variable, which it will update later
    int setCost(){
        return cost;
    }
};

void setHutCost(int c){///friend function updating the cost back in Hut class
    Hut h1;
    h1.cost = c;
}

class Tradepost:public Buildings{
public:
    Tradepost(){
        //cout<<"Tradepost Class Called."<<endl;
    }
    int setCost(){                          ///Tradepost class (child of Buildings)
        return 100;
    }
};

class Lodge:public Buildings{
public:
    Lodge(){
        //cout<<"Lodge Class Called."<<endl;
    }
    int setCost(){                  ///Lodge class (child of Buildings)
        return 100;
    }
};

class WorkshopClass:public Buildings{
public:
    WorkshopClass(){
        //cout<<"Lodge Class Called."<<endl;
    }                                               ///Workshop class(child of Buildings)
    int setCost(){
        return 100;
    }
};


GameFunctions::GameFunctions()  ///CONSTRUCTOR
{
}

GameFunctions::~GameFunctions(){}

void GameFunctions::PrintDay(){
    cout<<"Day: "<<data.day<<endl;
}

void GameFunctions::AddInfo(DataFromSave data1){ ///This function receives the struct from main and populates its own struct
    data.villagers = data1.villagers;
    data.day = data1.day;
    data.wood = data1.huts;
    data.typeOfCart = data1.typeOfCart;
    data.traps = data1.traps;
    data.huts = data1.huts;
    data.tradepost = data1.tradepost;
    data.lodge = data1.lodge;
    data.workshop = data1.workshop;
    data.maxCapacity = data1.huts*2;
    //cout<<"Max Capacity: "<<data.maxCapacity<<endl;
}

void GameFunctions::Village(){ ///When users select this from the menu, all pertinent info about their village is displayed
    char choice;
    cout<<"Maximum Capacity of Village: "<<data.maxCapacity<<endl;
    cout<<"Villagers: "<<data.villagers<<endl;
    cout<<"Huts: "<<data.huts<<endl;
    cout<<"Type of Cart: "<<data.typeOfCart<<endl;
    cout<<"Wood: "<<data.wood<<endl;
    cout<<"Tradepost Owned?: ";
    if (data.tradepost == true){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
    cout<<"Workshop Owned?: ";
    if (data.workshop == true){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
    cout<<"Lodge Owned?: ";
    if (data.lodge == true){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}


}
void GameFunctions::Builder(){ ///Asks the user if they want to build something then lists options for building structures
    string choice;
    cout<<"Would you like to build a structure? y/n: ";
    cin>>choice;
    if(choice == "y"){
        cout<<"1. Hut"<<endl;
        cout<<"2. Tradepost"<<endl;
        cout<<"3. Lodge"<<endl;
        cout<<"4. Workshop"<<endl;
        cin>>choice;
        if(choice == "1"){
            setHutCost(10);///CALL FRIEND FUNCTION TO SET COST OF HUTS TO 10
            Hut h1;
            //cout<<"Set Cost: "<<h1.setCost()<<endl;
            if(data.wood >= h1.setCost()){///IF USER HAS MORE WOOD THAN THE COST OF A HUT, A HUT WILL BE BUILT AND THEY WILL LOSE THAT MUCH WOOD
                data.wood -= h1.setCost();
                data.huts += 1;
                cout<<"\nHuts: "<<data.huts<<endl;
            }else{
                cout<<"\nNot enough wood to build a house."<<endl;
                cout<<"Huts: "<<data.huts<<endl;
            }
        }else if(choice == "2"){
            Tradepost t1;
            if(data.tradepost == false && data.wood >= t1.setCost()){///IF THE USER DOESNT HAVE A TRADEPOST YET, THEY HAVE THE OPTION TO BUILD ONE
                cout<<"Wood:"<<data.wood<<endl;
                data.wood -= t1.setCost();
                data.tradepost = true;
                cout<<"\nYou now have a Tradepost!"<<endl;
            }else if(data.wood < t1.setCost()){
                cout<<"\nYou do not have enough wood for a Tradepost!"<<endl;
            }else{
                cout<<"\nYou already have a Tradepost!"<<endl;
            }
            //cout<<"2"<<endl;
        }else if(choice == "3"){
            Lodge l1;
            if(data.lodge == false && data.wood >= l1.setCost()){///IF THE USER DOESNT HAVE A TRADEPOST YET, THEY HAVE THE OPTION TO BUILD ONE
                cout<<"Wood:"<<data.wood<<endl;
                data.wood -= l1.setCost();
                data.lodge = true;
                cout<<"\nYou now have a Lodge!"<<endl;
            }else if(data.wood < l1.setCost()){
                cout<<"\nYou do not have enough wood for a Lodge!"<<endl;
            }else{
                cout<<"\nYou already have a Lodge!"<<endl;
            }
            //cout<<"3"<<endl;
        }else if(choice == "4"){
            WorkshopClass w1;
            if(data.workshop == false && data.wood >= w1.setCost()){///IF THE USER DOESNT HAVE A WORKSHOP YET, THEY  HAVE THE OPTION TO BUILD ONE
                cout<<"Wood:"<<data.wood<<endl;
                data.wood -= w1.setCost();
                data.workshop = true;
                cout<<"\nYou now have a Workshop!"<<endl;
            }else if(data.wood < w1.setCost()){
                cout<<"\nYou do not have enough wood for a Workshop!"<<endl;
            }else{
                cout<<"\nYou already have a Workshop!"<<endl;
            }
        }//end Elseif Stucture
    }
}
void GameFunctions::Merchant(){
    if (data.day%5 != 0){///EVERY 5 DAYS THE MERCHANT APPEARS AND YOU CAN PURCHASE AN UPGRADED CART FROM HIM
        cout<<"The merchant is off in some distant land. Maybe try waiting a few days."<<endl;
    }else{
        string choice;
        cout<<"1. Buy upgraded cart (200 wood)"<<endl;
        cin>>choice;
        if(choice == "1" && data.typeOfCart != "good"){
            if(data.wood < 200){
                cout<<"Not enough wood for an upgraded cart!"<<endl;
            }else{
                data.wood -= 200;
                data.typeOfCart = "good";
                cout<<"Your upgraded your cart to a good cart!"<<endl;
            }
        }else{cout<<"You already have an upgraded cart!"<<endl;}///IF THE USER HAS ALREADY PURCHASED THE UPGRADED CART, HE CAN'T AGAIN
    }
}
void GameFunctions::Workshop(){
    if(data.workshop){
        string choice;
        cout<<"Build a statue of yourself for all of the town to see? y/n: ";
        cin>>choice;
        if (choice == "y"){
            cout<<"You built a massive statue of yourself but half of your townspeople died while making it."<<endl;
            data.villagers /= 2;
        }

        ///YOU CAN BUILD A STATUE IN THE VILLAGE BUT IT'S SO HUGE THAT HALF OF THE TOWNSPEOPLE DIE
    }else{
        cout<<"You don't have a workshop yet!"<<endl;
    }
}

void GameFunctions::EndDay(){
    data.maxCapacity = data.huts*2; ///EACH HUT CAN HOLD TWO PEOPLE SO THE MAX CAPACITY IS NUMBER OF HUTS TIMES 2

    srand(time(NULL));

    int randNum = rand() % 100 +1;
    //cout<<"Rand Num:" << randNum<< endl;

    if (data.villagers < data.maxCapacity && randNum > 10 && randNum < 65){///SLIGHTLY GREATER THAN 50% CHANCE THAT A VILLAGER WILL MOVE IN IF THERE'S SPACE
        data.villagers += 1;
        cout<<"A new villager has arrived in your village!"<<endl;
    }
    srand(time(NULL));

    cout<<"\nMax Capacity: "<<data.maxCapacity<<endl;
    cout<<"Villagers: "<<data.villagers<<endl;

    if (data.typeOfCart != "good"){///IF THE USER HAS BOUGHT AN UPGRADED CART, THE VILLAGERS WILL BRING BACK TWICE AS MUCH WOOD PER DAY
        data.wood += data.villagers*2;
    }else{
        data.wood += data.villagers*4;
    }
    cout<<"Wood: "<<data.wood<<endl;

    data.day++;
}
void GameFunctions::Reset(){

    string choice;
    cout<<"Are you SURE you want to reset? y/n: ";
    cin>>choice;

    ///IF THEY REALLY WANT TO RESET, ALL VALUES IN LOCAL STRUCT WILL BE RESET TO THE BEGINNING OF THE GAME.

    if(choice == "y"){
        data.day = 0;
        data.huts = 1;
        data.lodge = false;
        data.maxCapacity = data.huts*2;
        data.tradepost = false;
        data.traps = 0;
        data.villagers = 1;
        data.wood = 10;
        data.workshop = false;
        data.typeOfCart = "small";
    }else{}
}
