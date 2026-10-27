#ifndef GATOENTITY_H
#define GATOENTITY_H

#include <iostream>
#include "EmpleadoEntity.h"
#include "AnimalEntity.h"

using namespace std;

class GatoEntity : public Animal
{
private:
	string test;
	int indoor;

public:
	const string &getTest() const
	{
		return test;
	}

	void setTest(const string &test)
	{
		this->test = test;
	}

	const int &getIndoor() const
	{
		return indoor;
	}

	void setIndoor(const int &indoor)
	{
		this->indoor = indoor;
	}
};

#endif