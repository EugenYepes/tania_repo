#include <iostream>
#include "Direccion.hpp"
#include "Auto.hpp"

using namespace std;


class Persona {
private:
	string dni;
	string nombre;
	string apellido;
	Direccion& direccion;
	Auto& vehiculo;
public:
	Persona(string dni, string nombre, string apellido, Direccion &direccion, Auto &vehiculo);
	Persona(string dni, string nombre, string apellido, Direccion &direccion);


	string getNombreCompleto();

	string toString();
};
