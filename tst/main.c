#include "base.h"

#include <time.h>
#include <unistd.h>

void test_dir ()
void test_db ()
void test_commit ()
void test_list_empty ()

void setup_base ()

	errno = 0

	char temp[] = "/tmp/test-YYYYmmdd-HHMMSS-XXXXXX"

	time_t now = time (NULL)
	assert_int_equal (errno, 0)

	strftime (temp, sizeof(temp), "/tmp/test-%Y%m%d-%H%M%S-XXXXXX", localtime (&now))

	mkdtemp (temp)
	assert_int_equal (errno, 0)

	chdir(temp)
	assert_int_equal (errno, 0)

#include "../lib/db.h"

void setup_db (void** context)

	Prime_Db** db = (Prime_Db**) context

	setup_base ()

	*db = malloc (sizeof (Prime_Db))
	assert_int_equal (errno, 0)
	assert_non_null (*db)

	(*db)->txn = NULL

void teardown_db (void** context)

	Prime_Db** db = (Prime_Db**) context

	prime_db_close (*db)
	assert_int_equal (errno, 0)

	free (*db)

int main ()

	UnitTest tests[] =
		unit_test_setup (test_dir, setup_base),
		unit_test_setup_teardown (test_db, setup_db, teardown_db),
		unit_test_setup_teardown (test_commit, setup_db, teardown_db),
		unit_test_setup_teardown (test_list_empty, setup_db, teardown_db),

	return run_tests (tests)
