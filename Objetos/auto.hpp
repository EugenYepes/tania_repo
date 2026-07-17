#include <iostream>
#include <string>
#include "motor.hpp"


using namespace std;


class Auto {
private:
	string marca;
	string modelo;
	string color;
	Motor& Motor;
public:
	Auto(string marca, string modelo, string color, Motor &Motor);



};
