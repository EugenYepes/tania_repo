#include "EmpleadoEntity.h"
#include <list>

class EmpleadoDAO {

public:
	void createEmpleado(EmpleadoEntity empleado);

	EmpleadoEntity getEmpleado(string telefono, string email);

	list<EmpleadoEntity> getAllEmpleados();
};