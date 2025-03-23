#include <stdio.h>

int main( void )
{
	float Tableau[6];
	int err;
	size_t i;

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Entrez le nombre %lu: ", (unsigned long)( i + 1 ) );
		err = scanf( "%f", &Tableau[i] );
		if ( err != 1 )
		{
			printf( "Erreur de lecture\n" );
			return 1;
		}
	}

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Tableau[%lu] = %f\n", (unsigned long)i, (double)Tableau[i] );
	}

	return 0;
}
