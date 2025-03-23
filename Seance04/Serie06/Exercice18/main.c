#include <stdio.h>
#include <stdlib.h>

static int n;
int Modif( void );

int main( void )
{
	int err;

	printf( "Entrez un entier: " );
	err = scanf( "%d", &n );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return EXIT_FAILURE;
	}

	Modif();

	printf( "La valeur de n est maintenant %d\n", n );

	return EXIT_SUCCESS;
}

int Modif( void )
{
	return --n;
}
