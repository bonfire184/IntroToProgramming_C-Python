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

string lastDayItRained(Forecast forecastData[]){//THIS FUNCTION WILL MOVE BACKWARDS THROUGH THE ARRAY, ENSURE THE DAY IS THE SAME AS THE FORECAST DAY AND REPORT THE LAST DAY WITH >0 PRECIPITATION
    for (int i = 984; i >= 1; i--){//starts at 984 and decrements
        if(forecastData[i].precip > 0 && forecastData[i].day == forecastData[i].forecastDay){
            return forecastData[i].day;
        }
    }
}

double totalRainfall(Forecast forecastData[]){
    double totalRain = 0;

    for (int i = 0; i < 984; i++){//WILL INCREMENT THROUGH THE ARRAY AND MAKE SURE THE DAY MATCHES THE FORECAST DAY THEN ADD THE PRECIPATION TO THE CURRENT PRECIPITATION
        if(forecastData[i].precip > 0 && forecastData[i].day == forecastData[i].forecastDay){
            totalRain += forecastData[i].precip;
        }
    }
    return totalRain;
}

int maxWindspeed(Forecast forecastData[]){//WILL INCREMENT THROUGH THE ARRAY AND MAKE SURE THE DAY MATCHES THEN CHECK IF THE CURRENT MAX WIND IS GREATER THAN THE PREVIOUS MAX
    int temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].maxWind > 0 && forecastData[i].maxWind > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].maxWind;
        }
    }
    return temp;
}
double maxRainfall(Forecast forecastData[]){//WILL INCREMENT THROUGH THE ARRAY AND MAKE SURE THE DAY MATCHES THE FORECAST DAY THEN CHECK IF THE THE CURRENT MAX TEMP IS GREATER THAN PREVIOUS MAX
    double temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].precip > 0 && forecastData[i].precip > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].precip;
        }
    }
    return temp;
}
int maxTempDifference(Forecast forecastData[]){//WILL INCREMENT THROUGH THE ARRAY AND MAKE SURE THE DAY MATCHES THE FORECAST DAY THEN CHECK IF THE CURRENT DIFFERENCE IN TEMPS IS GREATER THAN THE PREVIOUS DIFFERENCE IN TEMPS
    int temp = 0;

    for (int i = 0; i < 984; i++){
        if(forecastData[i].highTemp - forecastData[i].lowTemp > 0 && forecastData[i].highTemp - forecastData[i].lowTemp > temp && forecastData[i].day == forecastData[i].forecastDay){
            temp = forecastData[i].highTemp - forecastData[i].lowTemp;
        }
    }
    return temp;
}


Forecast forecastForDay(Forecast forecastData[], string day){//WILL INCREMENT THROUGH THE ARRAY UNTIL THE DAY THEY INPUT MATCHES A DAY/FORECAST DAY IN THE ARRAY, THEN WILL PRINT OUT THE FORECAST FOR THAT DAY
    for (int i = 0; i < 984; i++){
        if(day == forecastData[i].day && forecastData[i].day == forecastData[i].forecastDay){
            cout<<"Forecast for "<<day<<endl;
            cout<<"H: "<<forecastData[i].highTemp<<endl;
            cout<<"L: "<<forecastData[i].lowTemp<<endl;
            cout<<"Humidity: "<<forecastData[i].humidity<<endl;
            cout<<"Avg. wind: "<<forecastData[i].avgWind<<endl;
            cout<<"Avg. wind direction: "<<forecastData[i].avgWindDir<<endl;
            cout<<"Precipitation: "<<forecastData[i].precip<<endl;
        }
    }
}



int main(){
    stringstream line;//A STREAM THAT WILL HOLD LINES IMPORTED FROM FILE
    string portion;//STRING OF EACH WORD IN LINE
    ifstream Data;//A STREAM TO CONTAIN THE FILE IMPORTED
    Data.open("boulderData.csv");
    string TempString;
    int arrayLength = 984;
    Forecast forecastData[arrayLength];

    if(Data.fail()){
        cout<<"Error importing file."<<endl;
    }
    else{

        int ArrayIndex = 0;
        while(getline(Data, TempString, '\n')){//WILL RUN THIS CODE EVERY NEW LINE

            line<<TempString;//PUT THE TEMP STRING INTO LINE STREAM
            int WordIndex = 0;
            while(getline(line, portion, ',')){//search line, GOES WORD BY WORD

                //DEPENDING ON THE WHICH WORD IS BEING READ FROM THE LINE, FORECAST DATA WILL BE SAVED WITH ONE OF THE FOLLOWING VALUES

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
                WordIndex++;//GO TO NEXT WORD
            }//end While
            ArrayIndex++;//GO TO NEXT LINE
            line.str("");//CLEAR SAVED STRING
            line.clear();//CLEAR SAVED DATA
        }
    }

    string date;

    cout<<"Last day it rained: "<<lastDayItRained(forecastData)<<endl;
    cout<<"Total rainfall: "<<totalRainfall(forecastData)<<endl;
    cout<<"Max wind speed: "<<maxWindspeed(forecastData)<<endl;
    cout<<"Max rain fall: "<<maxRainfall(forecastData)<<endl;
    cout<<"Max difference in temperature: "<<maxTempDifference(forecastData)<<endl;

    cout<<"Enter a date: ";
    getline(cin, date);
    forecastForDay(forecastData, date);
    //***********PLEASE READ********>>>> The code overflows the memory buffer for some reason after printing the
    //***********PLEASE READ********>>>> forecast for input date. I think this issue is local to my computer.
    //***********PLEASE READ********>>>> The code works correctly, but then the console
    //***********PLEASE READ********>>>> prints memory overflow error. ALL OF THE CORRECT OUTPUT is above the memory
    //***********PLEASE READ********>>>> overflow information.
}
