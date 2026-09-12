#include "DAO.h"

void DAO::createStatement(const char *query, sqlite3_stmt** stmt) {
	int ret = sqlite3_prepare_v2(DAO::getDb(), query, -1, stmt, nullptr);
	if (ret != SQLITE_OK)
	{
		cerr << "Error al preparar la sentencia SQL: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
	}
}