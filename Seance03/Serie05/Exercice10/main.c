#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int Tableau[] = { 1, 100, 200, 300, 400 };

	int i;

	for ( i = sizeof( Tableau ) / sizeof( int ); i > 0; --i )
	{
		printf( "Tableau[%d] = %d\n", i - 1, Tableau[i - 1] );
	}

	return EXIT_SUCCESS;
}
