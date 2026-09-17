#include "DireccionDAO.h"
#include "sqlite3.h"

void DireccionDAO::guardarDireccion(DireccionEntity direccion) {
	sqlite3_stmt *stmt = nullptr;
	int ret;

	// Preparar la sentencia SQL para insertar un empleado
	const char *sqlInsert = "INSERT INTO direcciones (id, calle, estado, pais, numero) VALUES (?,?,?,?,?)";

	

	try {
		DAO::createStatement(sqlInsert, &stmt);

		// Vincular los valores del empleado a la sentencia SQL
		sqlite3_bind_int(stmt, 1, direccion.getId());
		sqlite3_bind_text(stmt, 2, direccion.getCalle().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, direccion.getEstado().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, direccion.getPais().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 5, direccion.getNumero().c_str(), -1, SQLITE_STATIC);

		DAO::executeStatement(stmt);
	} catch(const std::runtime_error& re) {
		cerr << "ocurrio un error con la base de datos " << re.what();
	}
}