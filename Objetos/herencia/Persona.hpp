#include <iostream>

using namespace std;


class Persona {
private:
	string nombre;
	int edad;
public:
	Persona(string nombre, int edad);


	virtual string toString();
};

class Estudiante : Persona {
private:
    string carrera;
public:
    Estudiante(string nombre, int edad, string carrera);

	string toString() override;
};

