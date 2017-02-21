#include <iostream>

using namespace std;

int EnterHeight(){
    cout<<"Enter the height of a mountain as an integer."<<endl;
    int InputMountainHeight;
    cin >> InputMountainHeight;

    return InputMountainHeight;
}

int main(){

int Input = EnterHeight();
bool NumIsGood = false;

while(NumIsGood == false){
    if (Input == 29029 || Input == 28251 || Input == 28169){
        NumIsGood = true;
        if(Input == 29029){
            cout<<"Height Rank: 1, Height: 29,029ft., Name: Mount Everest"<<endl;
        }
        else if(Input ==28251){
            cout<<"Height Rank: 2, Height: 28,251ft., Name: K2"<<endl;
        }
        else if(Input == 28169){
            cout<<"Height Rank: 3, Height: 28,169ft., Name: Mount Everest"<<endl;
        }

    }//end if
    else {
            cout<<"Height does not match that of the three mountains. Please enter a correct height.\n"<<endl;
            Input = EnterHeight();
            NumIsGood = false;
        }
}//end while


return 0;
}
