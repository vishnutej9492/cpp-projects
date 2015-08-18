/*
 * Header file to help SAE Program
 * 
 * @author : Vishnu Tej MP(vm9069)
 *
 */
#ifndef SAE_H_
#define SAE_H_

#include <iostream>
#include <stdexcept>

class SAE
{
	float feet;
	float inches;
	int dimensions;

public:
	SAE();
	SAE(float ft, float inc);
	float getFeet();
	float getInches();
	void setDimensions(int value);
	int getDimensions();
	void Fit();

	SAE& operator+(SAE& sae);
	SAE& operator-(SAE& sae);
	SAE& operator*(SAE& sae);
	SAE& operator/(SAE& sae);

	SAE& operator+=(SAE& sae);
	SAE& operator-=(SAE& sae);
	SAE& operator*=(SAE& sae);

	SAE& operator*(float number);
	SAE& operator/(float number);

	friend std::ostream& operator<<(std::ostream& out, SAE sae);
};



#endif /* SAE_H_ */
