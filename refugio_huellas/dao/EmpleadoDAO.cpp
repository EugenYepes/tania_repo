#include "EmpleadoDAO.h"
#include "sqlite3.h"

void EmpleadoDAO::guardarEmpleado(EmpleadoEntity empleado) {
	sqlite3_stmt *stmt = nullptr;
	int ret;

	// Preparar la sentencia SQL para insertar un empleado
	const char *sqlInsert = "INSERT INTO empleados (telefono, correo, sueldo, nombre, apellido, turno) VALUES (?,?,?,?,?,?)";
	DAO::createStatement(sqlInsert, &stmt);

	// Vincular los valores del empleado a la sentencia SQL
	sqlite3_bind_text(stmt, 1, empleado.getTelefono().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 2, empleado.getCorreoElectronico().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_double(stmt, 3, empleado.getSueldo());
	sqlite3_bind_text(stmt, 4, empleado.getNombre().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 5, empleado.getApellido().c_str(), -1, SQLITE_STATIC);
	sqlite3_bind_text(stmt, 6, empleado.getTurnoString().c_str(), -1, SQLITE_STATIC);


	ret = sqlite3_step(stmt); // TODO mover al DAO generalizar
	if (ret != SQLITE_DONE)
	{
		cerr << "Error al ejecutar la sentencia SQL: " << sqlite3_errmsg(DAO::getDb()) << endl;
	}
	sqlite3_finalize(stmt); // TODO mover al DAO generalizar

	// TODO manejo de excepciones
	/*
	
	*/
}

