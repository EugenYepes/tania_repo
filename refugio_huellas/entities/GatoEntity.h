#include <iostream>
#include "EmpleadoEntity.h"
#include "AnimalEntity.h"

using namespace std;

enum class Estado
{
	NO_ADOPTADO = 0,
	ADOPTADO = 1
};

class GatoEntity : Animal
{
private:
	string test;
	string indoor;

public:
	const string &getTest() const
	{
		return test;
	}

	void setTest(const string &test)
	{
		this->test = test;
	}

	const string &getIndoor() const
	{
		return indoor;
	}

	void setIndoor(const string &indoor)
	{
		this->indoor = indoor;
	}
};