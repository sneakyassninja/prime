#include "db.h"

static bool db_open (Prime_Db* this, unsigned int flags)

	do
		try_v ( mdb_env_create (&this->env) )

		try_v ( mdb_env_open (this->env, ".prime", MDB_NOSUBDIR | flags, 0644) )

		try_v ( mdb_txn_begin (this->env, NULL, flags, &this->txn) )

		try_v ( mdb_dbi_open (this->txn, NULL, 0, &this->dbi) )

	finally

	return errno == 0

bool prime_db_open (Prime_Db* this)

	return db_open (this, MDB_RDONLY)

bool prime_db_open_rw (Prime_Db* this)

	return db_open (this, 0)

void prime_db_close (Prime_Db* this)

	mdb_env_close (this->env)
