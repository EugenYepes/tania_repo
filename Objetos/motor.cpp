#include "Motor.hpp"

Motor::Motor(double cilindrada, int cantCilindros, double torque, double potencia) {
	this->cilindrada = cilindrada;
	this->cantCilindros = cantCilindros;
	this->torque = torque;
	this->potencia = potencia;
}

Motor::Motor() {
	this->cilindrada = 0;
	this->cantCilindros = 0;
	this->torque = 0;
	this->potencia = 0;
}

string Motor::toString() {
	return to_string (this->cilindrada) + "," + to_string(this->cantCilindros) + "," + to_string(this->torque) + "," + to_string(this->potencia);
}
