#include <stdio.h>

int main( void )
{
	int entier;
	int err;

	printf( "Saisir un entier: " );

	err = scanf( "%d", &entier );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	{
		int tailleTableau = entier * entier;

		{
			int k;
			for ( k = 0; k < tailleTableau; k++ )
			{
				printf( "%d%d\n", ( k / entier ) + 1, ( k % entier ) + 1 );
			}
		}
	}

	return 0;
}
