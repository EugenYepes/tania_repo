#include <iostream>
#include <string>
#include "motor.hpp"


using namespace std;


class Auto {
private:
	string marca;
	string modelo;
	string color;
	Motor& motor;
	string placa;
public:
	Auto(string marca, string modelo, string color, Motor &motor, string placa);
	Auto();
	string toString();
};
