#include "EmpleadoDAO.h"
#include "sqlite3.h"

void EmpleadoDAO::guardarEmpleado(EmpleadoEntity empleado) {
	sqlite3_stmt *stmt = nullptr;
	int ret;

	// Preparar la sentencia SQL para insertar un empleado
	const char *sqlInsert = "INSERT INTO empleados (telefono, correo, sueldo, nombre, apellido, turno) VALUES (?,?,?,?,?,?)";

	try {
		DAO::createStatement(sqlInsert, &stmt);

		// Vincular los valores del empleado a la sentencia SQL
		sqlite3_bind_text(stmt, 1, empleado.getTelefono().c_str(), -1, SQLITE_TRANSIENT);
		cout << "Correo electrónico a insertar: " << empleado.getCorreoElectronico().c_str() << endl;
		sqlite3_bind_text(stmt, 2, empleado.getCorreoElectronico().c_str(), -1, SQLITE_TRANSIENT);
		sqlite3_bind_double(stmt, 3, empleado.getSueldo());
		sqlite3_bind_text(stmt, 4, empleado.getNombre().c_str(), -1, SQLITE_TRANSIENT);
		sqlite3_bind_text(stmt, 5, empleado.getApellido().c_str(), -1, SQLITE_TRANSIENT);
		sqlite3_bind_text(stmt, 6, empleado.getTurnoString().c_str(), -1, SQLITE_TRANSIENT);


		DAO::executeStatement(stmt);
	} catch(const std::runtime_error& re) {
		cerr << "ocurrio un error con la base de datos " << re.what();
	}
}
