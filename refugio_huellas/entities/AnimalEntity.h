#ifndef ANIMALENTITY_H
#define ANIMALENTITY_H

#include "EmpleadoEntity.h"
#include <iostream>

using namespace std;

enum class Estado
{
	NO_ADOPTADO = 0,
	ADOPTADO = 1
};

class Animal
{
private:
	int id;
	Estado estado;
	int edad;
	string nombre;
	string diagnostico;
	EmpleadoEntity * cuidador;


public:
	int getId() const
	{
		return id;
	}

	void setId(int id)
	{
		this->id = id;
	}

	string getEstado() const
	{
		switch (this->estado)
		{
		case Estado::NO_ADOPTADO:
			return "NO_ADOPTADO";
		case Estado::ADOPTADO:
			return "ADOPTADO";
		default:
			return "";
		}
	}

	void setEstado(Estado estado)
	{
		this->estado = estado;
	}

	int getEdad() const
	{
		return edad;
	}

	void setEdad(int edad)
	{
		this->edad = edad;
	}

	string getNombre() const
	{
		return nombre;
	}

	void setNombre(const string &nombre)
	{
		this->nombre = nombre;
	}

	string getDiagnostico() const
	{
		return diagnostico;
	}

	void setDiagnostico(const string &diagnostico)
	{
		this->diagnostico = diagnostico;
	}

	EmpleadoEntity *getCuidador() const
	{
		return cuidador;
	}

	void setCuidador(EmpleadoEntity *cuidador)
	{
		this->cuidador = cuidador;
	}
};

#endif
