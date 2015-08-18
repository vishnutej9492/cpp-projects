#include "Time.h"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <exception>
#include <stdexcept>

using namespace std;

Time::Time()
{
   set( 0 );
}

Time::Time( int secs )
{
   set( secs );
}

Time::Time( std::string HHMM )
{
   set( HHMM );
}

int Time::getTimeInSecs() const
{
   return timeInSecs;
}

string Time::getTimeInHHMM() const
{

   ostringstream osstr ;
   osstr << setw(2) << setfill('0') << timeInSecs / 3600 << ":" << setw(2) << ( timeInSecs % 3600 ) / 60;

   return osstr.str();

}

void Time::set( int secs )
{
   timeInSecs = secs;
}

void Time::set( string HHMM )
{
   int hours, minutes, sec = 0;
   int colon = -1;  // positions of ':' in s
   for (int i=0; i<int(HHMM.size()); ++i)
   {
      if (HHMM[i] == ':')
      {
         colon = i;
      }
   }

   istringstream(HHMM.substr( 0, colon )) >> hours;
   sec = hours * 3600;
   if (colon >= 0)
   {
      istringstream(HHMM.substr(colon+1)) >> minutes;
      sec += minutes * 60;
   }
   if ( sec > 86400 )
   {
      throw overflow_error("Time is out of range");
   }
   if ( sec < 0 )
   {
      throw underflow_error("Time is out of range");
   }


   timeInSecs = sec;

}

ostream& operator<<(ostream& os, const Time& t )
{
   os << t.getTimeInHHMM();
   return os;
}

istream& operator>>(istream& is, Time& t)
{
   string s; 
   is >> s;
   if(is.eof())
	   return is;   
   t.set( s );
   return is;
}

