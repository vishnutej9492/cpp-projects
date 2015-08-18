/* 
 * Statistics header with functions
 * 
 * @author : Vishnu Tej MP(vm9069)
 */
#ifndef STATISTICS_H_
#define STATISTICS_H_
#include <vector>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <math.h>
#include <map>

#include<iostream>
using namespace std;

/*
 * Template class Statistics inherits from the class vector
 * and contains five its own methods for statistics. Class vector is chosen because
 * it matches all the requirements such as pushing back and efficiently
 * realizes free access to the elements.
 */

template <class T>
class Statistics: public std::vector<T>
{

public:

	/*
	 * Method mean
	 *
	 * Returns the average, the sum of all the numbers divided by the number of numbers.
	 * The algorithm for finding mean is taken from the web-site:
	 * http://www.purplemath.com/modules/meanmode.htm
	 *
	 */

	T mean()
	{
		if (this->size() <= 1) throw std::underflow_error("Not enough data");

		T total = 0;
		typename Statistics<T>::iterator statIterator;

		for (statIterator = this->begin(); statIterator != this->end(); statIterator++)
		{
			total += (*statIterator);
		}
		return total / (T)this->size();
	}

	/*
	 * Method median
	 *
	 * Returns the middle number if the number of elements is odd and
	 * returns the average of two middle numbers if the number of elements
	 * is even.
	 * The algorithm for finding mean is taken from the web-site:
	 * http://www.purplemath.com/modules/meanmode.htm
	 *
	 */

	T median()
	{
		if (this->size() <= 1) throw std::underflow_error("Not enough data");

		typename Statistics<T>::iterator statIterator;
		std::sort(this->begin(), this->end());
		T size = this->size(), median;

		if ((int)size % 2 != 0)
		{
			median = (*this)[size / 2];
			return median;
		}
		else
		{
			median = ((*this)[size / 2] + (*this)[(size - 1) / 2]) / 2;
			return median;
		}
	}

	/*
	 * Method mode
	 *
	 * Returns the set of the most frequently repeated numbers or an empty set
	 * if all the numbers are unique.
	 *
	 */

	std::set<T> mode()
	{
		if (this->size() <= 1) throw std::underflow_error("Not enough data");

		typename Statistics<T>::iterator statIterator, nextStatIterator;
		std::set<T> modeSet;
		std::map<T, int> repeatedValues;

		statIterator = this->begin();
		while (statIterator != this->end())
		{
			nextStatIterator = statIterator;
			int repetition = 0;
			while (*nextStatIterator == *statIterator)
			{
				repetition++;
				nextStatIterator++;
			}
			repeatedValues[*statIterator] = repetition;
			statIterator = nextStatIterator;
		}

		typename std::map<T, int>::iterator repValIterator;
		int maxRepetition = (*repeatedValues.begin()).second;

		for (repValIterator = repeatedValues.begin(); repValIterator != repeatedValues.end(); repValIterator++)
		{
			if ((*repValIterator).second > maxRepetition) maxRepetition = (*repValIterator).second;
		}

		if (maxRepetition == 1) return modeSet;

		for (repValIterator = repeatedValues.begin(); repValIterator != repeatedValues.end(); repValIterator++)
		{
			if (maxRepetition == (*repValIterator).second) modeSet.insert((*repValIterator).first);
		}

		return modeSet;
	}

	/*
	 * Method variance
	 *
	 * Returns the average squared deviation from the mean.
	 * The algorithm is taken from the web-site:
	 * http://www.sciencebuddies.org/science-fair-projects/project_data_analysis_variance_std_deviation.shtml
	 *
	 */

	T variance()
	{
		if (this->size() <= 1) throw std::underflow_error("Not enough data");

		typename Statistics<T>::iterator statIterator;
		T mean = this->mean(), size = this->size();
		T total = 0;

		for (statIterator = this->begin(); statIterator != this->end(); statIterator++)
		{
			total += pow((*statIterator) - mean, 2);
		}

		return total / (size - 1);
	}

	/*
	 * Method standardDeviation
	 *
	 * Returns the square root of a variance.
	 */

	T standardDeviation()
	{
		return sqrt(this->variance());
	}
};

#endif /* STATISTICS_H_ */
