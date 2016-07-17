#include "base.h"

#include <fts.h>

typedef struct Prime_Dir Prime_Dir;
struct Prime_Dir;

struct Prime_Dir {
	FTS* fts;
};

bool prime_dir_open (Prime_Dir*);
void prime_dir_close (Prime_Dir*);
bool prime_dir_read (Prime_Dir* this, FTSENT** entry);
