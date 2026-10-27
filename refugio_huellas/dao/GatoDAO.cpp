#include "GatoDAO.h"
#include "sqlite3.h"

void GatoDAO::guardarGato(GatoEntity gato) {
	sqlite3_stmt *stmt = nullptr;
	int ret;

	// Preparar la sentencia SQL para insertar un empleado
	const char *sqlInsert = "INSERT INTO gatos (nombre, edad, test, indoor, diagnostico, estado) VALUES (?,?,?,?,?,?)";

	

	try {
		DAO::createStatement(sqlInsert, &stmt);

		// Vincular los valores del empleado a la sentencia SQL
		sqlite3_bind_text(stmt, 1, gato.getNombre().c_str(), -1, SQLITE_TRANSIENT);
		sqlite3_bind_int(stmt, 2, gato.getEdad());
		sqlite3_bind_text(stmt, 3, gato.getTest().c_str(), -1, SQLITE_TRANSIENT);
		sqlite3_bind_int(stmt, 4, gato.getIndoor());
		sqlite3_bind_text(stmt, 5, gato.getDiagnostico().c_str(), -1, SQLITE_TRANSIENT); //FK ?
        sqlite3_bind_text(stmt, 6, gato.getEstado().c_str(), -1, SQLITE_TRANSIENT);

		DAO::executeStatement(stmt);
	} catch(const std::runtime_error& re) {
		cerr << "ocurrio un error con la base de datos " << re.what();
	}
	
}

/*id INTEGER PRIMARY KEY AUTOINCREMENT,
	nombre TEXT NOT NULL,
	edad INTEGER,
	test TEXT, 
	indoor INTEGER CHECK (indoor IN (0, 1)),
	diagnostico TEXT,
	estado TEXT NOT NULL CHECK (estado IN ('ADOPTADO', 'NO ADOPTADO')),
	telefono TEXT,
	correo TEXT,*/