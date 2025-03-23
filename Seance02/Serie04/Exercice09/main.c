#include <stdio.h>

int main( void )
{
	int entier;
	int err;

	do
	{
		printf( "Saisir un entier supérieur ou égal a 100 : " );

		err = scanf( "%d", &entier );
		if ( err != 1 )
		{
			printf( "Erreur de saisie\n" );
		}
	} while ( err != 1 || entier < 100 );

	printf( "Bravo!" );

	return 0;
}
