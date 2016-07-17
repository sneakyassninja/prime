#include "dir.h"

bool prime_dir_open (Prime_Dir* this)

	this->fts = fts_open ((char* []){ ".", NULL, }, 0, NULL)
	return errno == 0

void prime_dir_close (Prime_Dir* this)

	fts_close (this->fts)

bool prime_dir_read (Prime_Dir* this, FTSENT** entry)

	do
		try ( *entry = fts_read (this->fts) )
	while ( (*entry != NULL) && ( ((*entry)->fts_info != FTS_F) || ((*entry)->fts_name[0] == '.') ))

	return errno == 0
