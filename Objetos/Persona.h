#include <iostream>

using namespace std;


class Persona {
private:
	string dni;
	string nombre;
	string apellido;
	string direccion;
public:
	Persona(string dni, string nombre, string apellido, string direccion);

	string getNombreCompleto();
};
