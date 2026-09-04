#include <iostream>
#include "DireccionEntity.h"

using namespace std;

class CandidatoEntity {
public:	
	string nombre;
	string apellido;
	string correoElectronico;
	string telefono;
	DireccionEntity direccion;

private:
	void setNombre(string nombre) {
		this->nombre = nombre;
	}
};