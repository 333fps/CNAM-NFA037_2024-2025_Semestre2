#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int entier;
	int err;

	printf( "Saisir un entier: " );
	err = scanf( "%d", &entier );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
	}

	{
		int i;
		for ( i = entier; i > 0; --i )
		{
			int j;
			for ( j = 1; j <= 3; ++j )
			{
				printf( "%d.%d\n", entier, j );
			}
			--entier;
		}
	}

	return EXIT_SUCCESS;
}
