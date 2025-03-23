#include <stdio.h>

int main( void )
{
	char Tableau[] = { 'a', 'e', 'i', 'o', 'u', 'y' };
	int err;
	int index;

	printf( "Choisir un indice entre 0 et 5:\n" );

	err = scanf( "%d", &index );
	if ( err != 1 )
	{
		printf( "Erreur de lecture\n" );
		return 1;
	}

	if ( index < 0 || index > 5 )
	{
		printf( "Indice invalide\n" );
		return 1;
	}

	printf( "Tableau[%d] = %c\n", index, Tableau[index] );

	return 0;
}
