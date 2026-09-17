#include "CandidatoDAO.h"
#include "sqlite3.h"

void CandidatoDAO::guardarCandidato(CandidatoEntity candidato) {
	sqlite3_stmt *stmt = nullptr;
	int ret;

	// Preparar la sentencia SQL para insertar un empleado
	const char *sqlInsert = "INSERT INTO candidatos (telefono, correo, mascotas, nombre, apellido, direccion_id) VALUES (?,?,?,?,?,?)";

	
	/**	telefono TEXT NOT NULL,
	correo TEXT NOT NULL,
	mascotas TEXT,
	nombre TEXT NOT NULL,
	apellido TEXT NOT NULL,
	direccion_id INTEGER  NOT NULL, */
	try {
		DAO::createStatement(sqlInsert, &stmt);

		// Vincular los valores del empleado a la sentencia SQL
		sqlite3_bind_text(stmt, 1, candidato.getTelefono().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 2, candidato.getCorreoElectronico().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 3, candidato.getMascotas().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, candidato.getNombre().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 5, candidato.getApellido().c_str(), -1, SQLITE_STATIC);
		//sqlite3_bind_text(stmt, 6, candidato.getDireccon_id().c_str(), -1, SQLITE_STATIC); no supe como hacer la referencia a direccion


		DAO::executeStatement(stmt);
	} catch(const std::runtime_error& re) {
		cerr << "ocurrio un error con la base de datos " << re.what();
	}
}