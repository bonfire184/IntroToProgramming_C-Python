#include <iostream>
#include <stdlib.h>
#include <string>
#include <stdio.h>


using namespace std;

int IndexOfLastItem = -1;

int InsertItem(string CraigslistArray[21][2]){

    string ItemType;
    int ItemCost;
    string StringItemCost;

    while(ItemType != "b" && ItemType != "m" && ItemType != "d" && ItemType != "t" && ItemType != "c"){//Make sure input is valid
        cout<<"Enter the item type-b,m,d,t,c:"<<endl;
        cin>>ItemType;
    }//end while

    cout<<"Enter the item cost: "<<endl;
    cin>>ItemCost;

    StringItemCost = to_string(ItemCost); //Cast item cost int to string


    if (IndexOfLastItem <= 18){//If the array is not full, they can add another item
        CraigslistArray[IndexOfLastItem + 1][0] = ItemType;
        CraigslistArray[IndexOfLastItem + 1][1] = StringItemCost;

        IndexOfLastItem += 1; //increment how many items are in the array

    }//end if
    else if (IndexOfLastItem > 18){//If the array is full, new post will delete the last post in the array
        CraigslistArray[IndexOfLastItem][0] = ItemType;
        CraigslistArray[IndexOfLastItem][1] = StringItemCost;
    }

    return 0;


}//end InsertItem

void SearchItem(string CraigslistArray[21][2]){

    string ItemChoice;
    int MaxItemCost;
    int ConvertedArraySecondColumn;

    while(ItemChoice != "b" && ItemChoice != "m" && ItemChoice != "d" && ItemChoice != "t" && ItemChoice != "c"){//make sure input is valid
        cout<<"Enter the item type-b,m,d,t,c:"<<endl;
        cin>>ItemChoice;
    }//end while

    cout<<"Enter the maximum item cost:";
    cin>>MaxItemCost;

    for(int i = 0; i <= IndexOfLastItem; i++){//Will do loop until find item or the last row of items in the array
        ConvertedArraySecondColumn = stol(CraigslistArray[i][1]);//Convert second column of array to integer for comparison

        if(CraigslistArray[i][0] == ItemChoice){//if character in first column = the character of what they want to buy, go on
            if(MaxItemCost >= ConvertedArraySecondColumn){//if they are offering as much or more for the item listed, go on
                //they are offering as much or more for the item they want

                CraigslistArray[i][0] = "null";//Intermediate step for clarity
                CraigslistArray[i][1] = "null";//Intermediate step for clarity

                for (int z = i; z <= IndexOfLastItem; z++){
                    CraigslistArray[z][0] = CraigslistArray[z+1][0];//Set current row index, 1st column equal to row index, column of one below
                    CraigslistArray[z][1] = CraigslistArray[z+1][1];//Set current row index, 2nd column equal to row index, column of one below
                }

                IndexOfLastItem -= 1;//Decrement # of items used in array

                break;
            }else{
                cout<<"Item not found."<<endl;//Item matched but they didn't offer enough
                break;
            }
        }else{
            cout<<"Item not found."<<endl;//No Item matching
            break;
        }
    }//end for



}//end SearchItem

void PrintItem(string CraigslistArray[21][2]){

    for(int i = 0; i <= IndexOfLastItem; i++){//while i is less than the row index of the last item, it will print out the row

        //Checks char to expand into full word
        if(CraigslistArray[i][0] == "b"){
            cout<<"bicycle: "<<CraigslistArray[i][1]<<endl;
        }
        if(CraigslistArray[i][0] == "m"){
            cout<<"microwave: "<<CraigslistArray[i][1]<<endl;
        }
        if(CraigslistArray[i][0] == "d"){
            cout<<"dresser: "<<CraigslistArray[i][1]<<endl;
        }
        if(CraigslistArray[i][0] == "t"){
            cout<<"truck: "<<CraigslistArray[i][1]<<endl;
        }
        if(CraigslistArray[i][0] == "c"){
            cout<<"chicken: "<<CraigslistArray[i][1]<<endl;
        }



        //cout<<CraigslistArray[i][0]<<":"<<CraigslistArray[i][1]<<endl;
    }

}//end PrintItem


int main(){

    string CraigslistArray[21][2];

    int choice = -1;

    while(choice != 4){//while they dont want to quit, menu cycles
        cout<<"1. Insert an item."<<endl;
        cout<<"2. Search for an item."<<endl;
        cout<<"3. Print the message board."<<endl;
        cout<<"4. Quit"<<endl;
        cin>>choice;
        if(choice == 1){
            InsertItem(CraigslistArray);
        }
        else if(choice == 2){
            SearchItem(CraigslistArray);
        }
        else if(choice == 3){
            PrintItem(CraigslistArray);
        }
        else if(choice == 4){}
        else{
            cout<<"Can not recognize your input.\n"<<endl;
        }
    }//end while

}//end main
