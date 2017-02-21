#include <iostream>
#include <stdlib.h>

using namespace std;

void myFunction(int *x){
    //update the value of x
    cout<<"in function"<<endl;
    cout<<"address that x points to"<<x<<endl;
    *x = 40;

}

int main(){
    //atoi
    string temp="12";
    int x;
    x = atoi(temp.c_str());
    cout<<x+5<<endl;
    //x = stoi(temp);
    //cout<<x<<endl;

    //stuff['b'][50]

    /*for(int i = 0; i < length of stuff; i++){
        if stuff[i][0] == 'b'{
            do more stuff
        }
    }*/

    //pointers
    cout<<"addr of x"<<&x<<endl;//Ampersand gives address of variable x
    int *xPtr = &x; //Astrix means you have created a pointer variable (pointer x = the value at the address of variable x)

    cout<<"Value of *xPtr: "<<*xPtr<<", Address pointed to by *xPtr: "<<xPtr<<endl;

    myFunction(xPtr);

    *xPtr++;

    cout<<"*xPtr after function: "<<*xPtr<<endl; //this statement will change the value of x
    cout<<"x after function"<<x<<endl;
    cout<<&x+1<<endl;
}
