#define try(action) \
	if ( (action), errno ) { break; }

#define try_v(action) \
	try ( errno = (action) )

#define finally \
	while ( 0 );

#define ever \
	( ;; )
