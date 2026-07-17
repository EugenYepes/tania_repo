#include <iostream>
#include <string>


using namespace std;


class Motor {
private:
	double cilindrada;
	int cantCilindros;
	double torque;
	double potencia;
public:
	Motor(double cilindrada, int cantCilindros, double torque, double potencia);
	Motor();
	
   	double getCilindrada();
    int getCantidadCilindros();
    double getTorque();
    double getPotencia();

    string toString();
};


