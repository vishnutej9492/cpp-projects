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


/**
 * Record temperature and wind at a particular time
 *
 * @param time Time of the observation
 * @param temperature Temperature of the observation
 * @param wind wind of the observation
 * @param deg wind of the observation
 * @param rain rain of the observation
 */
void WeatherStationWithWindAndRain::recordObservation( Time time, float temperature, float wind, float windDirection,float rain)
{
	WeatherStationWithWind::recordObservation(time, temperature,wind,windDirection);
	this->rain[WeatherStationWithWind::currentObservation-1]=rain;
	WeatherStationWithRain::currentObservation=WeatherStationWithWind::currentObservation;
}

WeatherStationWithWindAndRain::WeatherStationWithWindAndRain( const std::string &name, 
                   const double &latitude,
                   const double &longitude )
				   :WeatherStationWithWind(name,latitude,longitude)
{
}
