#include <stdio.h>

int main( void )
{
	int nb;
	int err;
	int i;

	printf( "Entrer un nombre entier: " );
	err = scanf( "%d", &nb );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "*\n" );

	for ( i = 1; i < nb; i++ )
	{
		int spaces;
		for ( spaces = 0; spaces < i; spaces++ )
		{
			printf( " " );
		}
		printf( "*\n" );
	}

	return 0;
}
