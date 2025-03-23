#include <stdio.h>

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
		return 1;
	}

	Modif();

	printf( "La valeur de n est maintenant %d\n", n );

	return 0;
}

int Modif( void )
{
	return --n;
}
