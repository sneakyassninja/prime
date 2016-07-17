#include "base.h"

#include "../lib/db.h"

void test_db (void** context)

	Prime_Db* db = (Prime_Db*) *context

	bool success = prime_db_open (db)
	assert_int_equal (errno, ENOENT)
	assert_false (success)
	assert_null (db->txn)
	errno = 0
