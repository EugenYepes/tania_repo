#include "motor.hpp"

Motor::Motor(double cilindrada, int cantCilindros, double torque, double potencia) {
	this->cilindrada = cilindrada;
	this->cantCilindros = cantCilindros;
	this->torque = torque;
	this->potencia = potencia;
}

string Motor::toString() {
	return to_string (this->cilindrada) + "," + to_string(this->cantCilindros) + ", " + this->ciudad + ", " + this->estado + ", " + this->pais;
}
