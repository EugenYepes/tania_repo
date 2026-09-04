#include <iostream>
#include "DireccionEntity.h"
#include "Persona.h"

using namespace std;

class CandidatoEntity: public Persona
{
private:
	string mascotas;
	DireccionEntity direccion;

public:
	const string &getMascotas() const
	{
		return mascotas;
	}

	void setMascotas(const string &mascotas)
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