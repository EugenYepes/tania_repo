#include "Persona.h"


Persona::Persona(string dni, string nombre, string apellido, string direccion) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellido = apellido;
	this->direccion = direccion;
}

string Persona::getNombreCompleto() {
	return this->nombre + " " + this->apellido;
}
