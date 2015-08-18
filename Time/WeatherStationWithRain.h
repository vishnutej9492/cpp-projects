
class WeatherStationWithRain:public WeatherStation
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
   WeatherStationWithRain( const std::string &name, 
                   const double &latitude,
				   const double &longitude );
   WeatherStationWithRain(){};
	/**
    * Record temperature and wind at a particular time
    *
    * @param time Time of the observation
	* @param temperature Temperature of the observation
	* @param wind wind of the observation
	* @param deg wind of the observation
    */
   void recordObservation(Time time, float temperature, float rain);
      
    /**
    * Return the total rain of all observations
    *
    * @return average wind speed
    */
   float getTotalRain();
protected:
	
   /** An array for storing wind observations */
   float rain[maxObservations];
};