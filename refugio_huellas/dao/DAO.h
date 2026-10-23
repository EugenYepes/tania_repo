#ifndef DAO_H
#define DAO_H

#include <iostream>

#include "sqlite3.h"

using namespace std;

class DAO {
private:
	sqlite3 *db;

public:
	DAO() {
		
		int ret = sqlite3_open("refugio.db", &db);
		if (ret != SQLITE_OK)
		{
			cerr << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << endl;
			return;
		}
	}

	
	void createStatement(const char *query, sqlite3_stmt** stmt);

	void executeStatement(sqlite3_stmt* stmt);

	sqlite3* getDb() {
		return db;
	}

	// destructor
	~DAO() {
		sqlite3_close(db);
	}
};

#endif