#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
private:
	std::string nombre;
	std::string apellido;
	std::string correoElectronico;
	std::string telefono; 

public:
	std::string getNombre() const {
		return nombre;
	}

	void setNombre(const std::string& nombre) {
		this->nombre = nombre;
	}

	std::string getApellido() const {
		return apellido;
	}

	void setApellido(const std::string& apellido) {
		this->apellido = apellido;
	}

	std::string getCorreoElectronico() const {
		return correoElectronico;
	}

	void setCorreoElectronico(const std::string& correoElectronico) {
		this->correoElectronico = correoElectronico;
	}

	std::string getTelefono() const {
		return telefono;
	}

	void setTelefono(const std::string& telefono) {
		this->telefono = telefono;
	}

};

#endif