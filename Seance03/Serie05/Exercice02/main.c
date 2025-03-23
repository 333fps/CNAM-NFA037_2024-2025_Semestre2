#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int Tableau[11];
	int i;

	for ( i = 0; i < 11; ++i )
	{
		Tableau[i] = (int)i * 5;
	}

	for ( i = 0; i < 11; ++i )
	{
		printf( "Tableau[%d] = %d\n", i, Tableau[i] );
	}

	return EXIT_SUCCESS;
}
