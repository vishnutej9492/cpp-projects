class WeatherStationWithWindAndRain:public WeatherStationWithWind,public WeatherStationWithRain
{
public:
	WeatherStationWithWindAndRain( const std::string &name, 
                   const double &latitude,
                   const double &longitude );
	/**
    * Record temperature and wind at a particular time
    *
    * @param time Time of the observation
	* @param temperature Temperature of the observation
	* @param wind wind of the observation
	* @param deg wind of the observation
	* @param deg rain of the observation
    */
   void recordObservation( Time time, float temperature, float wind, float windDirection,float rain);
  


};