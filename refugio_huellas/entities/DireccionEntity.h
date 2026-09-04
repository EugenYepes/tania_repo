#pragma once

#include <string>

using namespace std;

class DireccionEntity
{
private:
	string calle;
	string estado;
	string pais;
	string numero;

public:
	int id = 0;

	int getId() const { return id; }
	void setId(int id) { this->id = id; }

	string getCalle() const
	{
		return calle;
	}

	void setCalle(string calle)
	{
		this->calle = calle;
	}

	string getEstado() const
	{
		return estado;
	}

	void setEstado(string estado)
	{
		this->estado = estado;
	}

	string getPais() const
	{
		return pais;
	}

	void setPais(string pais)
	{
		this->pais = pais;
	}

	string getNumero() const
	{
		return numero;
	}

	void setNumero(string numero)
	{
		this->numero = numero;
	}
};
