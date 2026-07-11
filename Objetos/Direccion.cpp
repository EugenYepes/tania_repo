#include "Direccion.hpp"

Direccion::Direccion(string pais, string estado, string ciudad, string calle, int numero) {
	this->pais = pais;
	this->estado = estado;
	this->ciudad = ciudad;
	this->calle = calle;
	this->numero = numero;
}

string Direccion::toString() {
	return this->calle + " " + to_string(this->numero) + ", " + this->ciudad + ", " + this->estado + ", " + this->pais;
}