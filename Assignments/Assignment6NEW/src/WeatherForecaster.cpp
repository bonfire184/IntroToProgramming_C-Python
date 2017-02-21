#include "WeatherForecaster.h"
#include <iostream>
using namespace std;

WeatherForecaster::WeatherForecaster(){
    index = 0;
    arrayLength = 984;
}
WeatherForecaster::~WeatherForecaster(){}

void WeatherForecaster::addDayToData(ForecastDay ReceivedForecast){
    yearData[index] = ReceivedForecast; //When the function receives a struct, it adds the struct to the next index of the yearData array
    index+=1;

}
void WeatherForecaster::printDaysInData(){
    for(int i = 0; i <= 984; i++){
        if (yearData[i].day == yearData[i].forecastDay){
            cout<<yearData[i].day<<endl;//prints each day where actual day matches forecast day
        }
    }
} //prints the unique dates in the data

void WeatherForecaster::printForecastForDay(std::string input){

    for(int i = 0; i <= 984; i++){
        if (yearData[i].day == yearData[i].forecastDay && yearData[i].day == input){//ensures actual and forecast day match and also match the day they want a forecast for
            cout<<" "<<endl;
            cout<<"Forecast for "<<input<<": "<<endl;
            cout<<"H: "<<yearData[i].highTemp<<endl;
            cout<<"L: "<<yearData[i].lowTemp<<endl;
            cout<<"Humidity: "<<yearData[i].humidity<<endl;
            cout<<"Avg. wind: "<<yearData[i].avgWind<<endl;
            cout<<"Avg. wind direction: "<<yearData[i].avgWindDir<<endl;
            cout<<"Max. wind: "<<yearData[i].maxWind<<endl;
            cout<<"Precipitation: "<<yearData[i].precip<<endl;
            cout<<" "<<endl;
            break;
        }
        if(i == 984){
            cout<<"Date not found."<<endl;//if the loop finishes but doesn't stop at any date, this will say date not found
        }
    }


}
void WeatherForecaster::printFourDayForecast(string input1){
    for(int i = 0; i <= 984; i++){
        if (yearData[i].day == yearData[i].forecastDay && yearData[i].day == input1){
            for(int y = 0; y < 4; y++){
                cout<<"Forecast for "<<yearData[i+y].forecastDay<<": "<<endl;   //Will first find matching day and forecast day and then print forecasts for the following 3 days
                cout<<"H: "<<yearData[i+y].highTemp<<endl;
                cout<<"L: "<<yearData[i+y].lowTemp<<endl;
                cout<<"Humidity: "<<yearData[i+y].humidity<<endl;
                cout<<"Avg. wind: "<<yearData[i+y].avgWind<<endl;
                cout<<"Avg. wind direction: "<<yearData[i+y].avgWindDir<<endl;
                cout<<"Max. wind: "<<yearData[i+y].maxWind<<endl;
                cout<<"Precipitation: "<<yearData[i+y].precip<<endl;
                cout<<" "<<endl;
                break;
            }
        }
        if(i == 984){
            cout<<"Date not found."<<endl; //If array index makes it to the end without breaking, then call the date not found
        }
    }
}

double WeatherForecaster::calculateTotalPrecipitation(){
   double totalRain = 0;
   for(int i = 0; i <= 984; i++){
        if(yearData[i].day == yearData[i].forecastDay && yearData[i].precip > 0){//if the actual day matches the forecast day and there is some precipitation, it is added to the running total
            totalRain += yearData[i].precip;
        }
   }
   return totalRain;
}

void WeatherForecaster::printLastDayItRained(){
    for(int i = 984; i >= 0; i--){
        if(yearData[i].day == yearData[i].forecastDay && yearData[i].precip > 0){//loops backwards and finds the last day with rain
            cout<<"Last day it rained: "<<yearData[i].day<<endl;
            break;
        }
    }
}

void WeatherForecaster::printLastDayAboveTemperature(int Temp){
    for(int i = 984; i >= 0; i--){
        if(yearData[i].day == yearData[i].forecastDay && yearData[i].highTemp > Temp){//loops backwards; if the high temp is greater than the input temp, will stop at that value
            cout<<"It was above "<<Temp<<" on "<<yearData[i].day<<endl;
            break;
        }
        if(i == 0){
            cout<<"No days above that temperature."<<endl;//if it gets to the end of the array and no temp found
        }
    }
}

void WeatherForecaster::printTemperatureForecastDifference(std::string input2){
    for(int i = 0; i <= 984; i++){
        if (yearData[i].day == yearData[i].forecastDay && yearData[i].day == input2){
            cout<<"Forecast for "<<input2<<" issued on "<<yearData[i-3].day<<endl;//Every 3 indexes back from initial special day/forecast combo will be a forecast for that day (up to 3 iterations back)
            cout<<"H: "<<yearData[i-3].highTemp<<endl;
            cout<<"L: "<<yearData[i-3].lowTemp<<endl;

            cout<<"Forecast for "<<input2<<" issued on "<<yearData[i-6].day<<endl;
            cout<<"H: "<<yearData[i-6].highTemp<<endl;
            cout<<"L: "<<yearData[i-6].lowTemp<<endl;

            cout<<"Forecast for "<<input2<<" issued on "<<yearData[i-9].day<<endl;
            cout<<"H: "<<yearData[i-9].highTemp<<endl;
            cout<<"L: "<<yearData[i-9].lowTemp<<endl;

            cout<<"Actual forecast for"<<input2<<endl;
            cout<<"H: "<<yearData[i].highTemp<<endl;
            cout<<"L: "<<yearData[i].lowTemp<<endl;

        }
    }
}

void WeatherForecaster::printPredictedVsActualRainfall(int daysOut){
    double TotalPredicted = 0;
    double TotalActual = 0;

    for(int i = 4; i <= 980; i++){
        if(yearData[i].day == yearData[i].forecastDay && yearData[i - ((3)*daysOut)].forecastDay == yearData[i].day){//loop stops at every special date/prediction combo then checks to see if the prediction 3 array indexes back (times daysOut) is for the same date. If so, it will add the precipitation from predictive date to predicted and precipitation from actual date to actual
            TotalPredicted += yearData[i - ((3)*daysOut)].precip;
            TotalActual += yearData[i].precip;
        }
    }
    cout<<"Predicted rainfall in "<<daysOut<<"-day forecast"<<endl;
    cout<<TotalPredicted<<" inches"<<endl;

    cout<<"Actual rainfall in "<<daysOut<<"-day forecast"<<endl;
    cout<<TotalActual<<" inches"<<endl;

    cout<<"Difference: "<<TotalPredicted-TotalActual<<endl;//.21, .48, 2.19
} //argument is days out, such as 1 = 1 day out, 2 = 2 days out, 3 = 3 days out

string WeatherForecaster::getFirstDayInData(){
    return yearData[0].day;//return first item in the array
}
string WeatherForecaster::getLastDayInData(){
    return yearData[980].day;//return last item in the array
}
