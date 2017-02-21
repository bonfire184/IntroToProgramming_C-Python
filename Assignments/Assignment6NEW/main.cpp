#include "WeatherForecaster.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

//HAYDEN LINGLE
//RECITATION WITH CAMILLA TUESDAYS 2PM
//ASSIGNMENT 6

int main()
{
    WeatherForecaster instWeatherForecaster;
    ForecastDay instForecast;


    string TempString;
    string portion;

    ifstream Data;
    stringstream line;
    Data.open("boulderData.txt");


    if(Data.fail()){
        cout<<"Error importing file."<<endl;
    }
    else{

        int ArrayIndex = 0;
        while(getline(Data, TempString, '\n')){//Searching through Data (contains whole file), put all data into TempString, end at linebreak

            line<<TempString;//puts the entire line into a stream to be analyzed below
            int WordIndex = 0;
            while(getline(line, portion, ',')){//search line word by word
                if(WordIndex == 0){
                    instForecast.day = portion;
                }
                else if(WordIndex == 1){
                    instForecast.forecastDay = portion;
                }
                else if(WordIndex == 2){
                    instForecast.highTemp = stoi(portion.substr(2));
                }
                else if(WordIndex == 3){
                    instForecast.lowTemp = stoi(portion.substr(2));
                }
                else if(WordIndex == 4){
                    instForecast.humidity = stoi(portion);
                }
                else if(WordIndex == 5){
                    instForecast.avgWind = stoi(portion);
                }
                else if(WordIndex == 6){
                    instForecast.avgWindDir = portion;
                }
                else if(WordIndex == 7){
                    instForecast.maxWind = stoi(portion);
                }
                else if(WordIndex == 8){
                    instForecast.maxWindDir = portion;
                }
                else if(WordIndex == 9){
                    instForecast.precip = stod(portion);
                }//end else
                WordIndex++;
            }//end While
            instWeatherForecaster.addDayToData(instForecast);
            ArrayIndex++;
            line.str("");
            line.clear();
        }
    }

    //ALL FUNCTION CALLS BELOW

    cout<<"Forecast statistics:"<<endl;
    instWeatherForecaster.printLastDayItRained();
    cout<<"Total rainfall: "<<instWeatherForecaster.calculateTotalPrecipitation()<<endl;

    cout<<"First date in data: "<<instWeatherForecaster.getFirstDayInData()<<endl;
    cout<<"Last date in data: "<<instWeatherForecaster.getLastDayInData()<<endl;

    string DayForForecast;
    cout<<"Enter day to print forecast:";
    cin>>DayForForecast;
    instWeatherForecaster.printForecastForDay(DayForForecast);

    cout<<"Enter day to print forecast for following 3 days:";
    cin>>DayForForecast;
    instWeatherForecaster.printFourDayForecast(DayForForecast);

    instWeatherForecaster.printDaysInData();

    int DaysOut;
    cout<<"Enter number of forecast days away:";
    cin>>DaysOut;
    instWeatherForecaster.printPredictedVsActualRainfall(DaysOut);
    //predicted versus actual

    cout<<"Enter day to print Temperature Forecast Data:";
    cin>>DayForForecast;
    instWeatherForecaster.printTemperatureForecastDifference(DayForForecast);
    //print tempForecastData

    int AboveTemp;
    cout<<"Enter temp to find last day above that temp.";
    cin>>AboveTemp;
    instWeatherForecaster.printLastDayAboveTemperature(AboveTemp);


}
