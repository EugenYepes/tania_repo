#ifndef CANDIDATOENTITY_H
#define CANDIDATOENTITY_H

#include <string>
#include "DireccionEntity.h"
#include "Persona.h"

class CandidatoEntity: public Persona
{
private:
	std::string mascotas;
	DireccionEntity direccion;

public:
	const std::string &getMascotas() const
	{
		return mascotas;
	}

	void setMascotas(const std::string &mascotas)
	{
		this->mascotas = mascotas;
	}

	DireccionEntity getDireccion() const
	{
		return direccion;
	}
	
	void setDireccion(const DireccionEntity &direccion)
	{
		this->direccion = direccion;
	}
};

#endif
