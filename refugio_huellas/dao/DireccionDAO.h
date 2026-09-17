#ifndef DIRECCION_H
#define DIRECCION_H

#include "DireccionEntity.h"
#include <list>
#include "DAO.h"

class DireccionDAO : public DAO
{
public:
	void guardarDireccion(DireccionEntity direccion);
 
	DireccionEntity getDireccion(string telefono, string email);

	list<DireccionEntity> getAllDirecciones();
};

#endif