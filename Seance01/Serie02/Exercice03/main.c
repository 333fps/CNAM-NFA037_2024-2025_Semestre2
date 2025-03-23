#include <stdio.h>

int main( void )
{
	char caractere;
	int err;

	printf( "Saisir un caractère... \n" );
	err = scanf( "%c", &caractere );

	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Le code ASCII du caractère %c est %d\n", caractere, caractere );

	return 0;
}
