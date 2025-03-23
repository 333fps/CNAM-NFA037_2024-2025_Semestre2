#include <stdio.h>

void EstPair( int i );

int main( void )
{
	int i;
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &i );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	EstPair( i );

	return 0;
}

void EstPair( int i )
{
	if ( i % 2 == 0 )
	{
		printf( "L'entier est pair\n" );
	}
	else
	{
		printf( "L'entier est impair\n" );
	}
}
