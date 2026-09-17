#include "PerroDAO.h"
#include "sqlite3.h"

void PerroDAO::guardarPerro(PerroEntity perro) {
	sqlite3_stmt *stmt = nullptr;
	int ret;


	const char *sqlInsert = "INSERT INTO perroes (nombre, edad, raza, diagnostico, estado) VALUES (?,?,?,?,?)";

	

	try {
		DAO::createStatement(sqlInsert, &stmt);

		// Vincular los valores del empleado a la sentencia SQL
		sqlite3_bind_text(stmt, 1, perro.getNombre().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_int(stmt, 2, perro.getEdad());
		sqlite3_bind_text(stmt, 3, perro.getRaza().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 4, perro.getDiagnostico().c_str(), -1, SQLITE_STATIC);
		sqlite3_bind_text(stmt, 5, perro.getEstado().c_str(), -1, SQLITE_STATIC);


		DAO::executeStatement(stmt);
	} catch(const std::runtime_error& re) {
		cerr << "ocurrio un error con la base de datos " << re.what();
	}
}

/* id INTEGER PRIMARY KEY AUTOINCREMENT,
	nombre TEXT NOT NULL,
	edad INTEGER,
	raza TEXT,
	diagnostico TEXT,
	estado TEXT NOT NULL CHECK (estado IN ('ADOPTADO', 'NO ADOPTADO'),
	telefono TEXT,
	correo TEXT,
	FOREIGN KEY (telefono, coreeo) REFERENCES empleados (telefono, correo)
	ON UPDATE CASCADE
	ON DELETE CASCADE
    SAque telefono y correo*/