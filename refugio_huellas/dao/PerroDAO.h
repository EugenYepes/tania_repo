#ifndef PERRODAO_H
#define PERRODAO_H

#include "PerroEntity.h"
#include <list>
#include "DAO.h"

class PerroDAO : public DAO
{
public:
	void guardarPerro(PerroEntity perro);

	PerroEntity getPerro(string telefono, string email);

	list<PerroEntity> getAllPerros();
};

#endif