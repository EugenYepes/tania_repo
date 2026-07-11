#include <iostream>
#include <string>

using namespace std;

class Direccion
{
private:
	string pais;
	string estado;
	string ciudad;
	string calle;
	int numero;
	int piso;
	char dpto;

public:
	Direccion(string pais, string estado, string ciudad, string calle, int numero = 0);

	void setPais(string pais) { this->pais = pais; }
	void setEstado(string estado) { this->estado = estado; }
	void setCiudad(string ciudad) { this->ciudad = ciudad; }
	void setCalle(string calle) { this->calle = calle; }
	void setNumero(int numero) { this->numero = numero; }

	void setPiso(int piso) { this->piso = piso; }
	void setDpto(char dpto) { this->dpto = dpto; }

	string getPais() { return this->pais; }

	string toString();
};