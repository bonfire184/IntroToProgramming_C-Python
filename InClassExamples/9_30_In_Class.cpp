#include <iostream>

using namespace std;

struct myStruct{
    string name;
    int score;
    //this is the constructor
    myStruct(string n, int s){
        name = n;
        score = s;
    }
    myStruct(){}
};

struct WeatherData{
    double temp;
    double humidity;
    double wind;
};

struct Team{
    string name;
    int wins;
    int losses;
    Team(string n, int w, int l){
        n = name;w = wins;l = losses;
    }
};

int main(){
    WeatherData wd;
    wd.humidity = 45;
    wd.temp = 34;
    wd.wind = 12;

    cout<<wd.humidity<<endl;
    cout<<wd.temp<<endl;
    cout<<wd.wind<<endl;

    //array of structs
    WeatherData wdArray[10];//type, variable name, array size
    for(int i = 0; i < 10; i++){
        wdArray[i].humidity = i+10;
        wdArray[i].temp = i * 10;
        wdArray[i].wind = 100.0/i;
    }
    for(int i = 0; i < 10; i++){
        cout<<"i = "<<i<<endl;
        cout<<wdArray[i].humidity<<endl;
        cout<<wdArray[i].temp<<endl;
        cout<<wdArray[i].wind<<endl;
    }

    //create a struct called Team
    //each Team has name, wins, loses
    //LA Dodgers 91 68
    //San Francisco 84 75
    //Colorado 74 85
    //San Diego 68 91
    //Arizona 66 93

    myStruct ms; //variable name is ms
    ms.name = "Hayden";
    ms.score = 85;

    //call the constructor
    myStruct ms2("hayden", 86);
    cout<<ms.name<<endl;
    cout<<ms2.score<<endl;
}
