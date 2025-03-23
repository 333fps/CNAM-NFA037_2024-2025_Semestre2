#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int hauteur;
	int err;

	printf( "Veuillez saisir un nombre entier positif: " );
	err = scanf( "%d", &hauteur );

	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	if ( hauteur <= 0 )
	{
		printf( "Le nombre doit etre positif!\n" );
		return EXIT_FAILURE;
	}

	{
		int i;
		for ( i = hauteur; i >= 1; --i )
		{
			int j;
			for ( j = i; j < hauteur; ++j )
			{
				printf( "%c", ' ' );
			}

			printf( "%c", '*' );

			if ( i > 1 )
			{
				for ( j = 2; j < 2 * i - 1; ++j )
				{
					printf( "%c", ' ' );
				}
				printf( "%c", '*' );
			}

			printf( "\n" );
		}
	}

	return EXIT_SUCCESS;
}
