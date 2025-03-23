#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float* tableau;
	unsigned long nombreCases;
	int err;
	unsigned long i;

	printf( "Entrez le nombre de cases du tableau: " );
	err = scanf( "%lu", &nombreCases );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	if ( nombreCases == 0 )
	{
		printf( "Le tableau doit avoir au moins une case\n" );
		return EXIT_FAILURE;
	}

	tableau = malloc( nombreCases * sizeof( float ) );
	if ( tableau == NULL )
	{
		printf( "Erreur d'allocation mémoire\n" );
		return EXIT_FAILURE;
	}

	for ( i = 0; i < nombreCases; ++i )
	{
		printf( "Entrez le nombre %lu: ", i + 1 );
		err = scanf( "%f", &tableau[i] );
		if ( err != 1 )
		{
			printf( "Erreur de lecture\n" );
			free( tableau );
			return EXIT_FAILURE;
		}
	}

	for ( i = 0; i < nombreCases; ++i )
	{
		printf( "Tableau[%lu] = %.2f\n", i, (double)tableau[i] );
	}

	free( tableau );

	return EXIT_SUCCESS;
}
