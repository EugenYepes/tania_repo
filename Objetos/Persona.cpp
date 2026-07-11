#include "Persona.hpp"

Persona::Persona(string dni, string nombre, string apellido, Direccion &direccion) : direccion(direccion)
{
	this->dni = dni;
	this->nombre = nombre;
	this->apellido = apellido;
}

string Persona::getNombreCompleto() {
	return this->nombre + " " + this->apellido;
}

string Persona::toString() {
	return this->dni + " - " + this->nombre + " " + this->apellido + " - " + this->direccion.toString();
}
