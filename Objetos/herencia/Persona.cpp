#include "Persona.hpp"


Persona::Persona(string nombre, int edad) {
	this->nombre = nombre;
	this->edad = edad;
}

string Persona::toString() {
	return this->nombre + " - " + to_string(this->edad);
}