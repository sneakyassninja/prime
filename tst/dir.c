#include "base.h"

#include "../lib/dir.h"

void test_dir ()

	Prime_Dir dir

	bool success = prime_dir_open (&dir)
	assert_int_equal (errno, 0)
	assert_true (success)

	prime_dir_close (&dir)
	assert_int_equal (errno, 0)
