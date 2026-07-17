#include "Auto.hpp"

Auto::Auto(string marca, string modelo, string color, Motor &motor, string placa) : motor(motor) {
	this->marca = marca;
	this->modelo = modelo;
	this->color = color;
	this->placa = placa;
}

Auto::Auto() : motor(*(new Motor())) {
	this->marca = "";
	this->modelo = "";
	this->color = "";
	this->placa = "";
}


string Auto::toString() {
	return this->marca + "," + this->modelo + "," + this->color + "," + this->placa + "," + this->motor.toString();
}