#include "GameFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    GameFunctions GameControlller;//Creates an Instance of Game Controller
    DataFromSave SaveData;//Creates an Instance of Save Data that is local to main, but it will be sent to Game Controller once data is read

    cout << "A Dark Forest         -Hayden Lingle"<<endl;

    string lineInSaveData;//String that will store each piece of data taken in by Data
    ifstream Data;//a steam of the entire file imported

    Data.open("SaveFile.txt");

    if(Data.fail()){
        cout<<"Error importing file."<<endl;
    }
    else{
        int index = 0;
        while (getline(Data, lineInSaveData, ',')){                    ///This block of code will populate the struct in main
            if (index == 0){
                SaveData.wood = stoi(lineInSaveData);                  ///with data from the save file. It checks to see the
            }else if(index == 1){
                SaveData.typeOfCart = lineInSaveData;                  ///index of what piece of data it is reading and then

            }else if(index == 2){
                SaveData.traps = stoi(lineInSaveData);                 ///inputs that into the correct part of the struct

            }else if(index == 3){
                SaveData.huts = stoi(lineInSaveData);

            }else if(index == 4){
                if(lineInSaveData == "true"){
                   SaveData.tradepost = true;
                }else{
                    SaveData.tradepost = false;
                }

            }else if(index == 5){
                if(lineInSaveData == "true"){
                   SaveData.lodge = true;
                }else{
                    SaveData.lodge = false;
                }

            }else if(index == 6){
                if(lineInSaveData == "true"){
                   SaveData.workshop = true;
                }else{
                    SaveData.workshop = false;
                }
            }
            else if(index == 7){
                SaveData.day = stoi(lineInSaveData);
            }
            else if(index == 8){
                SaveData.villagers = stoi(lineInSaveData);
            }
            else{};
            index++;
        }//end while
    }

    GameControlller.AddInfo(SaveData);///This line sends the struct full of save data to the GameFunctions class to populate its own local struct

    int choice = 0;

    while (choice != 7){                    ///Here is the menu. It will repeat over and over until the user selects the number 7 to exit
        cout<<""<<endl;
        GameControlller.PrintDay();
        cout<<""<<endl;
        cout<<"Enter Choice Below."<<endl;
        cout<<"1. Village"<<endl;
        cout<<"2. Builder"<<endl;
        cout<<"3. Merchant"<<endl;
        cout<<"4. Workshop"<<endl;
        cout<<"5. End Day"<<endl;
        cout<<"6. Reset"<<endl;
        cout<<"7. Exit"<<endl;
        cin>>choice;
        if (choice == 1){
            GameControlller.Village();      ///Depending on user input, will call functions inside the Game Functions class
        }else if(choice == 2){
            GameControlller.Builder();
        }else if(choice == 3){
            GameControlller.Merchant();
        }else if(choice == 4){
            GameControlller.Workshop();
        }else if(choice == 5){
            GameControlller.EndDay();
        }else if(choice == 6){
            GameControlller.Reset();
        }else if(choice == 7){
        }else{
            cout<<"Invalid Input"<<endl;
        }
    }
}
