#include <string>
#include "Persona.h"

using namespace std;

enum class Turno
{
	MATUTINO,
	VESPERTINO
};

class EmpleadoEntity: Persona
{
private:
	double sueldo;
	Turno turno;

public:

	double getSueldo() const
	{
		return sueldo;
	}

	void setSueldo(double sueldo)
	{
		this->sueldo = sueldo;
	}

	Turno getTurno() const
	{
		return turno;
	}

	void setTurno(Turno turno)
	{
		this->turno = turno;
	}
};
