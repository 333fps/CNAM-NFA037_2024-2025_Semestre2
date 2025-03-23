#include <stdio.h>

int main( void )
{
	int nombreDeLivres;
	int err;

	printf( "Entrez le nombre de livres possédés: " );

	err = scanf( "%d", &nombreDeLivres );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	if ( nombreDeLivres < 0 )
	{
		printf( "Erreur: le nombre de livres ne peut pas être négatif\n" );
		return 1;
	}

	nombreDeLivres > 1 ? printf( "Vous possédez %d livres\n", nombreDeLivres ) : printf( "Vous possédez %d livre\n", nombreDeLivres );

	return 0;
}
