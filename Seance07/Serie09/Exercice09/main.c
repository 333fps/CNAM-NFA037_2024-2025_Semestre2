#include <stdio.h>

enum Boolean
{
	FALSE = 0,
	TRUE
};

int main( void )
{
	enum Boolean b = FALSE;

	( b == TRUE ) ? printf( "TRUE\n" ) : printf( "FALSE\n" );

	return 0;
}
