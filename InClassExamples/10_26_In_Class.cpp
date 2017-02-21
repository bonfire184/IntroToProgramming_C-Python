#include <iostream>
using namespace std;


struct WeatherData{
    int temp;
    int humidity;
};

void memoryTest(){
    int *a = new int;
    //do stuff with a
    delete a;
}

void modify(WeatherData *wd){
    for(int i = 0; i <10; i++){
        wd[i].temp = i;
    }
}

int main(){

    WeatherData *wd = new WeatherData[10];
    wd[0].humidity = 40;
    wd[0].temp = 20;

    modify(wd);


    for(int i = 0; i < 10; i++){
        cout<<wd[i].temp<<endl;
    }
    //what happens when we pass wd as an argument to a function, then modify it in the function?



    int b = 5;
    int *a = &b;
    cout<<*a<<endl;
    cout<<&b<<endl;
    cout<<a<<endl;

    int *a2 = new int;
    cout<<a2<<endl;

    cout<<"Enter an array size: ";
    int temp;
    cin>>temp;
    int *a3 = new int[temp];//at run time the array is sized

    //free that dang meme-ory
    delete a2;
    delete []a3;
}
