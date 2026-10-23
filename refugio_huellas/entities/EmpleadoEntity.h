#ifndef EMPLEADOENTITY_H
#define EMPLEADOENTITY_H

#include <string>
#include "Persona.h"

using namespace std;

enum class Turno
{
	MATUTINO,
	VESPERTINO
};

class EmpleadoEntity : public Persona
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

	string getTurnoString() const
	{
		switch (this->turno) {
			case Turno::MATUTINO:
				return "MATUTINO";
			case Turno::VESPERTINO:
				return "VESPERTINO";
			default:
				return "";
		}
	}

	void setTurno(string turno)
	{
		if (turno == "MATUTINO") {
			this->turno = Turno::MATUTINO;
		} else if (turno == "VESPERTINO") {
			this->turno = Turno::VESPERTINO;
		} else {
			this->turno = Turno::MATUTINO; // Valor predeterminado
		}
	}
};

#endif
