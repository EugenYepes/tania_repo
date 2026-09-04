#include <iostream>
#include "EmpleadoEntity.h"
#include "AnimalEntity.h"

using namespace std;

enum class Estado
{
	NO_ADOPTADO = 0,
	ADOPTADO = 1
};

class PerroEntity : Animal
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