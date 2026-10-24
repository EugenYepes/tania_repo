#include "EmpleadoDAO.h"
#include "sqlite3.h"
#include <stdexcept>

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

EmpleadoEntity EmpleadoDAO::getCuidadorConMenosMascotas() {
	sqlite3_stmt *stmt = nullptr;
	const char *sql =
		"SELECT e.telefono, e.correo, e.sueldo, e.nombre, e.apellido, e.turno "
		"FROM empleados e "
		"ORDER BY "
		"(SELECT COUNT(*) FROM perros p "
		"WHERE p.telefono = e.telefono AND p.correo = e.correo) + "
		"(SELECT COUNT(*) FROM gatos g "
		"WHERE g.telefono = e.telefono AND g.correo = e.correo), "
		"e.telefono, e.correo "
		"LIMIT 1";

	DAO::createStatement(sql, &stmt);
	const int ret = sqlite3_step(stmt);
	if (ret != SQLITE_ROW) {
		const bool noEmployees = ret == SQLITE_DONE;
		const string error = noEmployees
			? "No hay empleados disponibles para asignar como cuidador"
			: sqlite3_errmsg(DAO::getDb());
		sqlite3_finalize(stmt);
		throw runtime_error(error);
	}

	EmpleadoEntity empleado;
	empleado.setTelefono(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
	empleado.setCorreoElectronico(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
	empleado.setSueldo(sqlite3_column_double(stmt, 2));
	empleado.setNombre(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
	empleado.setApellido(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
	empleado.setTurno(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 5)));
	sqlite3_finalize(stmt);

	return empleado;
}
