#ifndef DIRECCIONENTITY_H
#define DIRECCIONENTITY_H

#include <string>

class DireccionEntity
{
private:
	std::string calle;
	std::string estado;
	std::string pais;
	std::string numero;

public:
	int id = 0;

	int getId() const { return id; }
	void setId(int id) { this->id = id; }

	std::string getCalle() const
	{
		return calle;
	}

	void setCalle(std::string calle)
	{
		this->calle = calle;
	}

	std::string getEstado() const
	{
		return estado;
	}

	void setEstado(std::string estado)
	{
		this->estado = estado;
	}

	std::string getPais() const
	{
		return pais;
	}

	void setPais(std::string pais)
	{
		this->pais = pais;
	}

	std::string getNumero() const
	{
		return numero;
	}

	void setNumero(std::string numero)
	{
		this->numero = numero;
	}
};

#endif
