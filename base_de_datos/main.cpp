#include <iostream>
#include "sqlite3.h"

// Función callback que se ejecuta por cada fila devuelta por una consulta SELECT
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        std::cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << "\n";
    }
    std::cout << std::endl;
    return 0;
}

int main() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;

    // 1. Abrir o crear la base de datos
    rc = sqlite3_open("ejemplo.db", &db);
    if (rc) {
        std::cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return 0;
    } else {
        std::cout << "Base de datos abierta exitosamente.\n" << std::endl;
    }

    // 2. Crear una tabla, insertar un dato y consultarlo (todo en una misma cadena SQL por simplicidad)
    const char *sql = 
        "CREATE TABLE IF NOT EXISTS ALUMNOS("
        "ID INT PRIMARY KEY AUTOINCREMENT NOT NULL,"
        "NOMBRE         TEXT    NOT NULL,"
        "EDAD           INT     NOT NULL);"
        "INSERT OR IGNORE INTO ALUMNOS (NOMBRE, EDAD) VALUES ('Juan Perez', 20);"
        "SELECT * FROM ALUMNOS;";

    // 3. Ejecutar las sentencias SQL
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error SQL: " << zErrMsg << std::endl;
        sqlite3_free(zErrMsg);
    } else {
        std::cout << "Operación ejecutada con éxito." << std::endl;
    }

    // 4. Cerrar la base de datos
    sqlite3_close(db);
    return 0;
}
