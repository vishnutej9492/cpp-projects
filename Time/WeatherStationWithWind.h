
class WeatherStationWithWind:public WeatherStation
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
   WeatherStationWithWind( const std::string &name, 
                   const double &latitude,
                   const double &longitude );
	/**
    * Record temperature and wind at a particular time
    *
    * @param time Time of the observation
	* @param temperature Temperature of the observation
	* @param wind wind of the observation
	* @param deg wind of the observation
    */
   void recordObservation( Time time, float temperature, float wind, float windDirection);
      
    /**
    * Return the average wind spreed of all observations
    *
    * @return average wind speed
    */
   float getAverageWind();
	/**
    * Return the average wind spreed of all observations
    *
    * @return average wind speed
    */
   float getAverageWindDirection();
protected:
	/** Structure for storing time and temperature observations */
   struct WindObservation
   {
      float  wind;   ///< wind spped when the observation was made
	  float  windDirection;///< Wind direction when the observation was made
   };
   /** An array for storing wind observations */
   WindObservation windObservations[maxObservations];
};