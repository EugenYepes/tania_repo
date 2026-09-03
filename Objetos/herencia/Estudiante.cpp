#include "Persona.hpp"


Estudiante::Estudiante(string nombre, int edad, string carrera) : Persona(nombre, edad){
	this->carrera = carrera;
}

string Estudiante::toString() {
	return Persona::toString() + " - " + this->carrera;
}