#include "base.h"

#include "../lib/commit.h"
#include "../lib/list.h"

void test_list_empty (void** context)

	Prime_Db* db = (Prime_Db*) *context

	do
		try ( prime_db_open_rw (db) )
		assert_non_null (db->txn)

		Prime_Dir dir

		do
			try ( prime_dir_open (&dir) )

			try ( prime_commit (db, &dir) )

		finally
			prime_dir_close (&dir)
			assert_int_equal (errno, 0)

	finally
		prime_db_close (db)
		assert_int_equal (errno, 0)

	do
		try ( prime_db_open (db) )
		assert_non_null (db->txn)

		bool success = prime_list (db)
		assert_int_equal (errno, 0)
		assert_true (success)

	finally
