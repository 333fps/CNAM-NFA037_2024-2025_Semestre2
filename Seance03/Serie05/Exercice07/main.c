#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float Tableau[5];
	int err;
	size_t i;
	float plusGrand = 0;

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Entrez le nombre %lu: ", (unsigned long)( i + 1 ) );
		err = scanf( "%f", &Tableau[i] );
		if ( err != 1 )
		{
			printf( "Erreur de lecture\n" );
			return EXIT_FAILURE;
		}

		if ( Tableau[i] > plusGrand )
		{
			plusGrand = Tableau[i];
		}
	}

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Tableau[%lu] = %f\n", (unsigned long)i, (double)Tableau[i] );
	}

	printf( "Le plus grand nombre est %f\n", (double)plusGrand );

	return EXIT_SUCCESS;
}
