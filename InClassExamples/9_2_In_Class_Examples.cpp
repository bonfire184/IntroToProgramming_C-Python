#include <iostream>

using namespace std;

//functions

int addNums(int a, int b){
    return a + b;
}

//doesn't return a value
void printMsg(string msg){
    cout<<msg<<endl;
}

int main(){
    int a;
    string hello = "hello world";
    double e = 4.5;

    cout<<"hello world"<<endl;
    int x = addNums(5, 6);
    cout<<"x = "<<x<<endl;

    printMsg("hello world");

    //conditionals and loops
    //conditionals
    int intA = 5;
    if(intA < 5){
        cout<<"a < 5"<<endl;
    }
    else if(intA > 5){
        cout<<"a > 5"<<endl;
    }
    else{
        cout<<"intA = 5"<<endl;
    }

    int intB = 6;
    //conditional for when intA < 5 and intB = 6
    if(intA == 4 && intB == 6){
        cout<<"intA and intB"<<endl;
    }
    if(intA > 5|| intB ==6){
        cout<<"true that intA > 5 or intB = 6"<<endl;
    }
    if(intA == 5 ^ intB ==6){
        cout<<"xor"<<endl;
    }



    int intCounter = 0;
    int i = 1;
    int j = i++;
    cout<<"i = "<<i<<" j = "<<j<<endl;
    int intx = 1;
    int y = ++intx;
    cout<<"x = "<<intx<<" y = "<<y<<endl;

    bool flag = false;
    while(flag == false){
        cout<<intCounter<<endl;
        intCounter++;
        if(intCounter >= 5){
            flag=true;
        }
    }

    while(intCounter <= 5){
        cout<<intCounter<<endl;
        intCounter += 1;
    }

    cout<<"for loop"<<endl;
    for(int i = 0; i < 10; i++){
        cout<<i<<endl;
    }

    cout<<"i = "<<i<<endl;


    return 0;
}
