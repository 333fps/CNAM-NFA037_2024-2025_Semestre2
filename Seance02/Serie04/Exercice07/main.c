#include <stdio.h>

int main( void )
{
	int entier;
	int err;
	printf( "Entrez un entier pour en afficher la table : " );

	err = scanf( "%d", &entier );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	if ( entier <= 0 )
	{
		printf( "L' entier doit être positif\n" );
		return 1;
	}

	{
		int i;
		for ( i = 1; i <= 10; ++i )
		{
			printf( "%d*%d=%d\n", entier, i, i * entier );
		}
	}

	return 0;
}
