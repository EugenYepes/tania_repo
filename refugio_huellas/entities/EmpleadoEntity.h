#include <iostream>

using namespace std;

enum class Turno {
	MATUTINO,
	VESPERTINO = 10,
	NOCTURNO
};

class EmpleadoEntity{
private:
	string telefono;
	string correo;
	double sueldo;
	Turno turno;
    string nombre; 
    string apellido;

public:
	
	string getTelefono() {
		return telefono;
	}

	void setTelefono(string telefono) {
		this->telefono = telefono;
	}

	string getCorreo() {
		return correo;
	}

	void setCorreo(string correo) {
		this->correo = correo;
	}

	double getSueldo() {
		return sueldo;
	}

	void setSueldo(double sueldo) {
		this->sueldo = sueldo;
	}

	Turno getTurno() {
		return turno;
	}

	void setTurno(Turno turno) {
		this->turno = turno;
	}

	string getNombre() {
		return nombre;
	}

	void setNombre(string nombre) {
		this->nombre = nombre;
	}

	string getApellido() {
		return apellido;
	}

	void setApellido(string apellido) {
		this->apellido = apellido;
	}
};
