#include <stdio.h>

int main( void )
{
	float nombre;
	int err;

	printf( "Entrez un nombre : " );

	err = scanf( "%f", &nombre );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	nombre < 0 ? nombre = -nombre : nombre;

	printf( "La valeur absolue de ce nombre est : %f\n", (double)nombre );

	return 0;
}
