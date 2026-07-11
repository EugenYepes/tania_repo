#include <iostream>
#include "Direccion.hpp"

using namespace std;


class Persona {
private:
	string dni;
	string nombre;
	string apellido;
	Direccion& direccion;
public:
	Persona(string dni, string nombre, string apellido, Direccion &direccion);

	string getNombreCompleto();

	string toString();
};
