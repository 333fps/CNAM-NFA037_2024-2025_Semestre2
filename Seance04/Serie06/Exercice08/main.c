#include <stdio.h>
#include <stdlib.h>

void Affiche( int T[], int n );
int RangPlusGrand( int T[], int n );

int main( void )
{
	int i;
	int err;
	int T[5];

	for ( i = 0; i < 5; ++i )
	{
		printf( "Entrez un entier: " );
		err = scanf( "%d", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return EXIT_FAILURE;
		}
	}

	Affiche( T, 5 );
	printf( "Le rang du plus grand élément est %d\n", RangPlusGrand( T, 5 ) );
	return EXIT_SUCCESS;
}

void Affiche( int T[], int n )
{
	int i;

	for ( i = 0; i < n; ++i )
	{
		printf( "%d ", T[i] );
	}
	printf( "\n" );
}

int RangPlusGrand( int T[], int n )
{
	int i;
	int rang = 0;

	for ( i = 1; i < n; ++i )
	{
		if ( T[i] > T[rang] )
		{
			rang = i;
		}
	}

	return rang;
}
