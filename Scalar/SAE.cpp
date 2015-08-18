/*
 * Implementation program for SAE.
 * 
 * @author : Vishnu Tej MP(vm9069)
 *
 */

#include "SAE.h"
#include <math.h>

/*
 * 	Constructor with parameters, after initialization
 * 	controls that the number of inches is not greater
 * 	than eleven.
 */

SAE::SAE(float ft, float inc)
{
	feet = ft;
	inches = inc;
	dimensions = 1;

	if (inches > 11)
	{
		while (inches > 11)
		{
			feet++;
			inches-=12;
		}
	}
}

/*
 * 	The default constructor, which initializes fields with zero.
 */

SAE::SAE()
{
	feet = 0;
	inches = 0;
	dimensions = 0;
}

/*
 * 	This function takes as argument the number of dimensions to be set.
 */

void SAE::setDimensions(int value)
{
	dimensions = value;
}

/*
 * 	This function is to return feet.
 */

float SAE::getFeet()
{
	return feet;
}

/*
 * 	This function is to return inches.
 */

float SAE::getInches()
{
	return inches;
}

/*
 * 	Overloading operator + for SAE class.
 * 	Adds the feet from the passed object to the feet, adds the inches from
 * 	the passed object to the inches and initializes a new object of SAE class.
 */

SAE& SAE::operator +(SAE& sae)
{
	float new_feet = this->getFeet() + sae.getFeet();
	float new_inches = this->getInches() + sae.getInches();

	SAE* new_sae = new SAE(new_feet, new_inches);
	new_sae->Fit();
	return *new_sae;
}

/*
 * 	Overloading operator - for SAE class.
 * 	Subtracts the feet and inches of the passed object from the feet and inches
 * 	appropriately and initializes a new object of SAE class then.
 */

SAE& SAE::operator -(SAE& sae)
{
	float new_feet = this->getFeet() - sae.getFeet();
	float new_inches = this->getInches() - sae.getInches();

	SAE* new_sae = new SAE(new_feet, new_inches);
	new_sae->Fit();
	return *new_sae;
}

/*
 * 	Overloading operator * for SAE class.
 * 	Counts the square feet and the square feet of the passed object
 * 	and multiplies. Then initializes a new object of SAE class, increasing dimensions.
 */

SAE& SAE::operator *(SAE& sae)
{
	float new_feet = (this->getFeet() + this->getInches() / 12) * (sae.getFeet() + sae.getInches() / 12);

	SAE* new_sae = new SAE(new_feet, 0);
	new_sae->setDimensions(this->getDimensions() + 1);
	return *new_sae;
}

/*
 * 	Overloading operator / for SAE class.
 * 	Counts the square feet of the passed object and divides
 * 	the square feet by that value. Then initializes a new object of SAE class
 * 	with the counted value.
 */

SAE& SAE::operator /(SAE& sae)
{
	float new_feet, new_inches = 0;
	new_feet = feet / (sae.getFeet() + sae.getInches() / 12);

	SAE* new_sae = new SAE(new_feet, new_inches);
	new_sae->Fit();
	new_sae->setDimensions(this->getDimensions() - sae.getDimensions());
	if (new_sae->getDimensions() < 1) throw std::underflow_error("Not enough dimensions");
	return *new_sae;
}

/*
 * 	Overloading operator *= for SAE class.
 * 	Acts the say way as * operator but assigns the counted value
 * 	to the object that invoked this operator.
 */

SAE& SAE::operator *=(SAE& sae)
{
	feet += inches / 12;
	inches = 0;
	feet *= sae.getFeet() + sae.getInches() / 12;
	this->setDimensions(this->getDimensions() + 1);
	return *this;
}

/*
 * 	Overloading operator += for SAE class.
 * 	Acts the say way as + operator but assigns the counted value
 * 	to the object that invoked this operator.
 */

SAE& SAE::operator +=(SAE& sae)
{
	feet += sae.getFeet();
	inches += sae.getInches();
	this->Fit();
	return *this;
}

/*
 * 	Overloading operator -= for SAE class.
 * 	Acts the say way as - operator but assigns the counted value
 * 	to the object that invoked this operator.
 */

SAE& SAE::operator -=(SAE& sae)
{
	feet -= sae.getFeet();
	inches -= sae.getInches();
	this->Fit();
	return *this;
}

/*
 * 	Returns the number of dimensions.
 */

int SAE::getDimensions()
{
	return dimensions;
}

/*
 * 	Overloading operator << for SAE class.
 * 	If the number of dimensions is greater than 1, and feet are less than one,
 * 	prints inches and its number of dimensions, else prints feet and its number of dimensions,
 * 	else prints feet and inches.
 */

std::ostream& operator<<(std::ostream& out, SAE sae)
{
	if (sae.getDimensions() > 1)
	{
		if (sae.getFeet() < 1)
			out << sae.getFeet() * 144 << " inches^" << sae.getDimensions();
		else
		out << sae.getFeet() << " feet^" << sae.getDimensions();
	}
	else
	{
		out << sae.getFeet() << " feet, " << sae.getInches() << " inches";
	}

	return out;
}

/*
 * 	Overloading operator * for scalar multiplication.
 * 	Multiplies feet and inches by the passed number.
 */

SAE& SAE::operator *(float number)
{
	float new_feet = feet * number;
	float new_inches = inches * number;
	SAE* new_sae = new SAE(new_feet, new_inches);
	new_sae->Fit();
	return *new_sae;
}

/*
 * 	Overloading operator / for scalar division.
 * 	Divides feet and inches by the passed number.
 */

SAE& SAE::operator /(float number)
{
	if (number == 0) throw std::overflow_error("Devide by zero");
	float new_feet = feet / number;
	float new_inches = inches / number;
	SAE* new_sae = new SAE(new_feet, new_inches);
	new_sae->Fit();
	return *new_sae;
}

/*
 * 	This is a helper function needed to measure the values of feet and inches
 * 	and supply them appropriately.
 */

void SAE::Fit()
{
	if (fabs(feet) - (int)fabs(feet) > 0)
	{
		float tail = feet - (int)feet;
		inches += tail * 12;
		feet -= tail;
	}

	if (fabs(inches) > 11)
	{
		while (fabs(inches) > 11)
		{
			if (feet < 0) feet -= 1;
			else
			feet += 1;

			if (inches < 0) inches += 12;
			else
			inches -= 12;
		}
	}

	if (inches < 0 && feet > 0)
	{
		while (inches < 0)
		{
			feet -= 1;
			inches += 12;
		}
	}
}


