#include "PerroDAO.h"
#include "sqlite3.h"
#include <stdexcept>

void PerroDAO::guardarPerro(PerroEntity perro) {
	sqlite3_stmt *stmt = nullptr;
	EmpleadoEntity *cuidador = perro.getCuidador();
	if (cuidador == nullptr) {
		throw invalid_argument("No se puede guardar un perro sin cuidador");
	}

	const char *sqlInsert =
		"INSERT INTO perros "
		"(nombre, edad, raza, diagnostico, estado, telefono, correo) "
		"VALUES (?, ?, ?, ?, ?, ?, ?)";

	DAO::createStatement(sqlInsert, &stmt);
	sqlite3_bind_text(stmt, 1, perro.getNombre().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_int(stmt, 2, perro.getEdad());
	sqlite3_bind_text(stmt, 3, perro.getRaza().c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 4, perro.getDiagnostico().c_str(), -1, SQLITE_TRANSIENT);
	const string estado = perro.getEstado();
	sqlite3_bind_text(stmt, 5, estado.c_str(), -1, SQLITE_TRANSIENT);
	const string telefono = cuidador->getTelefono();
	const string correo = cuidador->getCorreoElectronico();
	sqlite3_bind_text(stmt, 6, telefono.c_str(), -1, SQLITE_TRANSIENT);
	sqlite3_bind_text(stmt, 7, correo.c_str(), -1, SQLITE_TRANSIENT);

	DAO::executeStatement(stmt);
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