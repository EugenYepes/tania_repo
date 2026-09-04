#include <iostream>

using namespace std;

class Persona {
private:
	string nombre;
	string apellido;
	string correoElectronico;
	string telefono; 

public:
	string getNombre() const {
		return nombre;
	}

	void setNombre(const string& nombre) {
		this->nombre = nombre;
	}

	string getApellido() const {
		return apellido;
	}

	void setApellido(const string& apellido) {
		this->apellido = apellido;
	}

	string getCorreoElectronico() const {
		return correoElectronico;
	}

	void setCorreoElectronico(const string& correoElectronico) {
		this->correoElectronico = correoElectronico;
	}

	string getTelefono() const {
		return telefono;
	}

	void setTelefono(const string& telefono) {
		this->telefono = telefono;
	}

};