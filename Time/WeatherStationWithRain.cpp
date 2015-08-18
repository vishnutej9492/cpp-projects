#include "Time.h"
#include "WeatherStation.h"
#include "WeatherStationWithRain.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>


/**
 * Record temperature and wind at a particular time
 *
 * @param time Time of the observation
 * @param temperature Temperature of the observation
 * @param wind wind of the observation
 * @param deg wind of the observation
 */
void WeatherStationWithRain::recordObservation(Time time, float temperature, float rain)
{
	WeatherStation::recordObservation(time,temperature);
	this->rain[currentObservation-1]=rain;
}

/**
 * Return the total rain of all observations
 *
 * @return average wind speed
 */
float WeatherStationWithRain::getTotalRain()
{

	float sum=0;
	for(int i=0;i<currentObservation;i++)
	{
		sum+=rain[i];
	}
	return sum;
}

WeatherStationWithRain::WeatherStationWithRain( const std::string &name, 
                   const double &latitude,
				   const double &longitude ):WeatherStation(name,latitude,longitude)
{
}
