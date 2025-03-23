#include <stdio.h>
#include <stdlib.h>

int main( void )
{
	float sommeEnEuro;
	int err;

	printf( "Saisir une somme en euros : " );

	err = scanf( "%f", &sommeEnEuro );
	if ( err == 1 )
	{
		printf( "Vous avez saisi %.2f euros\n", (double)sommeEnEuro );
	}
	else
	{
		printf( "Erreur de saisie\n" );
	}

	return EXIT_SUCCESS;
}
