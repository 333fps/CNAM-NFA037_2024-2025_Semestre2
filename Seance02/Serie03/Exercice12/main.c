#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	int nombreDeLivres;
	int err;

	printf( "Entrez le nombre de livres possédés: " );

	err = scanf( "%d", &nombreDeLivres );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return EXIT_FAILURE;
	}

	if ( nombreDeLivres < 0 )
	{
		printf( "Erreur: le nombre de livres ne peut pas être négatif\n" );
		return EXIT_FAILURE;
	}

	nombreDeLivres > 1 ? printf( "Vous possédez %d livres\n", nombreDeLivres ) : printf( "Vous possédez %d livre\n", nombreDeLivres );

	return EXIT_SUCCESS;
}
