#include "DAO.h"

void DAO::createStatement(const char *query, sqlite3_stmt** stmt) {
	int ret = sqlite3_prepare_v2(DAO::getDb(), query, -1, stmt, nullptr);
	if (ret != SQLITE_OK)
	{
		cerr << "Error al preparar la sentencia SQL: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
		throw std::runtime_error(sqlite3_errmsg(DAO::getDb()));
	}
}

void DAO::executeStatement(sqlite3_stmt* stmt) {
	int ret = sqlite3_step(stmt);
	if (ret != SQLITE_DONE)
	{
		cerr << "Error al ejecutar la sentencia SQL: " << sqlite3_errmsg(DAO::getDb()) << endl;
		sqlite3_close(DAO::getDb());
		throw std::runtime_error(sqlite3_errmsg(DAO::getDb()));
	}
	sqlite3_finalize(stmt);
}
