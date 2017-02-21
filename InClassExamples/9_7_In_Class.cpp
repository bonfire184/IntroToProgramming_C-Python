#include <iostream>

using namespace std;

int a = 6;

#define MPG 20.2 //macros
#define STR "mySTR"

const int intConst = 100;

/*void scopeTest(){
    cout<<a<<endl;
}*/


int main(){
    int a = 15;//what is the scope of a - local to main, can be seen in main
    //scopeTest();
    cout<<"Inside Main:"<<a<<endl;
    a++;
    cout<<"main:"<<a<<endl;
    //scopeTest();
    cout<<"mpg:"<<MPG<<endl;
    cout<<STR<<endl;

}
