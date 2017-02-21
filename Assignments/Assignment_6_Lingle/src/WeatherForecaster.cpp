#include "WeatherForecaster.h"
#include <iostream>

WeatherForecaster::WeatherForecaster(){}
WeatherForecaster::~WeatherForecaster(){}
void WeatherForecaster::addDayToData(ForecastDay){}
void WeatherForecaster::printDaysInData(){} //prints the unique dates in the data
void WeatherForecaster::printForecastForDay(std::string){}
void WeatherForecaster::printFourDayForecast(std::string){}
double WeatherForecaster::calculateTotalPrecipitation(){}
void WeatherForecaster::printLastDayItRained(){}
void WeatherForecaster::printLastDayAboveTemperature(int){} //argument is the temperature
void WeatherForecaster::printTemperatureForecastDifference(std::string){}
void WeatherForecaster::printPredictedVsActualRainfall(int){} //argument is days out, such as 1 = 1 day out, 2 = 2 days out, 3 = 3 days out
std::string getFirstDayInData(){}
std::string getLastDayInData(){}
