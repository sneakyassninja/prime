#include "list.h"

bool prime_list (Prime_Db* db)

	MDB_cursor* cursor

	do
		try_v ( mdb_cursor_open (db->txn, db->dbi, &cursor) )

		struct MDB_val key

		for ever
			try_v ( mdb_cursor_get (cursor, &key, NULL, MDB_NEXT) )

		if ( errno == MDB_NOTFOUND )
			errno = 0

	finally
		mdb_cursor_close (cursor)

	return errno == 0
