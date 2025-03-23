#include <stdio.h>

void Modif( float T[], int n );
void Affiche( float T[], int n );

int main( void )
{
	float T[5];

	Modif( T, 5 );
	Affiche( T, 5 );

	Modif( T, 5 );
	Affiche( T, 5 );

	return 0;
}

void Modif( float T[], int n )
{
	int i;
	int err;

	for ( i = 0; i < n; ++i )
	{
		printf( "Entrez un réel: " );
		err = scanf( "%f", &T[i] );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
			return;
		}
	}
}

void Affiche( float T[], int n )
{
	int i;

	for ( i = 0; i < n; ++i )
	{
		printf( "%f\n", (double)T[i] );
	}
}
