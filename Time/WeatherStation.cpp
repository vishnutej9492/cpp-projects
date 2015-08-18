#include "Time.h"
#include "WeatherStation.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>

using namespace std;

/** 
 * Constructor that takes the name, latitude and longitude of the station 
 *
 * @param name Name of the station 
 * @param latitude latitude of the station.  Negative values are south,
 * positive values are north
 * @param longitude longitude of the station. Negative values are west,
 * positive values are east
*/
WeatherStation::WeatherStation( const std::string &name, 
                   const double &latitude,
                   const double &longitude )
{
	this->latitude=latitude;
	this->longitude=longitude;
	this->name=name;
	currentObservation=0;
}


/**
 * Record temperature at a particular time
 *
 * @param time Time of the observation
 * @param temperature Temperature of the observation
 */
void WeatherStation::recordObservation( Time time, float temperature )
{
	if(currentObservation>=maxObservations)
		return;
	observations[currentObservation].temperature=temperature;
	observations[currentObservation].time=time;
	currentObservation++;
}

/**
 * Return the average of all observations
 *
 * @return average temperature
 */
float WeatherStation::getAverageTemperature()
{
	if(currentObservation==0)
		 throw overflow_error("Not enough observations recorded");;
	float sum=0;
	for(int i=0;i<currentObservation;i++)
	{
		sum+=observations[i].temperature;
	}
	return sum/currentObservation;
}

/**
 * Return the time the high temperature was observed
 *
 * @return the time the high temperature was observed
 */
Time WeatherStation::getTimeOfHighTemp() const
{
	int index=0;
	for(int i=0;i<currentObservation;i++)
	{
		if(observations[i].temperature>observations[index].temperature)
		{
			index=i;
		}
	}
	return observations[index].time;	
}

/**
 * Return the time the low temperature was observed
 *
 * @return the time the low temperature was observed
 */
Time WeatherStation::getTimeOfLowTemp() const
{
	int index=0;
	for(int i=0;i<currentObservation;i++)
	{
		if(observations[i].temperature<observations[index].temperature)
		{
			index=i;
		}
	}
	return observations[index].time;	
}

/**
 * Get the high temperature of the day
 *
 * @return the daily high temperature
 */
float WeatherStation::getValueOfHighTemp() const
{
	int index=0;
	for(int i=0;i<currentObservation;i++)
	{
		if(observations[i].temperature>observations[index].temperature)
		{
			index=i;
		}
	}
	return observations[index].temperature;	
}


   
/**
 * Get the low temperature of the day
 *
 * @return the daily low temperature
 */
float WeatherStation::getValueOfLowTemp() const
{
	int index=0;
	for(int i=0;i<currentObservation;i++)
	{
		if(observations[i].temperature<observations[index].temperature)
		{
			index=i;
		}
	}
	return observations[index].temperature;	
}

/**
 * Get the name of the station
 *
 * @return the name of the station
 */
std::string WeatherStation::getStationName() const
{
	return this->name;
}
    
/**
 * Return the latitude of the station
 *
 * @return the station's latitude
 */
double WeatherStation::getStationLatitude() const
{
	return this->latitude;
}

/**
 * Return the longitude of the station
 *
 * @return the station's longitude
 */
double WeatherStation::getStationLongitude() const
{
	return this->longitude;
}

