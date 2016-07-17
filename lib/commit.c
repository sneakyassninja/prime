#include "commit.h"

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

bool prime_commit (Prime_Db* db, Prime_Dir* dir)

	do
		FTSENT* entry

		for ever
			try ( prime_dir_read (dir, &entry) )

			if ( entry == NULL )
				break

			struct MDB_val key =
				.mv_size = entry->fts_pathlen + 1,
				.mv_data = entry->fts_path,

			struct MDB_val data =
				.mv_size = entry->fts_statp->st_size,

			try_v ( mdb_put (db->txn, db->dbi, &key, &data, MDB_RESERVE) )

			int file

			do
				try ( file = open (entry->fts_name, O_RDONLY) )

				try ( read (file, data.mv_data, data.mv_size) )

			finally
				close (file)

		try_v ( mdb_txn_commit (db->txn) )

	finally

	return errno == 0
