#include "Persona.hpp"


Persona::Persona(string dni, string nombre, string apellido, Direccion &direccion, Auto &vehiculo) : direccion(direccion), vehiculo(vehiculo) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellido = apellido;
}

Persona::Persona(string dni, string nombre, string apellido, Direccion &direccion) : direccion(direccion), vehiculo(*(new Auto())) {
	this->dni = dni;
	this->nombre = nombre;
	this->apellido = apellido;
}

string Persona::getNombreCompleto() {
	return this->nombre + " " + this->apellido;
}

string Persona::toString() {
	return this->dni + " - " + this->nombre + " " + this->apellido + " - " + this->direccion.toString() + " - " + this->vehiculo.toString();
}
