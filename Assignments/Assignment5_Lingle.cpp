#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

struct Forecast{
    string day;
    string forecastDay;
    int highTemp;
    int lowTemp;
    int humidity;
    int avgWind;
    string avgWindDir;
    int maxWind;
    string maxWindDir;
    double precip;
};

string lastDayItRained(Forecast forecastData[]){
    for (int i = 984; i >= 1; i--){
        if(forecastData[i].precip > 0 && forecastData[i].day == forecastData[i].forecastDay){
            return forecastData[i].day;
        }
    }
}

double totalRainfall(Forecast forecastData[]){
    double totalRain = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].precip > 0 && forecastData[i].day == forecastData[i].forecastDay){
            totalRain += forecastData[i].precip;
        }
    }
    return totalRain;
}

int maxWindspeed(Forecast forecastData[]){
    int temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].maxWind > 0 && forecastData[i].maxWind > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].maxWind;
        }
    }
    return temp;
}
double maxRainfall(Forecast forecastData[]){
    double temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].precip > 0 && forecastData[i].precip > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].precip;
        }
    }
    return temp;
}
int maxTempDifference(Forecast forecastData[]){
    int temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].highTemp - forecastData[i].lowTemp > 0 && forecastData[i].highTemp - forecastData[i].lowTemp > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].highTemp - forecastData[i].lowTemp;
        }
    }
    return temp;
}


Forecast forecastForDay(Forecast forecastData[], string day){

//    boost::multi_array<int, 3> x (boost::extents[300][300][4]);



    for (int i = 0; i <= 983; i++){
        if(forecastData[i].day == day && forecastData[i].day == forecastData[i].forecastDay){


            cout<<"Forecast for "<<day<<endl;
            cout<<"H: "<<forecastData[i].highTemp<<endl;
            cout<<"L: "<<forecastData[i].lowTemp<<endl;
            cout<<"Humidity: "<<forecastData[i].humidity<<endl;
            cout<<"Avg. wind: "<<forecastData[i].avgWind<<endl;
            cout<<"Avg. wind direction: "<<forecastData[i].avgWindDir<<endl;
            cout<<"Max wind: "<<forecastData[i].maxWind<<endl;
            cout<<"Max wind direction: "<<forecastData[i].maxWindDir<<endl;
            cout<<"Precipitation: "<<forecastData[i].precip<<endl;
        }
    }
}



int main(){
    int arrayLength = 984;
    Forecast forecastData[arrayLength];

    string TempString;
    string portion;

    ifstream Data;
    stringstream line;
    Data.open("boulderData.csv");


    if(Data.fail()){
        cout<<"Error importing file."<<endl;
    }
    else{

        int ArrayIndex = 0;
        while(getline(Data, TempString, '\n')){

            line<<TempString;
            int WordIndex = 0;
            while(getline(line, portion, ',')){//search line
                if(WordIndex == 0){
                    forecastData[ArrayIndex].day = portion;
                }
                else if(WordIndex == 1){
                    forecastData[ArrayIndex].forecastDay = portion;
                }
                else if(WordIndex == 2){
                    forecastData[ArrayIndex].highTemp = stoi(portion.substr(2));
                }
                else if(WordIndex == 3){
                    forecastData[ArrayIndex].lowTemp = stoi(portion.substr(2));
                }
                else if(WordIndex == 4){
                    forecastData[ArrayIndex].humidity = stoi(portion);
                }
                else if(WordIndex == 5){
                    forecastData[ArrayIndex].avgWind = stoi(portion);
                }
                else if(WordIndex == 6){
                    forecastData[ArrayIndex].avgWindDir = portion;
                }
                else if(WordIndex == 7){
                    forecastData[ArrayIndex].maxWind = stoi(portion);
                }
                else if(WordIndex == 8){
                    forecastData[ArrayIndex].maxWindDir = portion;
                }
                else if(WordIndex == 9){
                    forecastData[ArrayIndex].precip = stod(portion);
                }//end else
                WordIndex++;
            }//end While
            ArrayIndex++;
            line.str("");
            line.clear();
        }
    }



    cout<<"Last Day it Rained: "<<lastDayItRained(forecastData)<<endl;
    cout<<"Total Rainfall: "<<totalRainfall(forecastData)<<endl;
    cout<<"Maximum Wind Speed: "<<maxWindspeed(forecastData)<<endl;
    cout<<"Maximum Rainfall: "<<maxRainfall(forecastData)<<endl;
    cout<<"Maximum Temperature Difference: "<<maxTempDifference(forecastData)<<endl;

    string date;
    cout<<"Enter a date: ";
    getline(cin, date);
    Forecast dayForecast = forecastForDay(forecastData, date);
}




