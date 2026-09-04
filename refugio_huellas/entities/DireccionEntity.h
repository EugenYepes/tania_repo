#include <iostream>

using namespace std;

class DireccionEntity{
private:
	string calle;
	string ciudad;
	string provincia;
	string codigoPostal;

public:
	

	string getCalle() {
		return calle;
	}

	void setCalle(string calle) {
		this->calle = calle;
	}

	string getCiudad() {
		return ciudad;
	}

	void setCiudad(string ciudad) {
		this->ciudad = ciudad;
	}

	string getProvincia() {
		return provincia;
	}

	void setProvincia(string provincia) {
		this->provincia = provincia;
	}

	string getCodigoPostal() {
		return codigoPostal;
	}

	void setCodigoPostal(string codigoPostal) {
		this->codigoPostal = codigoPostal;
	}
};
