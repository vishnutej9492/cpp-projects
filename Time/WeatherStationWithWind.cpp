#include "Time.h"
#include "WeatherStation.h"
#include "WeatherStationWithWind.h"
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>

using namespace std;

/**
 * Record temperature and wind at a particular time
 *
 * @param time Time of the observation
 * @param temperature Temperature of the observation
 * @param wind wind of the observation
 * @param deg wind of the observation
 */
void WeatherStationWithWind::recordObservation( Time time, float temperature, float wind, float windDirection)
{
	WeatherStation::recordObservation(time,temperature);
	windObservations[currentObservation-1].wind=wind;
	windObservations[currentObservation-1].windDirection=windDirection;
}


/**
 * Return the average wind spreed of all observations
 *
 * @return average wind speed
 */
float WeatherStationWithWind::getAverageWind()
{
	if(currentObservation==0)
		 throw overflow_error("Not enough observations recorded");;
	float sum=0;
	for(int i=0;i<currentObservation;i++)
	{
		sum+=windObservations[i].wind;
	}
	return sum/currentObservation;
}

#define M_PIVALUE 3.1415926535 
/**
 * Return the average wind direction of all observations
 *
 * @return average wind speed
 */
float WeatherStationWithWind::getAverageWindDirection()
{
	if(currentObservation==0)
		 throw overflow_error("Not enough observations recorded");;
	float sum=0;
	float sum1=0;
	for(int i=0;i<currentObservation;i++)
	{
		sum+=sin(M_PIVALUE*windObservations[i].windDirection/180.0);
		sum1+=cos(M_PIVALUE*windObservations[i].windDirection/180.0);
	}
	return 180.0*atan2(sum,sum1)/M_PIVALUE;
}

WeatherStationWithWind::WeatherStationWithWind( const std::string &name, 
                   const double &latitude,
                   const double &longitude )
				   :WeatherStation(name,latitude,longitude)
{

}
