#include <stdio.h>

int main( void )
{
	char Symb;
	int err;

	printf( "Saisissez un symbole\n" );
	err = scanf( "%c", &Symb );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Le symbole saisi est : %c ; son code ASCII est : %d\n", Symb, Symb );
	return 0;
}
