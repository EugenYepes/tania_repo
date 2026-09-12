#ifndef EMPLEADODAO_H
#define EMPLEADODAO_H

#include "EmpleadoEntity.h"
#include <list>
#include "DAO.h"

class EmpleadoDAO : public DAO
{
public:
	void guardarEmpleado(EmpleadoEntity empleado);

	EmpleadoEntity getEmpleado(string telefono, string email);

	list<EmpleadoEntity> getAllEmpleados();
};

#endif