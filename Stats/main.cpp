/**
 * 4003-703-03 Homework 4 main.cpp.  Students should add a showStats()
 * function to this file.
 *
 * @author : Vishnu Tej MP
 */
#include "statistics.h"
#include <iostream>
#include <fstream>
#include <iterator>

using namespace std;

/* showStats() function goes here */

void showStats( Statistics< int > Stats )
{
	cout << "mean: " << Stats.mean() << endl;
	cout << "median: " << Stats.median() << endl;

	std::set<int> modeSet = Stats.mode();
	std::set<int>::iterator modeSetIterator;
	cout << "mode: ";
	for (modeSetIterator = modeSet.begin(); modeSetIterator != modeSet.end(); modeSetIterator++)
	{
		cout << *modeSetIterator << " ";
	}
	cout << endl;

	cout << "variance: " << Stats.variance() << endl;
	cout << "stdDeviation: " << Stats.standardDeviation() << endl;
}

void showStats( Statistics< float > Stats )
{
	cout << "mean: " << Stats.mean() << endl;
	cout << "median: " << Stats.median() << endl;

	std::set<float> modeSet = Stats.mode();
	std::set<float>::iterator modeSetIterator;
	cout << "mode: ";
	for (modeSetIterator = modeSet.begin(); modeSetIterator != modeSet.end(); modeSetIterator++)
	{
		cout << *modeSetIterator << " ";
	}
	cout << endl;

	cout << "variance: " << Stats.variance() << endl;
	cout << "stdDeviation: " << Stats.standardDeviation() << endl;
}

/* DO NOT MODIFY ANYTHING BELOW THIS LINE */
int main()
{
   Statistics< int > iStats;
   Statistics< float > fStats;

   cout << "Enter integers separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< int > i_in_it( cin );
   for( ; i_in_it != istream_iterator<int>(); i_in_it++ )
   {
      if ( !cin.fail() )
      {
         iStats.push_back(*i_in_it);
      }
   }

   showStats( iStats );

   /* Clear the EOF we recieved from integer inputs */
   cin.clear();

   cout << endl << endl;
   cout << "Enter floats separated by whitespace. Press CTRL-D on an empty line to end." << endl;;

   /* Set up an input iterator and process the user input for integers */
   istream_iterator< float > f_in_it( cin );
   for( ; f_in_it != istream_iterator<float>(); f_in_it++ )
   {
      if ( !cin.fail() )
      {
         fStats.push_back(*f_in_it);
      }
   }
   showStats( fStats );

}
