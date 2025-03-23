#include <stdio.h>

int main( void )
{
	int entier1;
	int entier2;
	int err;

	printf( "Entrez un premier entier : " );
	err = scanf( "%d", &entier1 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	printf( "Entrez un second entier : " );
	err = scanf( "%d", &entier2 );
	if ( err != 1 )
	{
		printf( "Erreur de saisie\n" );
		return 1;
	}

	if ( entier1 == entier2 )
	{
		printf( "Les deux entiers sont égaux\n" );
	}
	else
	{
		if ( entier1 > entier2 )
		{
			printf( "Le premier entier est plus grand que le second\n" );
		}
		else
		{
			printf( "Le second entier est plus grand que le premier\n" );
		}
	}

	return 0;
}
