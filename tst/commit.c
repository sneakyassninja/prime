#include "base.h"

#include "../lib/commit.h"

void test_commit (void** context)

	Prime_Db* db = (Prime_Db*) *context

	do
		try ( prime_db_open_rw (db) )
		assert_non_null (db->txn)

		Prime_Dir dir

		do
			try ( prime_dir_open (&dir) )

			bool success = prime_commit (db, &dir)
			assert_int_equal (errno, 0)
			assert_true (success)

		finally
			prime_dir_close (&dir)
			assert_int_equal (errno, 0)

	finally
