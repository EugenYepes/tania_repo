#include <iostream>
#include "sqlite3.h"

using namespace std;

int main()
{
	sqlite3 *db;
	sqlite3_stmt *stmt = nullptr;
	int rc;

	// 1. Abrir o crear la base de datos
	rc = sqlite3_open("ejemplo.db", &db);
	if (rc)
	{
		cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
		return 0;
	}
	else
	{
		cout << "Base de datos abierta exitosamente."<< endl;
	}

	// 2. Crear una tabla, insertar un dato y consultarlo (todo en una misma cadena SQL por simplicidad)
	const char *sqlCreate =
		"CREATE TABLE IF NOT EXISTS ALUMNOS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
		"NOMBRE         TEXT    NOT NULL,"
		"EDAD           INT     NOT NULL);";
	rc = sqlite3_prepare_v2(db, sqlCreate, -1, &stmt, nullptr);
	if (rc != SQLITE_OK)
	{
		cerr << "Error al preparar CREATE: " << sqlite3_errmsg(db) << endl;
		return 1;
	}
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		cerr << "Error al ejecutar CREATE: " << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmt);
	stmt = nullptr;

	// 3. Insertar un alumno
	const char *sqlInsert = "INSERT OR IGNORE INTO ALUMNOS (NOMBRE, EDAD) VALUES ('Juan Perez', 20);";
	rc = sqlite3_prepare_v2(db, sqlInsert, -1, &stmt, nullptr);
	if (rc != SQLITE_OK)
	{
		cerr << "Error al preparar INSERT: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return 1;
	}
	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE)
	{
		cerr << "Error al ejecutar INSERT: " << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmt);
	stmt = nullptr;

	// 4. Consultar los alumnos
	const char *sqlSelect = "SELECT * FROM ALUMNOS;";
	rc = sqlite3_prepare_v2(db, sqlSelect, -1, &stmt, nullptr);
	if (rc != SQLITE_OK)
	{
		cerr << "Error al preparar SELECT: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return 1;
	}
	while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
	{
		int nCols = sqlite3_column_count(stmt);
		for (int i = 0; i < nCols; i++)
		{
			const char *colName = sqlite3_column_name(stmt, i);
			const unsigned char *value = sqlite3_column_text(stmt, i);
			cout << colName << " = " << (value ? reinterpret_cast<const char *>(value) : "NULL") << "\n";
		}
		cout << endl;
	}
	if (rc != SQLITE_DONE)
	{
		cerr << "Error al ejecutar SELECT: " << sqlite3_errmsg(db) << endl;
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		return 1;
	}
	sqlite3_finalize(stmt);
	cout << "Operaciones ejecutadas con exito." << endl;
	// Liberar la sentencia preparada antes de preparar la siguiente
	stmt = nullptr;

	// 4. Cerrar la base de datos
	sqlite3_close(db);
	return 0;
}