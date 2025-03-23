#include <stdio.h>

int main( void )
{
	float Tableau[6];
	int err;
	size_t i;
	float moyenne = 0;

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		printf( "Entrez la note %lu: ", (unsigned long)( i + 1 ) );
		err = scanf( "%f", &Tableau[i] );
		if ( err != 1 )
		{
			printf( "Erreur de lecture\n" );
			return 1;
		}
	}

	for ( i = 0; i < sizeof( Tableau ) / sizeof( float ); ++i )
	{
		moyenne += Tableau[i];
	}

	moyenne /= sizeof( Tableau ) / sizeof( float );

	printf( "La moyenne des notes est: %.2f\n", (double)moyenne );

	return 0;
}
