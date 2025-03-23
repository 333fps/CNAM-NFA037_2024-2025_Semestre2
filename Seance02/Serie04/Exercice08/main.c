#include <stdio.h>

int main( void )
{
	int entier = 1000;

	while ( entier > 100 )
	{
		printf( "Entrez un entier inférieur ou égal à 100: " );
		{
			int err = scanf( "%d", &entier );
			if ( err != 1 )
			{
				printf( "Erreur de saisie\n" );
				continue;
			}
		}
		if ( entier <= 100 )
		{
			break;
		}

		printf( "Erreur: %d est supérieur à 100\n", entier );
	}

	printf( "Merci pour votre saisie\n" );

	return 0;
}
