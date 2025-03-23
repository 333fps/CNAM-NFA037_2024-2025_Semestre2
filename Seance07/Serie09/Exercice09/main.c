#include <stdio.h>
#include <stdlib.h>

enum Boolean
{
	FALSE = 0,
	TRUE
};

int main( void )
{
	enum Boolean b = FALSE;

	( b == TRUE ) ? printf( "TRUE\n" ) : printf( "FALSE\n" );

	return EXIT_SUCCESS;
}
