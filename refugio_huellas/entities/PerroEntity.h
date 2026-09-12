#ifndef PERROENTITY_H
#define PERROENTITY_H

#include <iostream>
#include "EmpleadoEntity.h"
#include "AnimalEntity.h"

using namespace std;

class PerroEntity : public Animal
{
public:
	string raza;
	string energia;

public:
	string getRaza()
	{
		return raza;
	}

	void setRaza(string raza)
	{
		this->raza = raza;
	}

	string getEnergia()
	{
		return energia;
	}

	void setEnergia(string energia)
	{
		this->energia = energia;
	}
};

#endif