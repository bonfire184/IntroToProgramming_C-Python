#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void convertSeconds(int InputSeconds){
    int hours;
    int minutes;
    int seconds;
    hours = InputSeconds / 3600;
    minutes = (InputSeconds % 3600) / 60;
    seconds = (InputSeconds % 3600) % 60;
    cout<<"The time is "<<hours<<" hours, "<<minutes<<" minutes, and "<<seconds<<" seconds."<<endl;
}

void solveMaze(int HorseArray[4][4]){
    cout<<"solveMaze called"<<endl;

    int HorsePositionRow = 3;
    int HorsePositionColumn = 0; //

    while (HorsePositionRow != 0 || HorsePositionColumn != 3){
        if (HorseArray[HorsePositionRow][HorsePositionColumn + 1] == 2){
            HorsePositionColumn += 1;
            cout<<"Horse moved right 1."<<endl;
            cout<<"New Horse Position: ("<<HorsePositionRow<<", "<<HorsePositionColumn<<") (Row, Col)\nYou Reached the Apple!!"<<endl;
        }

        else if (HorseArray[HorsePositionRow - 1][HorsePositionColumn] == 0){
            HorsePositionRow -= 1;
            cout<<"Horse moved up 1."<<endl;
            cout<<"New Horse Position: ("<<HorsePositionRow<<", "<<HorsePositionColumn<<") (Row, Col)"<<endl;
        }

        else if (HorseArray[HorsePositionRow][HorsePositionColumn + 1] == 0){
            HorsePositionColumn += 1;
            cout<<"Horse moved right 1."<<endl;
            cout<<"New Horse Position: ("<<HorsePositionRow<<", "<<HorsePositionColumn<<") (Row, Col)"<<endl;
        }

    }//end while
}

void Problem2(){

    int randNum;
    char choice = 'z';

    while(choice != 'b'){
        cout<<"a. Fight the Dragon."<<endl;
        cout<<"b. Go Home."<<endl;
        cout<<"c. Save the Princess."<<endl;

        cin>>choice;

        if(choice == 'a'){
            srand (time(NULL));

            randNum = rand() % 2;

            if (randNum == 0){
                cout<<"You Win!"<<endl;
            }
            else{
                cout<<"You Lose."<<endl;
                choice = 'b';
            }//end else
        }//end if
        else if(choice == 'c'){
            cout<<"You saved the princess.\n"<<endl;
        }//end else if
        else if(choice == 'b'){
            cout<<"Wimp!"<<endl;
        }//end else if
        else{
            cout<<"Can not recognize your input.\n"<<endl;
        }//end else
    }//end while
}//end Problem2()

void Problem3(){
    int HorseArray[4][4] =
    {
       {1,1,0,2},//row1
       {0,0,0,1},//row2
       {0,1,0,1},//row3
       {0,0,0,1}//row4
    };//End Array Declaration

    solveMaze(HorseArray);
}

void Problem1(){

    cout<<""<<endl;
    int InputSeconds = -1;
    while (InputSeconds < 0 || InputSeconds > 86400){
        cout<<"Enter a value of seconds that is >= 0 and <= 86400."<<endl;
        cin>>InputSeconds;
    }
    convertSeconds(InputSeconds);

}

int main(){

    int choice = 0;

    while(choice != 4){
        cout<<"1. Problem 1"<<endl;
        cout<<"2. Problem 2"<<endl;
        cout<<"3. Problem 3"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter a value to select a problem."<<endl;
        cin>>choice;
        if(choice == 1){
            Problem1();
            cout<<" "<<endl;
        }
        else if(choice == 2){
            Problem2();
            cout<<" "<<endl;
        }
        else if(choice == 3){
            Problem3();
            cout<<" "<<endl;
        }
        else if(choice == 4){}
        else{
            cout<<"Can not recognize your input.\n"<<endl;
        }
    }//end while

}//end main
