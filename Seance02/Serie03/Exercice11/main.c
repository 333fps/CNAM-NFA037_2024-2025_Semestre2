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
		printf( "Le nombre de livres ne peut pas être négatif\n" );
		return EXIT_FAILURE;
	}

	if ( nombreDeLivres == 0 || nombreDeLivres == 1 )
	{
		printf( "Vous possedez %d livre\n ", nombreDeLivres );
	}
	else
	{
		printf( "Vous possedez %d livres\n ", nombreDeLivres );
	}

	return EXIT_SUCCESS;
}
