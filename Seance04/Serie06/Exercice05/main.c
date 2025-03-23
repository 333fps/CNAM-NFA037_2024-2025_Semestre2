#include <stdio.h>

void Affiche( float T[], int n );

int main( void )
{
	int i;
	int err;
	float T[5];

	for ( i = 0; i < 5; ++i )
	{
		printf( "Entrez un réel: " );
		err = scanf( "%f", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return 1;
		}
	}

	Affiche( T, 5 );

	return 0;
}

void Affiche( float T[], int n )
{
	int i;
	for ( i = 0; i < n; ++i )
	{
		printf( "%f\n", (double)T[i] );
	}
}
