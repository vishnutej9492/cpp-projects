#include "Time.h"
#include "WeatherStation.h"
#include "WeatherStationWithWind.h"
#include "WeatherStationWithRain.h"
#include "WeatherStationWithWindAndRain.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>


int main()
{
	WeatherStationWithWindAndRain station("McMurdo Station",-77.85,166.667);
	while(!std::cin.eof())
	{
		Time time;
		try
		{
			std::cout<<"Enter time (hh:mm): ";
			std::cin>>time;
		}
		catch(std::overflow_error ex)
		{
			std::cerr<<"General Exception occurred Time is out of range"<<std::endl;
			continue;
		}
		catch(std::underflow_error ex)
		{
			std::cerr<<"General Exception occurred Time is out of range"<<std::endl;
			continue;
		}
		if(std::cin.eof())
			break;
		float temperature,wind,windDirection,rain;
		std::cout<<"Enter temperature (deg C): ";
		std::cin>>temperature;
		std::cout<<"Enter wind speed (mph): ";
		std::cin>>wind;
		std::cout<<"Enter wind direction (deg): ";
		std::cin>>windDirection;
		std::cout<<"Enter rain (1/100th inch): ";
		std::cin>>rain;
		std::cout<<std::endl;	
		try
		{
			station.recordObservation(time,temperature,wind,windDirection,rain);
		}
		catch(std::overflow_error ex)
		{
			std::cerr <<  "General exception occurred: "<<ex.what()<<std::endl;
			break;
		}
		catch(std::underflow_error ex)
		{
			std::cerr <<  "General exception occurred: "<<ex.what()<<std::endl;
			break;
		}

	}
	std::cout<<std::fixed;
	std::cout<<"\n\nWeather Data for "<<((WeatherStationWithWind*)&station)->getStationName()<<" ("<<std::setprecision(2)<<
		((WeatherStationWithWind*)&station)->getStationLatitude()<<", "<<std::setprecision(3)<<((WeatherStationWithWind*)&station)->getStationLongitude()<<")"<<std::endl;
	std::cout<<"-------------------------------------------------------------"<<std::endl;
	try
	{
		std::cout<<"Average Temperature: "<<(int)((WeatherStationWithWind*)&station)->getAverageTemperature()<<" degree(s) C"<<std::endl;
		std::cout<<"High Temperature was "<<(int)((WeatherStationWithWind*)&station)->getValueOfHighTemp()<<" degree(s) C at "<<((WeatherStationWithWind*)&station)->getTimeOfHighTemp()<<std::endl;
		std::cout<<"Low Temperature was "<<(int)((WeatherStationWithWind*)&station)->getValueOfLowTemp()<<" degree(s) C at "<<((WeatherStationWithWind*)&station)->getTimeOfLowTemp()<<std::endl;
		std::cout<<"Average Wind Speed: "<<std::setprecision(1)<<station.getAverageWind()<<"mph"<<std::endl;
		std::cout<<"Average Wind Direction: "<<std::setprecision(0)<<(int)station.getAverageWindDirection()<<" degree(s)"<<std::endl;
		std::cout<<"Total Rain: "<<std::setprecision(2)<<station.getTotalRain()/100.0<<"\""<<std::endl;
	}
	catch(std::overflow_error ex)
	{
		std::cerr <<  "General exception occurred: "<<ex.what()<<std::endl;
	}
	catch(std::underflow_error ex)
	{
		std::cerr <<  "General exception occurred: "<<ex.what()<<std::endl;
	}
	return 0;
}
