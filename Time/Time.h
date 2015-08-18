#ifndef __TIME_H__
#define __TIME_H__

/**
 * @file
 * @author Travis E. Brown
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * Simple time class for storing time since midnight.  This is not a general
 * time class that can be used to represent ANY time.  
 */

#include <string>

class Time
{
public:
   /**
    * Constructor that sets the time to 0
    */
   Time();

   /**
    * Constructor that sets the time in number of seconds since midnight
    *
    * @param secs Number of seconds since midnight
    */
   Time( int secs );

   /**
    * Constructor that sets the time in the format HH:MM. This is passed in as
    * a C++ string
    *
    * @param HHMM a string that is number of hours and minutes since midnight.
    * In the format HH:MM
    */
   Time( std::string HHMM );

   /**
    * Get the stored time.
    *
    * @return Number of seconds since midnight
    */
   int getTimeInSecs() const;

   /**
    * Get the stored time
    *
    * @return a string in the format "HH:MM" which is the hours and minutes
    * since midnight.
    */
   std::string getTimeInHHMM() const;

   /**
    * Set the stored time
    *
    * @param HHMM a string in the format "HH:MM" which is the hours and
    * minutes since midnight
    */
   void set( std::string HHMM );

   /**
    * Set the stored time
    *
    * @param secs number of seconds since midnight
    */
   void set( int secs );

private:
   unsigned int timeInSecs;

};

/**
 * Operator << for Time class
 *
 * @param os ostream class for chaining
 * @param t Time class 
 * @return ostream class for chaining
 */
std::ostream& operator<<(std::ostream& os, const Time& t );

/**
 * Operator >> for Time class
 *
 * @param os istream class for chaining
 * @param t Time class 
 * @return istream class for chaining
 */
std::istream& operator>>(std::istream& is, Time& t);


#endif // __TIME_H__
