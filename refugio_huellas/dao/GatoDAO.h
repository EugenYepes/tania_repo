#ifndef GATO_H
#define GATO_H

#include "GatoEntity.h"
#include <list>
#include "DAO.h"

class GatoDAO : public DAO
{
public:
	void guardarGato(GatoEntity gato);
 
	GatoEntity getGato(string telefono, string email);

	list<GatoEntity> getAllGatos();
};

#endif