#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float* tableau;
	unsigned int nombreCases;
	unsigned int nombreCases_new;
	unsigned int i;

	printf( "Entrez le nombre de cases du tableau: " );
	if ( scanf( "%u", &nombreCases ) != 1 )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	if ( nombreCases == 0 )
	{
		printf( "Le tableau doit avoir au moins une case\n" );
		return 1;
	}

	tableau = malloc( nombreCases * sizeof( float ) );
	if ( tableau == NULL )
	{
		printf( "Erreur d'allocation mémoire\n" );
		return 1;
	}

	for ( i = 0; i < nombreCases; ++i )
	{
		printf( "Entrez le nombre %u: ", i + 1 );
		if ( scanf( "%f", &tableau[i] ) != 1 )
		{
			printf( "Erreur de lecture\n" );
			free( tableau );
			return 1;
		}
	}

	for ( i = 0; i < nombreCases; ++i )
	{
		printf( "Tableau[%u] = %.2f\n", (unsigned int)i, (double)tableau[i] );
	}

	printf( "Entrez la nouvelle taille du tableau: " );

	if ( scanf( "%u", &nombreCases_new ) != 1 )
	{
		printf( "Erreur de lecture\n" );
		free( tableau );
		return 1;
	}
	{
		float* temp = realloc( tableau, nombreCases_new * sizeof( float ) );
		if ( temp == NULL )
		{
			printf( "Erreur d'allocation mémoire\n" );
			free( tableau );
			return 1;
		}
		tableau = temp;
	}
	if ( nombreCases_new > nombreCases )
	{
		printf( "Le tableau est plus grand\n" );
		for ( i = nombreCases; i < nombreCases_new; i++ )
		{
			printf( "Entrez le nombre %u: ", (unsigned int)( i + 1 ) );
			if ( scanf( "%f", &tableau[i] ) != 1 )
			{
				printf( "Erreur de lecture\n" );
				free( tableau );
				return 1;
			}
		}
	}
	else
	{
		printf( "Le tableau est plus petit\n" );
	}

	for ( i = 0; i < nombreCases_new; i++ )
	{
		printf( "Tableau[%u] = %.2f\n", (unsigned int)i, (double)tableau[i] );
	}

	free( tableau );

	return 0;
}
