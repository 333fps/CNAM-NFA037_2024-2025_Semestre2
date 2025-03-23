#include <stdio.h>
#include <stdlib.h>

int somme_chiffres( int nombre );
int est_harshad( int nombre );

int main( void )
{
	int nombre;
	int err;

	printf( "Entrez un nombre entier positif: " );
	err = scanf( "%d", &nombre );

	if ( err != 1 || nombre <= 0 )
	{
		printf( "Erreur: veuillez entrer un nombre entier positif\n" );
		return EXIT_FAILURE;
	}

	if ( est_harshad( nombre ) )
		printf( "%d est un nombre Harshad\n", nombre );
	else
		printf( "%d n'est pas un nombre Harshad\n", nombre );

	return EXIT_SUCCESS;
}

int somme_chiffres( int nombre )
{
	if ( nombre < 10 )
		return nombre;

	return ( nombre % 10 ) + somme_chiffres( nombre / 10 );
}

int est_harshad( int nombre )
{
	int somme = somme_chiffres( nombre );
	return ( nombre % somme == 0 );
}
