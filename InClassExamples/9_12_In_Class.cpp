#include <iostream>

using namespace std;

bool deleteArray (int iSearch[], int value, int iUsed){
    bool success = false;
    int index = -1;
    for(int i = 0; i < iUsed; i++){
        if(iSearch[i] == value){
            index=i;
            break;
        }
    }

    if (index > -1){
        //delete
        for(int i = index; i < iUsed-1; i++){
            iSearch[i] = iSearch[i + 1];
        }
    }
    return success;
}

int main(){

    int iSearch[5] = {1, 3, 4, 5};
    cout<<iSearch[1]<<"Isearch [1]"<<endl;
    int iUsed = 4;

    for(int i = 0; i < iUsed; i++){
        cout<<iSearch[i]<<endl;
    }

    //insert 2 at position
    int index = 1;//WANT TO INSERT NUMBER AT INDEX 1
    for(int x = iUsed; x > index; x--){//

        iSearch[x] = iSearch[x-1];
        cout<<iSearch[x-1]<<" -> iSearch [x-1]"<<endl;
        cout<<iSearch[x]<<" -> iSearch [x]"<<endl;

    }
    iSearch[1] = 2;

    iUsed++;
    cout<<"added a 2"<<endl;
    for(int i = 0; i < iUsed; i++){
        cout<<iSearch[i]<<endl;
    }

    //adding 45 at index 2
    index = 2;
    for(int x = iUsed; x > index; x--){
        iSearch[x] = iSearch[x - 1];
    }
    iSearch[index] = 45;
    cout<<"add 45"<<endl;
    for(int x = 0; x < iUsed; x++){
        cout<<iSearch[x]<<endl;
    }

    //delete 45
    index = 2;
    for(int x = index; x < iUsed - 1; x++){
        iSearch[x] = iSearch[x+1];
    }
    iUsed--; //one fewer array element
    cout<<"delete 45"<<endl;
    for(int x = 0; x < iUsed; x++){
        cout<<iSearch[x]<<endl;
    }

    //Write a delete function
    //takes the array, and a value to delete, and iUsed as arguments
    //returns success or failure

    cout<<"Delete # from succ array"<<endl;

    bool success = false;
    success = deleteArray(iSearch, 2, iUsed);
    if(success){
        iUsed--;
    }else{
        cout<<"not found"<<endl;
    }



}
