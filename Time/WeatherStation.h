#ifndef __WEATHER_STATION_H__
#define __WEATHER_STATION_H__

/**
 * @file
 * @author Travis E. Brown
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Basic weather station that records time and temperature of observations.
 */


#include <string>
#include "Time.h"
#include <exception>
#include <stdexcept>


/** Basic weather station that records up to 24 temperature observations */
class WeatherStation
{

public:
   /** 
    * Constructor that takes the name, latitude and longitude of the station 
    *
    * @param name Name of the station 
    * @param latitude latitude of the station.  Negative values are south,
    * positive values are north
    * @param longitude longitude of the station. Negative values are west,
    * positive values are east
    */
   WeatherStation( const std::string &name, 
                   const double &latitude,
                   const double &longitude );

   /**
    * Weather station destructor.
    */
   virtual ~WeatherStation() {};
   WeatherStation() {};

   /**
    * Record temperature at a particular time
    *
    * @param time Time of the observation
    * @param temperature Temperature of the observation
    */
   void recordObservation( Time time, float temperature );

   /**
    * Return the average of all observations
    *
    * @return average temperature
    */
   float getAverageTemperature();

   /**
    * Return the time the high temperature was observed
    *
    * @return the time the high temperature was observed
    */
   Time getTimeOfHighTemp() const;

   /**
    * Return the time the low temperature was observed
    *
    * @return the time the low temperature was observed
    */
   Time getTimeOfLowTemp() const;

   /**
    * Get the high temperature of the day
    *
    * @return the daily high temperature
    */
   float getValueOfHighTemp() const;
   
   /**
    * Get the low temperature of the day
    *
    * @return the daily low temperature
    */
   float getValueOfLowTemp() const;

   /**
    * Get the name of the station
    *
    * @return the name of the station
    */
   std::string getStationName() const;
    
   /**
    * Return the latitude of the station
    *
    * @return the station's latitude
    */
   double getStationLatitude() const;

   /**
    * Return the longitude of the station
    *
    * @return the station's longitude
    */

   double getStationLongitude() const;

protected:
   /** Maximum number of observations that can be recored */
   static const int maxObservations = 24;

   /** Structure for storing time and temperature observations */
   struct Observation
   {
      Time   time;          ///< Time of the observation
      float  temperature;   ///< Temperature when the observation was made
   };

protected:
   /** An array for storing observations */
   Observation observations[maxObservations];

   /** Index into the observations array */
   int currentObservation;

private:
   std::string name;
   double latitude;
   double longitude;
};


#endif // __WEATHER_STATION_H__
