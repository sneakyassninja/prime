#pragma once

#include "base.h"

#include <lmdb.h>

typedef struct Prime_Db Prime_Db;
struct Prime_Db;

struct Prime_Db {
	MDB_env* env;
	MDB_txn* txn;
	MDB_dbi dbi;
};

bool prime_db_open (Prime_Db*);
bool prime_db_open_rw (Prime_Db*);
void prime_db_close (Prime_Db*);
